import { IDeletable, IDraw, IUpdate } from "@utilities/types"
import SceneNode from "./node"
import { ReadonlyTransform } from "@utilities/math/transform"

class Component implements IUpdate, IDraw, IDeletable
{
    public readonly node: SceneNode
    public get transform(): ReadonlyTransform
    {
        return this.node.transform
    }
    public constructor(node: SceneNode)
    {
        this.node = node
    }
    public delete(): void
    {

    }
    public update(): void
    {

    }
    public draw(): void
    {

    }
}

export default Component