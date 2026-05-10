import { OpenGL } from "@utilities/canvas"
import OpenGLShader from "./shader"
import OpenGLObject from "./object"
import { required, requiredReference } from "@utilities/types"
import OpenGLUniform from "./uniform"
import OpenGLAttribute from "./attribute"

class OpenGLProgram extends OpenGLObject<WebGLProgram>
{
    public static link(gl: OpenGL,...shaders: Array<OpenGLShader>): OpenGLProgram
    {
        const program = new this(gl,gl.createProgram())
        for(const shader of shaders)
            program.attachShader(shader)
        program.link()
        program.validate()
        if(!program.getLinkStatus())
        {
            program.delete()
            throw new Error(`failed to link program: ${program.getInfoLog()}`)
        }

        return program
    }
    public delete(): void
    {
        this.gl.deleteProgram(this.object)
    }
    public attachShader(shader: OpenGLShader): this
    {
        this.gl.attachShader(required(this.object),required(shader.object))
        return this
    }
    public link(): this
    {
        this.gl.linkProgram(required(this.object))
        return this
    }
    public validate(): this
    {
        this.gl.validateProgram(required(this.object))
        return this
    }
    public getAttachedShaders(): Array<OpenGLShader>
    {
        return required(this.gl.getAttachedShaders(required(this.object)))
            .map(shader => new OpenGLShader(this.gl,shader))
    }
    public use(): void
    {
        this.gl.useProgram(this.object)
    }
    public getAttributeLocation(name: string): OpenGLAttribute
    {
        return new OpenGLAttribute(this.gl,this,this.gl.getAttribLocation(required(this.object),name))
    }
    public getUniformLocation(name: string): OpenGLUniform
    {
        return new OpenGLUniform(this.gl,this,this.gl.getUniformLocation(required(this.object),name))
    }
    public override getParameter(pname: GLenum): unknown
    {
        return this.gl.getProgramParameter(required(this.object),pname)
    }
    public getDeleteStatus(): boolean
    {
        return Boolean(this.getParameter(this.gl.DELETE_STATUS))
    }
    public getLinkStatus(): boolean
    {
        return Boolean(this.getParameter(this.gl.LINK_STATUS))
    }
    public getValidateStatus(): boolean
    {
        return Boolean(this.getParameter(this.gl.VALIDATE_STATUS))
    }
    public getAttachedShadersCount(): number
    {
        return Number(this.getParameter(this.gl.ATTACHED_SHADERS))
    }
    public getActiveAttributes(): number
    {
        return Number(this.getParameter(this.gl.ACTIVE_ATTRIBUTES))
    }
    public getActiveUniforms(): number
    {
        return Number(this.getParameter(this.gl.ACTIVE_UNIFORMS))
    }
    public getTransformFeedbackBufferMode(): OpenGLProgram.TransformFeedBackBufferMode
    {
        return requiredReference(this.getParameter(this.gl2.TRANSFORM_FEEDBACK_BUFFER_MODE),this.gl2.SEPARATE_ATTRIBS,this.gl2.INTERLEAVED_ATTRIBS)
    }
    public getTransformFeedbackVaryings(): number
    {
        return Number(this.getParameter(this.gl2.TRANSFORM_FEEDBACK_VARYINGS))
    }
    public getActiveUniformBlocks(): number
    {
        return Number(this.getParameter(this.gl2.ACTIVE_UNIFORM_BLOCKS))
    }
    public getInfoLog(): string
    {
        return this.gl.getProgramInfoLog(required(this.object)) ?? ""
    }
}

namespace OpenGLProgram
{
    export type TransformFeedBackBufferMode = WebGL2RenderingContext["SEPARATE_ATTRIBS"] | WebGL2RenderingContext["INTERLEAVED_ATTRIBS"]
}

export default OpenGLProgram