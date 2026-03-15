import { createPreferredTimeHandler, createTimeHandler, TimeHandler, TimeHandlerType } from "./utilities/time"
import EngineCore from "./core"
import AssetDatabase from "./assets"
import "./utilities/math"

class KitsunEngine
{
    private _time: TimeHandler
    public get time(): TimeHandler
    {
        return this._time
    }
    public readonly core: EngineCore
    public readonly assets: AssetDatabase
    public constructor()
    {
        this.core = new EngineCore(this)
        this.assets = new AssetDatabase(this)
        this._time = createPreferredTimeHandler(this._update.bind(this))
        if(!PROD)
            Object.defineProperty(window,"engine",{value: this})
    }
    public switchTimeHandler(type: TimeHandlerType): this
    {
        this._time.stop()
        this._time = createTimeHandler(type,this._update.bind(this))
        this._time.start()
        return this
    }
    private _update(): void
    {
        // core engine update (input)
        this.core.update()
        // logic update

        this.core.postUpdate()
        // draw update
        document.title = `FPS ${Math.round(this._time.framesPerSecond)}`
    }
    public init(): void
    {
        this.core.init()
        this._time.start()
    }
}

export default KitsunEngine