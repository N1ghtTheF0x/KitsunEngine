import { Vec2, Vec2Like, Vec3, Vec3Like } from "@ntf/math";

class Vertex
{
    public position: Vec3
    public uv: Vec2
    public normal: Vec3
    public constructor(position: Vec3Like,uv: Vec2Like = [0,0],normal: Vec3Like = [0,0,0])
    {
        this.position = Vec3.resolve(position)
        this.uv = Vec2.resolve(uv)
        this.normal = Vec3.resolve(normal)
    }
}

export default Vertex