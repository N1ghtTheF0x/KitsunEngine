import { IReadonlyFileSystemProvider } from "@core/io/filesystem/provider"

abstract class Asset<T = unknown>
{
    protected _value?: T
    public get value(): T
    {
        if(this._value === undefined)
            throw new Error(`asset '${this.path}' is not loaded`)
        return this._value
    }
    public readonly path: string
    public abstract readonly type: string
    public static isAsset<T>(asset: Asset,Asset: AssetConstructor<T>): asset is Asset<T>
    {
        return asset.type === Asset.TYPE
    }
    public constructor(path: string)
    {
        this.path = path
    }
    public isLoaded(): boolean
    {
        return this._value !== undefined
    }
    public abstract load(provider: IReadonlyFileSystemProvider): Promise<void>
    public unload(): void | Promise<void>
    {
        this._value = undefined
    }
    public [Symbol.dispose](): void
    {
        this.unload()
    }
    public async [Symbol.asyncDispose](): Promise<void>
    {
        await this.unload()
    }
}

export interface AssetConstructor<T = unknown>
{
    new (path: string): Asset<T>
    readonly TYPE: string
}

export default Asset