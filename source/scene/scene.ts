import { IDeletable, IDraw, IUpdate } from "@utilities/types"
import SceneManager from "."
import SceneNode from "./node"

let id = 0n

class Scene implements IDeletable, IUpdate, IDraw
{
    public readonly manager: SceneManager
    public readonly id = id++
    public readonly root: SceneNode
    public constructor(manager: SceneManager)
    {
        this.manager = manager
        this.root = this.createNode()
    }
    public createNode(): SceneNode
    {
        return new SceneNode(this)
    }
    public delete(): void
    {
        SceneNode.delete()
    }
    public update(): void 
    {
        SceneNode.update()
    }
    public draw(): void
    {
        SceneNode.draw()
    }
}

export default Scene