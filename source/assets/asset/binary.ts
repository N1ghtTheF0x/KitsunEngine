import Asset from "../asset"

class AssetBinary extends Asset<ArrayBuffer>
{
    public static readonly TYPE: string = "binary"
    public override readonly type: string = AssetBinary.TYPE
    public override async load(): Promise<void>
    {
        this._value = await (await fetch(this.path)).arrayBuffer()
    }
}

export default AssetBinary