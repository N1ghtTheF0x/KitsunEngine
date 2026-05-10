import { createLogger } from "@ntf/logger"
import IInputMethod from "./method"
import EngineCoreIO from ".."
import { IPostUpdate, IUpdate } from "@utilities/types"
import keyboard from "./methods/keyboard"
import mouse from "./methods/mouse"
import { Vec2, Vec2Like, Vec3, Vec3Like } from "@ntf/math"
import EngineCoreWindow from "../../window"

const logger = createLogger("Input")

class EngineCoreInput implements IUpdate, IPostUpdate
{
    private _downValues: Record<string,number> = {}
    private _pressedValues: Record<string,number> = {}
    private _methods: Array<IInputMethod> = []
    public readonly io: EngineCoreIO
    public get window(): EngineCoreWindow
    {
        return this.io.core.window
    }
    public get domElement(): HTMLCanvasElement
    {
        return this.window.domElement
    }
    public constructor(io: EngineCoreIO)
    {
        this.io = io
        this.addMethod(keyboard,mouse)
    }
    public addMethod(...methods: Array<IInputMethod>): this
    {
        for(const method of methods)
        {
            if(this._methods.find(m => m.name === method.name) !== undefined)
            {
                logger.warn("method",method.name,"already exists")
                continue
            }
            this._methods.push(method)
            method.init?.(this)
            logger.info("added method",method.name)
        }
        return this
    }
    public setValue(key: string,value: number | boolean): this
    {
        const v = typeof value == "boolean" ? value ? 1 : 0 : value
        if(!this.isValueDown(key))
            this._pressedValues[key] = v
        this._downValues[key] = v
        return this
    }
    public setValueVec2(key: string,value: Vec2Like): this
    {
        const vec = Vec2.resolve(value)
        return this
            .setValue(`${key}X`,vec.x)
            .setValue(`${key}Y`,vec.y)
    }
    public setValueVec3(key: string,value: Vec3Like): this
    {
        const vec = Vec3.resolve(value)
        return this
            .setValue(`${key}X`,vec.x)
            .setValue(`${key}Y`,vec.y)
            .setValue(`${key}Z`,vec.z)
    }
    public getPressedValue(key: string): number
    {
        return this._pressedValues[key] ?? 0
    }
    public getDownValue(key: string): number
    {
        return this._downValues[key] ?? 0
    }
    public getDownValueVec2(key: string): Vec2
    {
        return new Vec2(
            this.getDownValue(`${key}X`),
            this.getDownValue(`${key}Y`)
        )
    }
    public getDownValueVec3(key: string): Vec3
    {
        return new Vec3(
            this.getDownValue(`${key}X`),
            this.getDownValue(`${key}Y`),
            this.getDownValue(`${key}Z`)
        )
    }
    public isValueDown(key: string,threshold: number = 0): boolean
    {
        return (this._downValues[key] ?? 0) > threshold
    }
    public isValuePressed(key: string,threshold: number = 0): boolean
    {
        return (this._pressedValues[key] ?? 0) > threshold
    }
    public update(): void
    {
        for(const method of this._methods)
            method.update?.(this)
    }
    public postUpdate(): void
    {
        this._pressedValues = {}
    }
}

export default EngineCoreInput