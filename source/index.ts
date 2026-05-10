import { createPreferredTimeHandler, setMaxFramesPerSecond, TimeHandler } from "./utilities/time"
import EngineCore from "./core"
import AssetDatabase from "./assets"
import SceneManager from "./scene"
import "./utilities/math"
import { defineGlobal } from "@utilities/global"

class KitsunEngine
{
    private _time: TimeHandler
    public get time(): TimeHandler
    {
        return this._time
    }
    public readonly core: EngineCore
    public readonly assets: AssetDatabase
    public readonly scene: SceneManager
    public constructor()
    {
        this.core = new EngineCore(this)
        this.assets = new AssetDatabase(this)
        this.scene = new SceneManager(this)
        this._time = this._create_time_handler()
        defineGlobal("engine",() => this)
    }
    private _create_time_handler(): TimeHandler
    {
        const time = createPreferredTimeHandler(this.core.config.getTimeHandlerMethod(),this._update.bind(this))
        setMaxFramesPerSecond(time,this.core.config.getTimeHandlerMaxFPS())
        return time
    }
    public reloadTimeHandler(): this
    {
        this._time.stop()
        this._time = this._create_time_handler()
        this._time.start()
        return this
    }
    private _update(): void
    {
        // core engine update (input)
        this.core.update()
        // logic update
        this.scene.update()
        this.core.postUpdate()
        // draw update
        this.scene.draw()
        document.title = `FPS ${Math.round(this._time.framesPerSecond)}`
    }
    public init(): void
    {
        this.core.init()
        this._time.start()
    }
}

export default KitsunEngine