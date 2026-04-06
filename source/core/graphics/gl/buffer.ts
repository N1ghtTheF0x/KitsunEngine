import { OpenGL } from "@utilities/canvas"
import OpenGLObject from "./object"
import { requiredReference } from "@utilities/types"

class OpenGLBuffer extends OpenGLObject<WebGLBuffer>
{
    public readonly target: OpenGLBuffer.Target
    public static create(gl: OpenGL,target: OpenGLBuffer.Target): OpenGLBuffer
    {
        return new this(gl,gl.createBuffer(),target)
    }
    public constructor(gl: OpenGL,buffer: WebGLBuffer | null,target: OpenGLBuffer.Target)
    {
        super(gl,buffer)
        this.target = target
        this.gl2.createVertexArray()
    }
    public override delete(): void
    {
        this.gl.deleteBuffer(this.object)
    }
    public bind(): void
    {
        this.gl.bindBuffer(this.target,this.object)
    }
    public write(data: ArrayBufferView,usage: OpenGLBuffer.Usage): void
    {
        this.gl.bufferData(this.target,data,usage)
    }
    public getParameter(pname: GLenum): unknown
    {
        return this.gl.getBufferParameter(this.target,pname)
    }
    public getSize(): number
    {
        return Number(this.getParameter(this.gl.BUFFER_SIZE))
    }
    public getUsage(): OpenGLBuffer.Usage
    {
        return requiredReference(this.getParameter(this.gl.BUFFER_USAGE),35044, 35048, 35040, 35045, 35049, 35041, 35046, 35050, 35042)
    }
}

namespace OpenGLBuffer
{
    export type Target = OpenGL["ARRAY_BUFFER"] | OpenGL["ELEMENT_ARRAY_BUFFER"] | WebGL2RenderingContext["COPY_READ_BUFFER"] | WebGL2RenderingContext["COPY_WRITE_BUFFER"] | WebGL2RenderingContext["TRANSFORM_FEEDBACK_BUFFER"] | WebGL2RenderingContext["UNIFORM_BUFFER"] | WebGL2RenderingContext["PIXEL_PACK_BUFFER"] | WebGL2RenderingContext["PIXEL_UNPACK_BUFFER"]
    export type Usage = OpenGL["STATIC_DRAW"] | OpenGL["DYNAMIC_DRAW"] | OpenGL["STREAM_DRAW"] | WebGL2RenderingContext["STATIC_READ"] | WebGL2RenderingContext["DYNAMIC_READ"] | WebGL2RenderingContext["STREAM_READ"] | WebGL2RenderingContext["STATIC_COPY"] | WebGL2RenderingContext["DYNAMIC_COPY"] | WebGL2RenderingContext["STREAM_COPY"]
}

export default OpenGLBuffer