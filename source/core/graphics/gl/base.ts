import { createLogger } from "@ntf/logger"
import { isWebGL1, isWebGL2, OpenGL } from "@utilities/canvas"
import { required, requiredType, requirePrototype, Typeof } from "@utilities/types"
import OpenGLExtensions from "./extension"

class OpenGLBase<GL extends OpenGL = OpenGL>
{
    public static readonly logger = createLogger("OpenGL")
    public readonly gl: GL
    public get gl1(): WebGLRenderingContext
    {
        if(this.isWebGL1())
            return this.gl
        throw new TypeError("not a webgl context")
    }
    public get gl2(): WebGL2RenderingContext
    {
        if(this.isWebGL2())
            return this.gl
        throw new TypeError("not a webgl2 context")
    }
    public constructor(webgl: GL)
    {
        this.gl = webgl
    }
    public isWebGL1(): this is OpenGLBase<WebGLRenderingContext>
    {
        return isWebGL1(this.gl)
    }
    public isWebGL2(): this is OpenGLBase<WebGL2RenderingContext>
    {
        return isWebGL2(this.gl)
    }
    public getParameter(pname: GLenum): unknown
    {
        return this.gl.getParameter(pname)
    }
    public getExtension<N extends keyof OpenGLExtensions>(name: N): OpenGLExtensions[N]
    {
        return required(this.gl.getExtension(name))
    }
    public getObjectParameter<T>(pname: GLenum,Class: new () => T,isNull?: true): T | undefined
    public getObjectParameter<T>(pname: GLenum,Class: new () => T,isNull?: false): T
    public getObjectParameter<T>(pname: GLenum,Class: new () => T,isNull: boolean = true): T | undefined
    {
        const object = this.gl.getParameter(pname)
        if(object === null && isNull)
            return undefined
        return requirePrototype(object,Class)
    }
    public getTypedParameter<T extends keyof Typeof>(pname: GLenum,type: T): Typeof[T]
    {
        return requiredType(this.getParameter(pname),type)
    }
}

export default OpenGLBase