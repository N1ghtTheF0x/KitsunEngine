export function defineGlobal<T>(name: PropertyKey,get: () => T): void
{
    if(PROD) return
    Object.defineProperty(globalThis,name,{get: get})
}