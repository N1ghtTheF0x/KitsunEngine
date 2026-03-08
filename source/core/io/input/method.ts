import EngineCoreInput from "."

interface IInputMethod
{
    readonly name: string
    init?(input: EngineCoreInput): void
    update?(input: EngineCoreInput): void
}

export default IInputMethod