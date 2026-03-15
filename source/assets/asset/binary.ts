import { IReadonlyFileSystemProvider } from "@core/io/filesystem/provider"
import Asset from "../asset"

class AssetBinary extends Asset<ArrayBuffer>
{
    public static readonly TYPE: string = "binary"
    public override readonly type: string = AssetBinary.TYPE
    public override async load(provider: IReadonlyFileSystemProvider): Promise<void>
    {
        this._value = await provider.readFile(this.path)
    }
}

export default AssetBinary