import Asset from "../asset"
import { IReadonlyFileSystemProvider } from "@core/io/filesystem/provider"

class ImageAsset extends Asset<ImageBitmap>
{
    public static readonly TYPE: string = "image"
    public override readonly type: string = ImageAsset.TYPE
    public override async load(provider: IReadonlyFileSystemProvider): Promise<void>
    {
        this._value = await createImageBitmap(new Blob([await provider.readFile(this.path)]))
    }
    public override unload(): void
    {
        this._value?.close()
        this._value = undefined
    }
}

export default ImageAsset