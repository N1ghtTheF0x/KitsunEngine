import KitsunEngine from ".."
import { IInit, IPostUpdate, IUpdate } from "@utilities/types"
import EngineCoreIO from "./io"
import EngineCoreWindow from "./window"
import EngineCoreConfig from "./config"

class EngineCore implements IUpdate, IInit, IPostUpdate
{
    public readonly engine: KitsunEngine
    public readonly config: EngineCoreConfig
    public readonly window: EngineCoreWindow
    public readonly io: EngineCoreIO
    public constructor(engine: KitsunEngine)
    {
        this.engine = engine
        this.config = new EngineCoreConfig(this)
        this.window = new EngineCoreWindow(this)
        this.io = new EngineCoreIO(this)
    }
    public init(): void
    {
        this.window.init()
    }
    public update(): void
    {
        this.window.update()
        this.io.update()
    }
    public postUpdate(): void
    {
        this.io.postUpdate()
    }
}

export default EngineCore