export class Publisher<Args extends Array<unknown> = []>
{
    private _subscribers: Array<Subscriber<Args>> = []
    public clear(): this
    {
        this._subscribers = []
        return this
    }
    public subscribe(...subscribe: Array<Subscriber<Args>>): this
    {
        this._subscribers.push(...subscribe)
        return this
    }
    public unsubscribe(subscribe: Subscriber<Args>): boolean
    {
        const index = this._subscribers.indexOf(subscribe)
        if(index === -1)
            return false
        this._subscribers.splice(index,1)
        return true
    }
    public notify(...args: Args): void
    {
        for(const sub of this._subscribers)
        {
            if(typeof sub === "function")
                sub(...args)
            else if(typeof sub === "object")
                sub.onNotify(...args)
        }
    }
}

export interface ISubscriber<Args extends Array<unknown>>
{
    onNotify(...args: Args): void
}

export type SubscriberCallback<Args extends Array<unknown>> = (...args: Args) => void

export type Subscriber<Args extends Array<unknown>> = ISubscriber<Args> | SubscriberCallback<Args>