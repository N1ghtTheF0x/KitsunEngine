import { IReadonlyFileSystemProvider } from "@core/io/filesystem/provider"
import Asset from "../asset"
import { textDecoder } from "@utilities/string"
import { importString } from "@utilities/import"

class JavaScriptAsset extends Asset<unknown>
{
    public static readonly TYPE: "javascript"
    public override readonly type: string = JavaScriptAsset.TYPE
    public override async load(provider: IReadonlyFileSystemProvider): Promise<void>
    {
        const content = textDecoder.decode(await provider.readFile(this.path))
        this._value = await importString(content)
    }
}

export default JavaScriptAsset