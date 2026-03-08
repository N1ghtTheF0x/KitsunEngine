import EngineCore from ".."
import { IPostUpdate, IUpdate } from "@utilities/types"
import EngineCoreInput from "./input"
import EngineCoreIOFileSystem from "./filesystem"

class EngineCoreIO implements IUpdate, IPostUpdate
{
    public readonly core: EngineCore
    public readonly input: EngineCoreInput
    public readonly filesytem: EngineCoreIOFileSystem
    public constructor(core: EngineCore)
    {
        this.core = core
        this.input = new EngineCoreInput(this)
        this.filesytem = new EngineCoreIOFileSystem(this)
    }
    public update(): void
    {
        this.input.update()
    }
    public postUpdate(): void
    {
        this.input.postUpdate()
    }
}

export default EngineCoreIO