import IInputMethod from "../method"

const mouse: IInputMethod = {
    name: "Mouse",
    init(input)
    {
        input.domElement.addEventListener("mousedown",(ev) =>
        {
            ev.preventDefault()
            input.setValue(`Mouse${ev.button}`,true)
        })
        input.domElement.addEventListener("mouseup",(ev) =>
        {
            ev.preventDefault()
            input.setValue(`Mouse${ev.button}`,false)
        })
        input.domElement.addEventListener("mousemove",(ev) =>
        {
            ev.preventDefault()
            input.setValueVec2("Mouse",[ev.offsetX,ev.offsetY])
            input.setValueVec2("MouseDelta",[ev.movementX,ev.movementY])
        })

    }
}

export default mouse