import { OpenGL } from "@utilities/canvas"
import OpenGLObject from "./object"

class OpenGLVertexArrayObject extends OpenGLObject<OpenGL.VertexArrayObject>
{
    private _1ext?: OES_vertex_array_object
    public static supported(gl: OpenGL): boolean
    {
        return gl instanceof WebGL2RenderingContext || (gl instanceof WebGLRenderingContext && gl.getExtension("OES_vertex_array_object") !== null)
    }
    public static create(gl: OpenGL): OpenGLVertexArrayObject
    {
        if(gl instanceof WebGLRenderingContext)
            return new this(gl,gl.getExtension("OES_vertex_array_object")?.createVertexArrayOES() ?? null)
        return new this(gl,gl.createVertexArray())
    }
    public constructor(gl: OpenGL,vao: OpenGL.VertexArrayObject | null)
    {
        super(gl,vao)
        if(gl instanceof WebGLRenderingContext)
        {
            const vao = this.gl.getExtension("OES_vertex_array_object")
            if(vao === null)
                throw new TypeError("OES_vertex_array_object is not supported")
        }
    }
    public override delete(): void
    {
        if(this.gl instanceof WebGL2RenderingContext)
            this.gl.deleteVertexArray(this.object)
        if(this._1ext !== undefined)
            this._1ext.deleteVertexArrayOES(this.object)
    }
    public bind(): void
    {
        if(this.gl instanceof WebGL2RenderingContext)
            this.gl.bindVertexArray(this.object)
        if(this._1ext !== undefined)
            this._1ext.bindVertexArrayOES(this.object)
    }
}

export default OpenGLVertexArrayObject