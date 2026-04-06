import { OpenGL } from "@utilities/canvas"
import OpenGLObject from "./object"

class OpenGLBuffer extends OpenGLObject<WebGLBuffer>
{
    public static create(gl: OpenGL): OpenGLBuffer
    {
        return new this(gl,gl.createBuffer())
    }
    public override delete(): void
    {
        this.gl.deleteBuffer(this.object)
    }
    public bind(target: OpenGLBuffer.Target): void
    {
        this.gl.bindBuffer(target,this.object)
    }
    public bindBase(target: OpenGLBuffer.BaseTarget,index: number): void
    {
        this.gl2.bindBufferBase(target,index,this.object)
    }
    public bindBaseRange(target: OpenGLBuffer.BaseTarget,index: number,offset: number,size: number): void
    {
        this.gl2.bindBufferRange(target,index,this.object,offset,size)
    }
}

namespace OpenGLBuffer
{
    export type Target = OpenGL["ARRAY_BUFFER"] | OpenGL["ELEMENT_ARRAY_BUFFER"] | WebGL2RenderingContext["COPY_READ_BUFFER"] | WebGL2RenderingContext["COPY_WRITE_BUFFER"] | WebGL2RenderingContext["TRANSFORM_FEEDBACK_BUFFER"] | WebGL2RenderingContext["UNIFORM_BUFFER"] | WebGL2RenderingContext["PIXEL_PACK_BUFFER"] | WebGL2RenderingContext["PIXEL_UNPACK_BUFFER"]
    export type BaseTarget = WebGL2RenderingContext["TRANSFORM_FEEDBACK_BUFFER"] | WebGL2RenderingContext["UNIFORM_BUFFER"]
}

export default OpenGLBuffer