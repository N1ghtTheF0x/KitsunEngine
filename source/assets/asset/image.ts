import { loadImage } from "@utilities/media"
import Asset from "../asset"

class ImageAsset extends Asset<ImageBitmap>
{
    public static readonly TYPE: string = "image"
    public override readonly type: string = ImageAsset.TYPE
    public override async load(): Promise<void>
    {
        this._value = await createImageBitmap(await loadImage(this.path))
    }
    public override unload(): void
    {
        this._value?.close()
        this._value = undefined
    }
}

export default ImageAsset