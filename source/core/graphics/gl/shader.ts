import { OpenGL } from "@utilities/canvas"
import OpenGLObject from "./object"
import { required, requiredReference } from "@utilities/types"

class OpenGLShader extends OpenGLObject<WebGLShader>
{
    public static compile(
        gl: OpenGL,
        type: OpenGLShader.Type,
        source: string
    ): OpenGLShader
    {
        const shader = new this(gl,required(gl.createShader(type)))
        shader.source(source)
        shader.compile()
        if(!shader.getCompileStatus())
        {
            shader.delete()
            throw new Error(`failed to compile shader: ${shader.getInfoLog()}`)
        }
        return shader
    }
    public static compileVertex(gl: OpenGL,source: string): OpenGLShader
    {
        return this.compile(gl,gl.VERTEX_SHADER,source)
    }
    public static compileFragment(gl: OpenGL,source: string): OpenGLShader
    {
        return this.compile(gl,gl.FRAGMENT_SHADER,source)
    }
    public override delete(): void
    {
        this.gl.deleteShader(this.object)
    }
    public override getParameter(pname: GLenum): unknown
    {
        return this.gl.getShaderParameter(required(this.object),pname)
    }
    public source(source: string): this
    {
        this.gl.shaderSource(required(this.object),source)
        return this
    }
    public compile(): this
    {
        this.gl.compileShader(required(this.object))
        return this
    }
    public getDeleteStatus(): boolean
    {
        return Boolean(this.getParameter(this.gl.DELETE_STATUS))
    }
    public getCompileStatus(): boolean
    {
        return Boolean(this.getParameter(this.gl.COMPILE_STATUS))
    }
    public getShaderType(): OpenGLShader.Type
    {
        return requiredReference(Number(this.getParameter(this.gl.SHADER_TYPE)),this.gl.FRAGMENT_SHADER,this.gl.VERTEX_SHADER)
    }
    public getInfoLog(): string
    {
        return this.gl.getShaderInfoLog(required(this.object)) ?? ""
    }
    public getSource(): string
    {
        return this.gl.getShaderSource(required(this.object)) ?? ""
    }
}

namespace OpenGLShader
{
    export type Type = OpenGL["VERTEX_SHADER"] | OpenGL["FRAGMENT_SHADER"]
}

export default OpenGLShader