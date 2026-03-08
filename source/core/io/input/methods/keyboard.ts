import IInputMethod from "../method"

const PREFIX = "Keyboard"

const __format_code__ = (code: string) => code.startsWith("Key") ? code.replace("Key",PREFIX) : PREFIX + code

const keyboard: IInputMethod = {
    name: "Keyboard",
    init(input)
    {
        input.domElement.addEventListener("keydown",(ev) =>
        {
            ev.preventDefault()
            input.setValue(__format_code__(ev.code),true)
        })
        input.domElement.addEventListener("keyup",(ev) =>
        {
            ev.preventDefault()
            input.setValue(__format_code__(ev.code),false)
        })
    },
}

export default keyboard