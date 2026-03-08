export type CanvasContextMap = {
    "2d": [CanvasRenderingContext2D | OffscreenCanvasRenderingContext2D,CanvasRenderingContext2DSettings]
    "webgl": [WebGLRenderingContext,WebGLContextAttributes]
    "webgl2": [WebGL2RenderingContext,WebGLContextAttributes]
    "bitmaprenderer": [ImageBitmapRenderingContext,ImageBitmapRenderingContextSettings]
}

export type CanvasLike = HTMLCanvasElement | OffscreenCanvas

export function getRequiredCanvasContext<T extends keyof CanvasContextMap>(canvas: CanvasLike,type: T,options?: CanvasContextMap[T][1]): CanvasContextMap[T][0]
{
    const context = canvas.getContext(type,options)
    if(context === null)
        throw new TypeError(`canvas context '${type}' is not available on this machine`)
    return context
}

export const CANVAS_CLASS_NAME = "kitsunengine-canvas"