import { CanvasContextMap, getRequiredCanvasContext } from "@utilities/canvas"
import { IDeletable } from "@utilities/types"

abstract class Renderer<T extends keyof CanvasContextMap> implements IDeletable
{
    public readonly type: T
    public readonly canvas: OffscreenCanvas
    public readonly context: CanvasContextMap[T][0]
    public constructor(width: number,height: number,type: T)
    {
        this.type = type
        this.canvas = new OffscreenCanvas(width,height)
        this.context = getRequiredCanvasContext(this.canvas,type)
    }
    public abstract clear(): void
    public abstract delete(): void
}

export default Renderer