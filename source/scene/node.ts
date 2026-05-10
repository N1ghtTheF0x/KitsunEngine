import { IDeletable, IDraw, IUpdate, required } from "@utilities/types"
import Scene from "./scene"
import { Transform } from "@utilities/math/transform"
import { Publisher } from "@utilities/observer"
import Component from "./component"

let id = 0n

let nodes: Array<SceneNode> = []
let deleting = false

class SceneNode implements IUpdate, IDraw, IDeletable
{
    public readonly id = id++
    public readonly scene: Scene
    public components: Array<Component> = []
    public readonly transform: Transform = new Transform
    private _parent?: bigint
    private _children: Array<bigint> = []
    public get parent(): SceneNode | undefined
    {
        return SceneNode.get(this._parent ?? -1n)
    }
    public set parent(parentNode: SceneNode | undefined)
    {
        if(parentNode === undefined || this._parent === parentNode.id)
            return
        if(this._parent !== undefined)
        {
            const parent = required(SceneNode.get(this._parent))
            parent.remove(this)
        }
        parentNode.add(this)
        this.transform.parent = parentNode.transform
    }
    public get children(): Array<SceneNode>
    {
        const children: Array<SceneNode> = []
        for(let i = 0;i < this._children.length;i++)
        {
            const child = required(this._children[i])
            const node = SceneNode.get(child)
            if(node === undefined)
            {
                this._children.splice(i,1)
                continue
            }
            children.push(node)
        }
        return children
    }
    public readonly onChildAdd = new Publisher<[child: SceneNode]>()
    public readonly onChildRemove = new Publisher<[removed: SceneNode]>()
    public readonly onComponentAdd = new Publisher<[component: Component]>()
    public static get(id: bigint): SceneNode | undefined
    {
        return nodes.find(node => node.id === id)
    }
    public static delete(): void
    {
        deleting = true
        for(const node of nodes)
            node.delete()
        nodes = []
        deleting = false
    }
    public static update(): void
    {
        for(const node of nodes)
            node.update()
    }
    public static draw(): void
    {
        for(const node of nodes)
            node.draw()
    }
    public constructor(scene: Scene,parent?: bigint)
    {
        if(deleting)
            throw new Error("cannot create a new node when deleting")
        this.scene = scene
        this._parent = parent
        nodes.push(this)
    }
    public createChild(): SceneNode
    {
        return this.add(new SceneNode(this.scene,this.id))
    }
    public add(node: SceneNode): this
    {
        if(!this._children.includes(node.id))
        {
            this._children.push(node.id)
            node._parent = this.id
            node.transform.parent = this.transform
            this.onChildAdd.notify(node)
        }
        return this
    }
    public remove(node: SceneNode): boolean
    {
        if(this._children.includes(node.id))
        {
            this._children.splice(this._children.indexOf(node.id),1)
            node._parent = undefined
            this.onChildRemove.notify(node)
            return true
        }
        return false
    }
    public pushComponent<C extends Component,Args extends Array<unknown>,Class extends new (node: SceneNode,...args: Args) => C>(Component: Class,...args: Args): C
    {
        const component = new Component(this,...args)
        this.components.push(component)
        this.onComponentAdd.notify(component)
        return component
    }
    public delete(): void
    {
        for(const c of this.components)
            c.delete()
    }
    public update(): void
    {
        for(const c of this.components)
            c.update()
    }
    public draw(): void
    {
        for(const c of this.components)
            c.draw()
    }
}

export default SceneNode