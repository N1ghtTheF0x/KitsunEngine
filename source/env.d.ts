declare const PROD: boolean

type NtfMath = typeof import("@ntf/math")

declare interface Math extends NtfMath
{

}

declare module "*.vert"
{
    const content: string
    export default content
}
declare module "*.frag"
{
    const content: string
    export default content
}