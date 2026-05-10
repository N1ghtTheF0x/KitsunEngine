import { TimeHandlerMethod } from "@utilities/time"
import EngineCore from ".."
import { isReference } from "@utilities/types"

class EngineCoreConfig
{
    public static readonly MASTER_KEY = "kitsunengine"
    public readonly core: EngineCore
    public constructor(core: EngineCore)
    {
        this.core = core

        this
            .setDefaultValue("window.width",screen.width)
            .setDefaultValue("window.height",screen.height)
            .setDefaultValue("timehandler.method","auto")
            .setDefaultValue("timehandler.max_fps",60)
    }
    public getValue(key: string): string | undefined
    {
        return localStorage.getItem(`${EngineCoreConfig.MASTER_KEY}.${key}`) ?? undefined
    }
    public setValue(key: string,value: unknown): this
    {
        localStorage.setItem(`${EngineCoreConfig.MASTER_KEY}.${key}`,String(value))
        return this
    }
    public setDefaultValue(key: string,value: unknown): this
    {
        if(this.getValue(key) === undefined)
            this.setValue(key,value)
        return this
    }
    public getNumber(key: string): number | undefined
    {
        const value = this.getValue(key)
        if(value === undefined)
            return undefined
        const number = parseFloat(value)
        return isFinite(number) ? number : undefined
    }
    public getBoolean(key: string): boolean | undefined
    {
        const value = this.getValue(key)
        return value === "true" ? true : value === "false" ? false : undefined
    }
    public getWindowWidth(): number
    {
        return this.getNumber("window.width") ?? screen.width
    }
    public setWindowWidth(width: number): this
    {
        return this.setValue("window.width",width)
    }
    public getWindowHeight(): number
    {
        return this.getNumber("window.height") ?? screen.height
    }
    public setWindowHeight(height: number): this
    {
        return this.setValue("window.height",height)
    }
    public getTimeHandlerMethod(): TimeHandlerMethod
    {
        const method = this.getValue("timehandler.method") ?? "auto"
        if(!isReference(method,"auto","requestAnimationFrame","setTimeout","setInterval"))
            return "auto"
        return method
    }
    public setTimeHandlerMethod(method: TimeHandlerMethod): this
    {
        return this.setValue("timehandler.method",method)
    }
    public getTimeHandlerMaxFPS(): number
    {
        return this.getNumber("timehandler.max_fps") ?? 60
    }
    public setTimeHandlerMaxFPS(fps: number): this
    {
        return this.setValue("timehandler.max_fps",fps)
    }
}

export default EngineCoreConfig