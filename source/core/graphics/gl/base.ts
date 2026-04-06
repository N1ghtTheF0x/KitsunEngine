import { createLogger } from "@ntf/logger"
import { OpenGL } from "@utilities/canvas"

class OpenGLBase
{
    public static readonly logger = createLogger("OpenGL")
    public readonly gl: OpenGL
    public get gl1(): WebGLRenderingContext
    {
        if(this.gl instanceof WebGLRenderingContext)
            return this.gl
        throw new TypeError(`${this.gl} is not a webgl context`)
    }
    public get gl2(): WebGL2RenderingContext
    {
        if(this.gl instanceof WebGL2RenderingContext)
            return this.gl
        throw new TypeError(`${this.gl} is not a webgl2 context`)
    }
    public constructor(webgl: OpenGL)
    {
        this.gl = webgl
    }
}

export default OpenGLBase