import { textDecoder, textEncoder } from "@utilities/string"
import EngineCoreIO from ".."
import FileSystemProvider, { IReadonlyFileSystemProvider, IWriteOnlyFileSystemProvider } from "./provider"
import fetchReadProvider from "./read/fetch"

class EngineCoreIOFileSystem implements FileSystemProvider
{
    private _readProvider: Array<IReadonlyFileSystemProvider> = []
    private _writeProvider: Array<IWriteOnlyFileSystemProvider> = []
    public readonly io: EngineCoreIO
    public constructor(io: EngineCoreIO)
    {
        this.io = io
        this.pushReadProvider(fetchReadProvider)
    }
    public pushProvider(...providers: Array<FileSystemProvider>): this
    {
        for(const provider of providers)
            this
            .pushReadProvider(provider)
            .pushWriteProvider(provider)
        return this
    }
    public unshiftProvider(...providers: Array<FileSystemProvider>): this
    {
        for(const provider of providers)
            this
            .unshiftReadProvider(provider)
            .unshiftWriteProvider(provider)
        return this
    }
    public pushReadProvider(...providers: Array<IReadonlyFileSystemProvider>): this
    {
        this._readProvider.push(...providers)
        return this
    }
    public unshiftReadProvider(...providers: Array<IReadonlyFileSystemProvider>): this
    {
        this._readProvider.unshift(...providers)
        return this
    }
    public pushWriteProvider(...providers: Array<IWriteOnlyFileSystemProvider>): this
    {
        this._writeProvider.push(...providers)
        return this
    }
    public unshiftWriteProvider(...providers: Array<IWriteOnlyFileSystemProvider>): this
    {
        this._writeProvider.unshift(...providers)
        return this
    }
    public async readFile(filepath: string): Promise<ArrayBuffer>
    {
        const errors: Array<Error> = []

        for(const provider of this._readProvider)
        {
            try
            {
                const result: ArrayBuffer | Error = await provider.readFile(filepath).catch(e => e)
                if(Error.isError(result))
                    throw result
                return result
            }
            catch(e)
            {
                errors.push(Error.isError(e) ? e : new Error(String(e)))
            }
        }

        throw new AggregateError(errors,`failed to read '${filepath}'`)
    }
    public async readTextFile(filepath: string): Promise<string>
    {
        return this.readFile(filepath).then(buffer => textDecoder.decode(buffer))
    }
    public async readJsonFile(filepath: string): Promise<unknown>
    {
        return JSON.parse(await this.readTextFile(filepath))
    }
    public async writeFile(filepath: string,data: ArrayBuffer): Promise<void>
    {
        const errors: Array<Error> = []

        for(const provider of this._writeProvider)
        {
            try
            {
                const result: Error | undefined = await provider.writeFile(filepath,data).catch(e => e)
                if(Error.isError(result))
                    throw result
                return
            }
            catch(e)
            {
                errors.push(Error.isError(e) ? e : new Error(String(e)))
            }
        }

        throw new AggregateError(errors,`failed to write '${filepath}'`)
    }
    public async writeTextFile(filepath: string,data: string): Promise<void>
    {
        return this.writeFile(filepath,textEncoder.encode(data).buffer)
    }
    public async writeJsonFile(filepath: string,data: unknown): Promise<void>
    {
        return this.writeTextFile(filepath,JSON.stringify(data))
    }
}

export default EngineCoreIOFileSystem