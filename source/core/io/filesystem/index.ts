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
        this.addReadProvider(fetchReadProvider)
    }
    public addProvider(...providers: Array<FileSystemProvider>): this
    {
        for(const provider of providers)
            this
            .addReadProvider(provider)
            .addWriteProvider(provider)
        return this
    }
    public addReadProvider(...providers: Array<IReadonlyFileSystemProvider>): this
    {
        this._readProvider.push(...providers)
        return this
    }
    public addWriteProvider(...providers: Array<IWriteOnlyFileSystemProvider>): this
    {
        this._writeProvider.push(...providers)
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
}

export default EngineCoreIOFileSystem