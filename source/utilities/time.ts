export abstract class TimeHandler
{
    private _currentTime: number = 0
    private _lastTime: number = 0
    public get deltaTime(): number
    {
        return this._currentTime - this._lastTime
    }
    public get framesPerSecond(): number
    {
        return 1000 / this.deltaTime
    }
    protected _cb: TimeHandler.Callback
    public constructor(callback: TimeHandler.Callback)
    {
        this._cb = callback
    }
    protected _update_time(time: number): void
    {
        this._lastTime = this._currentTime
        this._currentTime = time
    }
    public abstract start(): this
    public abstract stop(): this
    public restart(): this
    {
        return this.stop().start()
    }
}

export namespace TimeHandler
{
    export type Callback = () => unknown
}

export class RequestAnimationFrameTimeHandler extends TimeHandler
{
    private _handle: number = NaN
    private async _loop(time: number): Promise<void>
    {
        this._update_time(time)
        await this._cb()
        this._handle = requestAnimationFrame(this._loop.bind(this))
    }
    public override start(): this
    {
        this._handle = requestAnimationFrame(this._loop.bind(this))
        return this
    }
    public override stop(): this
    {
        cancelAnimationFrame(this._handle)
        return this
    }
}

export class SetIntervalTimeHandler extends TimeHandler
{
    private _handle: number = NaN
    public maxFramesPerSecond: number = 60
    public override start(): this
    {
        this.stop()
        this._handle = setInterval(async () =>
        {
            this._update_time(performance.now())
            await this._cb()
        },1000 / this.maxFramesPerSecond)
        return this
    }
    public override stop(): this
    {
        clearInterval(this._handle)
        return this
    }
}

export type TimeHandlerType = "requestAnimationFrame" | "setInterval"

export function createTimeHandler(type: TimeHandlerType,callback: TimeHandler.Callback): TimeHandler
{
    switch(type)
    {
        case "requestAnimationFrame":
            return new RequestAnimationFrameTimeHandler(callback)
        case "setInterval":
            return new SetIntervalTimeHandler(callback)
        default:
            throw new TypeError(`unknown time handler type '${type}'`)
    }
}

export function createPreferredTimeHandler(callback: TimeHandler.Callback): TimeHandler
{
    if(typeof requestAnimationFrame === "function")
        return new RequestAnimationFrameTimeHandler(callback)
    if(typeof setInterval === "function")
        return new SetIntervalTimeHandler(callback)
    throw new Error("the machine does not support any kind of time handling")
}