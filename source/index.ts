import { createPreferredTimeHandler, TimeHandler } from "./utilities/time"
import EngineCore from "./core"
import AssetDatabase from "./assets"
import "./utilities/math"

class KitsunEngine
{
    public readonly core: EngineCore
    public readonly assets: AssetDatabase
    public readonly time: TimeHandler
    public constructor()
    {
        this.core = new EngineCore(this)
        this.assets = new AssetDatabase(this)
        this.time = createPreferredTimeHandler(this._update.bind(this))
        if(!PROD)
            Object.defineProperty(window,"engine",{value: this})
    }
    private _update(): void
    {
        // core engine update (input)
        this.core.update()
        // logic update

        this.core.postUpdate()
        // draw update
    }
    public init(): void
    {
        this.core.init()
        this.time.start()
    }
}

export default KitsunEngine