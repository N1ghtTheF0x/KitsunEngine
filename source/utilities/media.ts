export function loadImage(src: string): Promise<HTMLImageElement>
{
    return new Promise<HTMLImageElement>((resolve,reject) =>
    {
        const img = new Image
        img.src = src
        function __clear__(): void
        {
            img.onload = img.onerror = null
        }
        img.onload = function()
        {
            __clear__()
            resolve(img)
        }
        img.onerror = function(...args)
        {
            __clear__()
            reject(args[4])
        }
    })
}