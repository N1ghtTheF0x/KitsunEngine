import { Size, Vec2, Vec2Arguments, Vec2Like } from "@ntf/math"
import EngineCore from "../.."
import { CANVAS_CLASS_NAME, getRequiredCanvasContext } from "@utilities/canvas"
import { IInit } from "@utilities/types"

const MAIN_CANVAS_ID = "kitsunengine-canvas-main"

function __setup_canvas__(canvas: HTMLCanvasElement): void
{
    canvas.tabIndex = 1
    canvas.classList.add(CANVAS_CLASS_NAME)
    canvas.id = MAIN_CANVAS_ID
    canvas.autofocus = true
}

class EngineCoreWindow implements IInit
{
    private _scale: number = 1
    private _offset: Vec2 = Vec2.zero
    public get scale(): number
    {
        return this._scale
    }
    public get offset(): Vec2
    {
        return this._offset
    }
    public readonly core: EngineCore
    public readonly domElement: HTMLCanvasElement
    public readonly context: ImageBitmapRenderingContext
    public target: HTMLElement = document.body
    public constructor(core: EngineCore)
    {
        this.core = core
        this.domElement = document.createElement("canvas")
        this.context = getRequiredCanvasContext(this.domElement,"bitmaprenderer",{alpha: false})
        __setup_canvas__(this.domElement)
        window.addEventListener("resize",this._on_resize.bind(this))
    }
    public init(): void
    {
        this.domElement.remove()
        this.target.append(this.domElement)
        this._on_resize()
    }
    private _on_resize(): void
    {
        const canvas = this.domElement
        const parentBoundingBox = canvas.parentElement?.getBoundingClientRect()

        const parentWidth = canvas.parentElement === document.body ? innerWidth : parentBoundingBox?.width ?? innerWidth
        const parentHeight = canvas.parentElement === document.body ? innerHeight : parentBoundingBox?.height ?? innerHeight

        this._scale = Math.min(
            parentWidth / canvas.width,
            parentHeight / canvas.height
        )
        const scaledSize = new Size(
            this._scale * canvas.width,
            this._scale * canvas.height
        )
        this._offset = new Vec2(
            (parentWidth - scaledSize.width) / 2,
            (parentHeight - scaledSize.height) / 2
        )

        canvas.style.width = `${scaledSize.width}px`
        canvas.style.height = `${scaledSize.height}px`
        canvas.style.left = `${this.offset.x}px`
        canvas.style.top = `${this.offset.y}px`
    }
    public draw(bitmap: ImageBitmap): this
    {
        this.context.transferFromImageBitmap(bitmap)
        return this
    }
    public drawWithCanvas(canvas: OffscreenCanvas): this
    {
        return this.draw(canvas.transferToImageBitmap())
    }
    public clear(): this
    {
        this.context.transferFromImageBitmap(null)
        return this
    }
    public toNDC2(vec: Vec2Like): Vec2
    public toNDC2(x: number,y: number): Vec2
    public toNDC2(...args: Vec2Arguments): Vec2
    {
        return Vec2.resolveArgs(args)
            .divide(this.domElement.width,this.domElement.height)
            .multiply(2)
            .subtract(1)
    }
    public fromNDC2(vec: Vec2Like): Vec2
    public fromNDC2(x: number,y: number): Vec2
    public fromNDC2(...args: Vec2Arguments): Vec2
    {
        return Vec2.resolveArgs(args)
            .add(1)
            .divide(2)
            .naiveMultiply(this.domElement.width,this.domElement.height)
    }
}

export default EngineCoreWindow