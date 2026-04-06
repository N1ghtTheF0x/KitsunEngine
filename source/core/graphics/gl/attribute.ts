import { OpenGL } from "@utilities/canvas"
import OpenGLBase from "./base"
import OpenGLProgram from "./program"

class OpenGLAttribute extends OpenGLBase
{
    public readonly program: OpenGLProgram
    public readonly location: number
    public constructor(gl: OpenGL,program: OpenGLProgram,location: number)
    {
        super(gl)
        this.program = program
        this.location = location
    }
    public enable(): void
    {
        this.gl.enableVertexAttribArray(this.location)
    }
    public setup(
        size: number,
        type: OpenGL.DataType,
        normalized: boolean,
        stride: number,
        offset: number
    ): void
    {
        this.gl.vertexAttribPointer(this.location,size,type,normalized,stride,offset)
    }
}

export default OpenGLAttribute