export type CanvasContextMap = {
    "2d": [CanvasRenderingContext2D | OffscreenCanvasRenderingContext2D,CanvasRenderingContext2DSettings]
    "webgl": [WebGLRenderingContext,WebGLContextAttributes]
    "webgl2": [WebGL2RenderingContext,WebGLContextAttributes]
    "bitmaprenderer": [ImageBitmapRenderingContext,ImageBitmapRenderingContextSettings]
    "webgpu": [GPUCanvasContext,GPUCanvasConfiguration]
}

export type CanvasLike = HTMLCanvasElement | OffscreenCanvas

export type OpenGL = WebGLRenderingContext | WebGL2RenderingContext

export function getRequiredCanvasContext<T extends keyof CanvasContextMap>(canvas: CanvasLike,type: T,options?: CanvasContextMap[T][1]): CanvasContextMap[T][0]
{
    const context = canvas.getContext(type,options)
    if(context === null)
        throw new TypeError(`canvas context '${type}' is not available on this machine`)
    return context
}

export function createCanvasContext<T extends keyof CanvasContextMap>(type: T,options?: CanvasContextMap[T][1]): CanvasContextMap[T][0] | null
{
    try
    {
        const canvas = new OffscreenCanvas(1,1)
        return canvas.getContext(type,options)
    }
    catch(e)
    {
        return null
    }
}

export function createRequiredCanvasContext<T extends keyof CanvasContextMap>(type: T,options?: CanvasContextMap[T][1]): CanvasContextMap[T][0]
{
    const context = createCanvasContext(type,options)
    if(context === null)
        throw new TypeError(`context '${type}' is not available on this machine`)
    return context
}

export const CANVAS_CLASS_NAME = "kitsunengine-canvas"

export const SUPPORTED_CANVAS_CONTEXT: Record<keyof CanvasContextMap,boolean> = {
    "2d": createCanvasContext("2d") !== null,
    "webgl": createCanvasContext("webgl") !== null,
    "webgl2": createCanvasContext("bitmaprenderer") !== null,
    "bitmaprenderer": createCanvasContext("bitmaprenderer") !== null,
    "webgpu": createCanvasContext("webgpu") !== null
}