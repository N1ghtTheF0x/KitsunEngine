import { OpenGL } from "@utilities/canvas"
import OpenGLProgram from "../../program"
import OpenGLShader from "../../shader"

import FRAGMENT_GLSL from "./pbr.frag"
import VERTEX_GLSL from "./pbr.vert"

class PBRShader
{
    public readonly gl: OpenGL
    public readonly program: OpenGLProgram
    public constructor(gl: OpenGL)
    {
        this.gl = gl
        this.program = OpenGLProgram.link(gl,
            OpenGLShader.compileVertex(gl,VERTEX_GLSL),
            OpenGLShader.compileFragment(gl,FRAGMENT_GLSL)
        )
    }
}

export default PBRShader