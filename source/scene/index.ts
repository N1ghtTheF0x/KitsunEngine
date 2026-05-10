import { IDeletable, IDraw, IUpdate } from "@utilities/types"
import KitsunEngine from ".."
import Scene from "./scene"
import { createLogger } from "@ntf/logger"

const logger = createLogger("SceneManager")

class SceneManager implements IUpdate, IDraw, IDeletable
{
    public readonly engine: KitsunEngine
    private _scenes: Array<Scene> = []
    private _sceneMap: Record<string,bigint> = {}
    private _current?: Scene
    public constructor(engine: KitsunEngine)
    {
        this.engine = engine
    }
    public push(...scenes: Array<Scene>): this
    {
        this._scenes.push(...scenes.filter(scene => !this._scenes.includes(scene)))
        return this
    }
    public map(id: bigint,name: string): this
    {
        this._sceneMap[name] = id
        return this
    }
    public set(name: string,scene: Scene): this
    {
        this._sceneMap[name] = scene.id
        return this.push(scene)
    }
    public get(key: bigint | string): Scene | undefined
    {
        const id = typeof key === "string" ? this._sceneMap[key] : key
        if(id === undefined)
        {
            logger.warn("no scene with name",key,"exists")
            return undefined
        }
        const scene = this._scenes.find(scene => scene.id === id)
        if(scene === undefined)
        {
            logger.warn("no scene with id",key,"exists")
            return undefined
        }
        return scene
    }
    public delete(): void
    {
        this._current?.delete()
        this._current = undefined
        this._scenes = []
        this._sceneMap = {}
    }
    public switch(key: bigint | string): boolean
    {
        const scene = this.get(key)
        if(scene === undefined)
            return false
        scene.delete()
        this._current = scene
        return true
    }
    public update(): void
    {
        this._current?.update()
    }
    public draw(): void
    {
        this._current?.draw()
    }
}

export default SceneManager