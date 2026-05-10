import { Quaternion, Mat4, Vec3, Vec3Like, QuaternionLike } from "@ntf/math"

export class Transform
{
    private _position: Vec3
    private _rotation: Quaternion
    private _scale: Vec3
    private _matrix: Mat4
    private _local_matrix: Mat4
    public parent?: Transform
    public constructor(position: Vec3Like = [0,0,0],rotation: QuaternionLike = Quaternion.zero,scale: Vec3Like = [1,1,1],parent?: Transform)
    {
        this._position = Vec3.resolve(position)
        this._rotation = Quaternion.resolve(rotation)
        this._scale = Vec3.resolve(scale)
        this._matrix = this._calculate()
        this._local_matrix = this._calculate_local()
        this.parent = parent
    }
    private _calculate(): Mat4
    {
        let mat = new Mat4
        let parent = this.parent
        while(parent !== undefined)
        {
            mat = mat.multiply(parent._matrix)
            parent = parent.parent
        }
        return mat.multiply(this._calculate_local())
    }
    private _calculate_local(): Mat4
    {
        return new Mat4()
            .scale(this._scale)
            .multiply(this._rotation)
            .translate(this._position)
    }
    private _update(): this
    {
        this._matrix = this._calculate()
        return this
    }
    public getLocalPosition(): Vec3
    {
        return this._position
    }
    public setLocalPosition(position: Vec3Like): this
    {
        this._position = Vec3.resolve(position)
        return this._update()
    }
    public getLocalRotation(): Quaternion
    {
        return this._rotation
    }
    public setLocalRotation(rotation: QuaternionLike): this
    {
        this._rotation = Quaternion.resolve(rotation)
        return this._update()
    }
    public getLocalScale(): Vec3
    {
        return this._scale
    }
    public setLocalScale(scale: Vec3Like): this
    {
        this._scale = Vec3.resolve(scale)
        return this._update()
    }
    public getMatrix(): Mat4
    {
        return this._matrix
    }
    public getLocalMatrix(): Mat4
    {
        return this._local_matrix
    }
}

export type ReadonlyTransform = Readonly<Transform>