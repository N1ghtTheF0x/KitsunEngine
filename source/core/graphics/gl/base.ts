import { createLogger } from "@ntf/logger"
import { RGBA } from "@ntf/math"
import { isWebGL1, isWebGL2, OpenGL } from "@utilities/canvas"
import { requiredType, requirePrototype } from "@utilities/types"

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
    public getActiveTexture(): GLenum
    {
        return requiredType(this.getParameter(this.gl.ACTIVE_TEXTURE),"number")
    }
    public getAliasedLineWidthRange(): Float32Array
    {
        return requirePrototype(this.getParameter(this.gl.ALIASED_LINE_WIDTH_RANGE),Float32Array)
    }
    public getAliasedPointSizeRange(): Float32Array
    {
        return requirePrototype(this.getParameter(this.gl.ALIASED_POINT_SIZE_RANGE),Float32Array)
    }
    public getAlphaBits(): GLint
    {
        return requiredType(this.getParameter(this.gl.ALPHA_BITS),"number")
    }
    public getArrayBufferBinding(): WebGLBuffer
    {
        return requirePrototype(this.getParameter(this.gl.ARRAY_BUFFER_BINDING),WebGLBuffer)
    }
    public getBlend(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.BLEND),"boolean")
    }
    public getBlendColor(): RGBA
    {
        const [red,green,blue,alpha] = requirePrototype(this.getParameter(this.gl.BLEND_COLOR),Float32Array)
        return new RGBA()
    }
}

export default OpenGLBase