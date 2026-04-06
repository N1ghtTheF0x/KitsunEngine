export interface IPreUpdate
{
    preUpdate(): void
}

export interface IUpdate
{
    update(): void
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

export function required<T>(value: T | null | undefined): T
{
    if(value !== null && value !== undefined)
        return value
    throw new TypeError(`value is ${value}`)
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