import { OpenGL } from "@utilities/canvas"
import OpenGLBase from "./base"
import OpenGLProgram from "./program"
import { required } from "@utilities/types"
import { Mat3, Mat3Like, Mat4, Mat4Like } from "@ntf/math"

class OpenGLUniform extends OpenGLBase
{
    public readonly program: OpenGLProgram
    public readonly location: WebGLUniformLocation | null
    public get value(): unknown
    {
        return this.gl.getUniform(required(this.program.object),required(this.location))
    }
    public constructor(gl: OpenGL,program: OpenGLProgram,location: WebGLUniformLocation | null)
    {
        super(gl)
        this.program = program
        this.location = location
    }
    public setSignedInteger(x: number): void
    {
        this.gl.uniform1i(this.location,x)
    }
    public setSignedInteger2(x: number,y: number): void
    {
        this.gl.uniform2i(this.location,x,y)
    }
    public setSignedInteger3(x: number,y: number,z: number): void
    {
        this.gl.uniform3i(this.location,x,y,z)
    }
    public setSignedInteger4(x: number,y: number,z: number,w: number): void
    {
        this.gl.uniform4i(this.location,x,y,z,w)
    }
    public setUnsignedInteger(x: number): void
    {
        this.gl2.uniform1ui(this.location,x)
    }
    public setUnsignedInteger2(x: number,y: number): void
    {
        this.gl2.uniform2ui(this.location,x,y)
    }
    public setUnsignedInteger3(x: number,y: number,z: number): void
    {
        this.gl2.uniform3ui(this.location,x,y,z)
    }
    public setUnsignedInteger4(x: number,y: number,z: number,w: number): void
    {
        this.gl2.uniform4ui(this.location,x,y,z,w)
    }
    public setFloat(x: number): void
    {
        this.gl.uniform1f(this.location,x)
    }
    public setFloat2(x: number,y: number): void
    {
        this.gl.uniform2f(this.location,x,y)
    }
    public setFloat3(x: number,y: number,z: number): void
    {
        this.gl.uniform3f(this.location,x,y,z)
    }
    public setFloat4(x: number,y: number,z: number,w: number): void
    {
        this.gl.uniform4f(this.location,x,y,z,w)
    }
    public setMatrix3(matrix: Mat3Like,transpose: boolean): void
    {
        this.gl.uniformMatrix3fv(this.location,transpose,new Float32Array(Mat3.resolve(matrix).toArray()))
    }
    public setMatrix4(matrix: Mat4Like,transpose: boolean): void
    {
        this.gl.uniformMatrix4fv(this.location,transpose,new Float32Array(Mat4.resolve(matrix).toArray()))
    }
}

export default OpenGLUniform