export interface IPreUpdate
{
    preUpdate(): void
}

export interface IUpdate
{
    update(): void
}

export interface IDraw
{
    draw(): void
}

export interface IPostUpdate
{
    postUpdate(): void
}

export interface IInit
{
    init(): void
}

export interface IDeletable
{
    delete(): void
}

export type Typeof = {
    "string": string
    "number": number
    "bigint": bigint
    "boolean": boolean
    "symbol": symbol
    "undefined": undefined
    "object": {} | null
    "function": (...args: Array<unknown>) => unknown
}

export function required<T>(value: T | null | undefined): T
{
    if(value !== null && value !== undefined)
        return value
    throw new TypeError(`value is ${value}`)
}

export function requiredType<T extends keyof Typeof>(value: unknown,type: T): Typeof[T]
{
    if(typeof value === type)
        return value as Typeof[T]
    throw new TypeError(`${value} is not a ${type}`)
}

export function requirePrototype<V,Class extends new (...args: Array<unknown>) => V>(value: unknown,Class: Class): V
{
    if(value instanceof Class)
        return value
    throw new TypeError(`${value} is not a ${Class.name}`)
}

export function requireArray(value: unknown): Array<unknown>
{
    if(Array.isArray(value))
        return value
    throw new TypeError(`${value} is not an array`)
}

export function isReference<T>(value: unknown,...refs: ReadonlyArray<T>): value is T
{
    for(const ref of refs)
        if(ref === value)
            return true
    return false
}

export function requiredReference<T>(value: unknown,...refs: ReadonlyArray<T>): T
{
    if(isReference(value,...refs))
        return value
    throw new TypeError(`value is not ${refs.join(", ")}`)
}