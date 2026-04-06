import { OpenGL } from "@utilities/canvas"
import { IDeletable } from "@utilities/types"
import OpenGLBase from "./base"

abstract class OpenGLObject<T> extends OpenGLBase implements IDeletable
{
    public readonly object: T | null = null
    public constructor(gl: OpenGL,object: T | null)
    {
        super(gl)
        this.object = object
    }
    public abstract delete(): void
}

export default OpenGLObject