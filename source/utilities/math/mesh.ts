import { Vec3, Vec3Like } from "@ntf/math";
import Vertex from "./vertex";

class Mesh
{
    public vertices: Array<Vertex>
    public indices: Array<Vec3>
    public constructor(vertices: Array<Vertex>,indices: Array<Vec3Like> = [])
    {
        this.vertices = vertices
        this.indices = indices.map(index => Vec3.resolve(index))
    }
}

export default Mesh