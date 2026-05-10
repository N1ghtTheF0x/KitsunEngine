import { OpenGL } from "@utilities/canvas"
import OpenGLShader from "./shader"
import OpenGLProgram from "./program"
import OpenGLBuffer from "./buffer"
import OpenGLObject from "./object"
import OpenGLTexture from "./texture"
import { AnyColor, AnyColorLike, RGBA } from "@ntf/math"

class OpenGLContext
{
    private _objects: Array<OpenGLObject<unknown>> = []
    public readonly gl: OpenGL
    public constructor(gl: OpenGL)
    {
        this.gl = gl
    }
    public clear(): void
    {
        this.gl.clear(this.gl.COLOR_BUFFER_BIT)
    }
    public delete(): void
    {
        for(const object of this._objects)
            object.delete()
    }
    private _add_object<O extends OpenGLObject<unknown>>(obj: O): O
    {
        this._objects.push(obj)
        return obj
    }
    public setClearColor(color: AnyColorLike): this
    {
        let rgba = AnyColor.resolve(color,false)
        rgba = rgba instanceof RGBA ? rgba : RGBA.resolve(rgba)
        rgba.alpha
        this.gl.clearColor(rgba.red,rgba.green,rgba.blue,rgba.alpha)
        return this
    }
    public compileShader(type: OpenGLShader.Type,source: string): OpenGLShader
    {
        return this._add_object(OpenGLShader.compile(this.gl,type,source))
    }
    public compileVertexShader(source: string): OpenGLShader
    {
        return this._add_object(OpenGLShader.compileVertex(this.gl,source))
    }
    public compileFragmentShader(source: string): OpenGLShader
    {
        return this._add_object(OpenGLShader.compileFragment(this.gl,source))
    }
    public linkProgram(...shaders: Array<OpenGLShader>): OpenGLProgram
    {
        return this._add_object(OpenGLProgram.link(this.gl,...shaders))
    }
    public createBuffer(target: OpenGLBuffer.Target): OpenGLBuffer
    {
        return this._add_object(OpenGLBuffer.create(this.gl,target))
    }
    public createTexture(target: OpenGLTexture.Target): OpenGLTexture
    {
        return this._add_object(OpenGLTexture.create(this.gl,target))
    }
}

export default OpenGLContext