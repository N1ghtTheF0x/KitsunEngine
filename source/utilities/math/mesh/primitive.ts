import Mesh from "../mesh";
import Vertex from "../vertex";

namespace MeshPrimitive
{
    export function cube(size: number = 1): Mesh
    {
        return new Mesh([
            new Vertex([-0.5 * size,0.5 * size,0.5 * size]), // top left front
            new Vertex([-0.5 * size,-0.5 * size,0.5 * size]), // bottom left front
            new Vertex([0.5 * size,-0.5 * size,0.5 * size]), // bottom right front
            new Vertex([0.5 * size,0.5 * size,0.5 * size]), // top right front

            new Vertex([-0.5 * size,0.5 * size,-0.5 * size]), // top left back
            new Vertex([-0.5 * size,-0.5 * size,-0.5 * size]), // bottom left back
            new Vertex([0.5 * size,-0.5 * size,-0.5 * size]), // bottom right back
            new Vertex([0.5 * size,0.5 * size,-0.5 * size]), // top right back
        ],[
            [0,1,2], // bottom left front
            [0,2,3], // top right front
            [4,5,6], // bottom left
        ])
    }
}

export default MeshPrimitive