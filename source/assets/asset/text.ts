import { IReadonlyFileSystemProvider } from "@core/io/filesystem/provider"
import Asset from "../asset"
import { textDecoder } from "@utilities/string"

class TextAsset extends Asset<string>
{
    public static readonly TYPE: string = "text"
    public override readonly type: string = TextAsset.TYPE
    public override async load(provider: IReadonlyFileSystemProvider): Promise<void>
    {
        this._value = textDecoder.decode(await provider.readFile(this.path))
    }
}

export default TextAsset