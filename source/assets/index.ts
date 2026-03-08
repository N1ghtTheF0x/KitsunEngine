import { createLogger } from "@ntf/logger"
import Asset, { AssetConstructor } from "./asset"
import AssetBinary from "./asset/binary"
import { Publisher } from "@utilities/observer"
import KitsunEngine from ".."
import ImageAsset from "./asset/image"
import TextAsset from "./asset/text"

const logger = createLogger("Assets")

class AssetDatabase
{
    private _resolvers: Array<AssetDatabase.Resolver> = []
    private _data: Record<string,Asset> = {}
    public readonly engine: KitsunEngine
    public readonly onLoad: Publisher<[items: number]> = new Publisher
    public readonly onLoadProgress: Publisher<[items: number,loaded: number]> = new Publisher
    public readonly onLoaded: Publisher = new Publisher
    public readonly onUnload: Publisher = new Publisher
    public constructor(engine: KitsunEngine)
    {
        this.engine = engine
        this
            .addResolver([".png",".jpg",".jpeg",".webp",".gif"],ImageAsset)
            .addResolver([".txt",".md"],TextAsset)
    }
    public addResolver<T>(extensions: Array<string>,Asset: AssetConstructor<T>): this
    {
        this._resolvers.push([extensions,Asset])
        return this
    }
    public addAsset(id: string,path: string): this
    {
        if(id in this._data)
            logger.warn("asset",id,"already exists! Old asset will be replaced!")
        const Asset: AssetConstructor = this._resolvers.find(r => r[0].some(ext => path.endsWith(ext)))?.[1] ?? AssetBinary
        this._data[id] = new Asset(path)
        return this
    }
    public async load(): Promise<number>
    {
        const assets = Object.values(this._data).filter(asset => !asset.isLoaded())
        if(assets.length === 0)
        {
            logger.warn("no assets to load")
            return 0
        }
        this.onLoad.notify(assets.length)
        const loaded: Array<Promise<void>> = []
        for(let i = 0;i < assets.length;i++)
        {
            const asset = assets[i]!
            const l = Number(i)
            logger.info("loading",asset.path)
            loaded.push(Promise.resolve(asset.load()).then(() => this.onLoadProgress.notify(assets.length,l + 1)))
        }
        await Promise.all(loaded)
        this.onLoaded.notify()
        return assets.length
    }
    public async unload(): Promise<void>
    {
        const assets = Object.values(this._data).filter(asset => asset.isLoaded())
        if(assets.length === 0)
        {
            logger.warn("no assets to unload")
            return
        }
        const unloaded: Array<Promise<void>> = []
        for(let i = 0;i < assets.length;i++)
        {
            const asset = assets[i]!
            unloaded.push(Promise.resolve(asset.unload()))
        }
        await Promise.all(unloaded)
        this.onUnload.notify()
    }
    public async reload(): Promise<void>
    {
        logger.info("reloading assets...")
        await this.unload()
        await this.load()
    }
}

namespace AssetDatabase
{
    export type Resolver<T = unknown> = [Array<string>,AssetConstructor<T>]
}

export default AssetDatabase