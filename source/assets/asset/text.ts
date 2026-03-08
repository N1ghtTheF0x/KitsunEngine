import Asset from "../asset"

class TextAsset extends Asset<string>
{
    public static readonly TYPE: string = "text"
    public override readonly type: string = TextAsset.TYPE
    public override async load(): Promise<void>
    {
        this._value = await (await fetch(this.path)).text()
    }
}

export default TextAsset