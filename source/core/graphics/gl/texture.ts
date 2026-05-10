import { OpenGL } from "@utilities/canvas"
import OpenGLObject from "./object"
import { Size, SizeLike, Vec2, Vec2Like } from "@ntf/math"
import { required, requiredReference, requiredType } from "@utilities/types"

class OpenGLTexture extends OpenGLObject<WebGLTexture>
{
    public readonly target: OpenGLTexture.Target
    public static create(gl: OpenGL,target: OpenGLTexture.Target): OpenGLTexture
    {
        return new this(gl,gl.createTexture(),target)
    }
    public static unbind(gl: OpenGL,target: OpenGLTexture.Target): void
    {
        gl.bindTexture(target,null)
    }
    public constructor(gl: OpenGL,texture: WebGLTexture | null,target: OpenGLTexture.Target)
    {
        super(gl,texture)
        this.target = target
    }
    public override delete(): void
    {
        this.gl.deleteTexture(this.object)
    }
    public override getParameter(pname: GLenum): unknown
    {
        return this.gl.getTexParameter(this.target,pname)
    }
    public bind(): this
    {
        this.gl.bindTexture(this.target,required(this.object))
        return this
    }
    public getMaxFilter(): OpenGLTexture.MagFilter
    {
        return requiredReference(this.getParameter(this.gl.TEXTURE_MAG_FILTER),9729,9728)
    }
    public getMinFilter(): OpenGLTexture.MinFilter
    {
        return requiredReference(this.getParameter(this.gl.TEXTURE_MIN_FILTER),9729,9728,9984,9985,9986,9987)
    }
    public getTextureWrapS(): OpenGLTexture.Wrap
    {
        return requiredReference(this.getParameter(this.gl.TEXTURE_WRAP_S),10497,33071,33648)
    }
    public getTextureWrapT(): OpenGLTexture.Wrap
    {
        return requiredReference(this.getParameter(this.gl.TEXTURE_WRAP_T),10497,33071,33648)
    }
    public getMaxAnisotropyExtension(): GLfloat
    {
        return requiredType(this.getParameter(this.getExtension("EXT_texture_filter_anisotropic").TEXTURE_MAX_ANISOTROPY_EXT),"number")
    }
    public getBaseLevel(): GLint
    {
        return requiredType(this.getParameter(this.gl2.TEXTURE_BASE_LEVEL),"number")
    }
    public getCompareFunction(): OpenGLTexture.CompareFunction
    {
        return requiredReference(this.getParameter(this.gl2.TEXTURE_COMPARE_FUNC),515,518,513,516,514,517,519,512)
    }
    public getCompareMode(): OpenGLTexture.CompareMode
    {
        return requiredReference(this.getParameter(this.gl2.TEXTURE_COMPARE_MODE),0,34894)
    }
    public getImutableFormat(): GLboolean
    {
        return requiredType(this.getParameter(this.gl2.TEXTURE_IMMUTABLE_FORMAT),"boolean")
    }
    public getImutableLevels(): GLint
    {
        return requiredType(this.getParameter(this.gl2.TEXTURE_IMMUTABLE_LEVELS),"number")
    }
    public getMaxLevel(): GLint
    {
        return requiredType(this.getParameter(this.gl2.TEXTURE_MAX_LEVEL),"number")
    }
    public getMaxLOD(): GLfloat
    {
        return requiredType(this.getParameter(this.gl2.TEXTURE_MAX_LOD),"number")
    }
    public getMinLOD(): GLfloat
    {
        return requiredType(this.getParameter(this.gl2.TEXTURE_MIN_LOD),"number")
    }
    public getTextureWrapR(): OpenGLTexture.Wrap
    {
        return requiredReference(this.getParameter(this.gl2.TEXTURE_WRAP_R),10497,33071,33648)
    }
    public loadCompressed(
        level: GLint,
        internalFormat: OpenGLTexture.CompressedFormat,
        size: SizeLike,
        data: ArrayBufferView
    ): void
    {
        const s = Size.resolve(size)
        this.gl.compressedTexImage2D(
            this.target,
            level,
            internalFormat,
            s.width,
            s.height,
            0,
            data
        )
    }
    public loadCompressedSub(
        level: GLint,
        offset: Vec2Like,
        size: SizeLike,
        format: OpenGLTexture.CompressedFormat,
        data: ArrayBufferView
    ): void
    {
        const o = Vec2.resolve(offset)
        const s = Size.resolve(size)
        this.gl.compressedTexSubImage2D(
            this.target,
            level,
            o.x,o.y,
            s.width,s.height,
            format,
            data
        )
    }
    public copyFromCurrentFramebuffer(
        level: GLint,
        format: OpenGLTexture.CopyFormat,
        position: Vec2Like,
        size: SizeLike
    ): void
    {
        const p = Vec2.resolve(position)
        const s = Size.resolve(size)
        this.gl.copyTexImage2D(
            this.target,
            level,
            format,
            p.x,p.y,
            s.width,s.height,
            0
        )
    }
    public copyFromCurrentFramebufferSub(
        level: GLint,
        offset: Vec2Like,
        position: Vec2Like,
        size: SizeLike
    ): void
    {
        const o = Vec2.resolve(offset)
        const p = Vec2.resolve(position)
        const s = Size.resolve(size)
        this.gl.copyTexSubImage2D(
            this.target,
            level,
            o.x,o.y,
            p.x,p.y,
            s.width,s.height
        )
    }
    public generateMipmap(): void
    {
        this.gl.generateMipmap(this.target)
    }
    public load<IF extends keyof OpenGLTexture.FormatMap>(
        level: GLint,
        internalFormat: IF,
        size: SizeLike,
        format: OpenGLTexture.FormatMap[IF][0],
        type: OpenGLTexture.FormatMap[IF][1],
        data: ArrayBufferView
    ): void
    {
        const s = Size.resolve(size)
        this.gl.texImage2D(
            this.target,
            level,
            internalFormat,
            s.width,s.height,
            0,
            format,
            type,
            data
        )
    }
    public loadBitmap<IF extends keyof OpenGLTexture.FormatMap>(
        level: GLint,
        internalFormat: IF,
        format: OpenGLTexture.FormatMap[IF][0],
        type: OpenGLTexture.FormatMap[IF][1],
        bitmap: ImageBitmap
    ): void
    {
        this.gl.texImage2D(
            this.target,
            level,
            internalFormat,
            format,
            type,
            bitmap
        )
    }
    public loadSub<IF extends keyof OpenGLTexture.FormatMap>(
        level: GLint,
        offset: Vec2Like,
        size: SizeLike,
        format: OpenGLTexture.FormatMap[IF][0],
        type: OpenGLTexture.FormatMap[IF][1],
        data: ArrayBufferView
    ): void
    {
        const s = Size.resolve(size)
        const o = Vec2.resolve(offset)
        this.gl.texSubImage2D(
            this.target,
            level,
            o.x,o.y,
            s.width,s.height,
            format,
            type,
            data
        )
    }
    public loadBitmapSub<IF extends keyof OpenGLTexture.FormatMap>(
        level: GLint,
        offset: Vec2Like,
        format: OpenGLTexture.FormatMap[IF][0],
        type: OpenGLTexture.FormatMap[IF][1],
        bitmap: ImageBitmap
    ): void
    {
        const o = Vec2.resolve(offset)
        this.gl.texSubImage2D(
            this.target,
            level,
            o.x,o.y,
            format,
            type,
            bitmap
        )
    }
    public setMagFilter(filter: OpenGLTexture.MagFilter): this
    {
        this.gl.texParameteri(this.target,this.gl.TEXTURE_MAG_FILTER,filter)
        return this
    }
    public setMinFilter(filter: OpenGLTexture.MinFilter): this
    {
        this.gl.texParameteri(this.target,this.gl.TEXTURE_MIN_FILTER,filter)
        return this
    }
    public setWarpS(wrap: OpenGLTexture.Wrap): this
    {
        this.gl.texParameteri(this.target,this.gl.TEXTURE_WRAP_S,wrap)
        return this
    }
    public setWarpT(wrap: OpenGLTexture.Wrap): this
    {
        this.gl.texParameteri(this.target,this.gl.TEXTURE_WRAP_T,wrap)
        return this
    }
    public setMaxAnistropyExtension(anisotropy: GLfloat): this
    {
        this.gl.texParameterf(this.target,this.getExtension("EXT_texture_filter_anisotropic").TEXTURE_MAX_ANISOTROPY_EXT,anisotropy)
        return this
    }
    public setBaseLevel(base: GLint): this
    {
        this.gl.texParameteri(this.target,this.gl2.TEXTURE_BASE_LEVEL,base)
        return this
    }
    public setCompareFunction(func: OpenGLTexture.CompareFunction): this
    {
        this.gl.texParameteri(this.target,this.gl2.TEXTURE_COMPARE_FUNC,func)
        return this
    }
    public setCompareMode(mode: OpenGLTexture.CompareMode): this
    {
        this.gl.texParameteri(this.target,this.gl2.TEXTURE_COMPARE_MODE,mode)
        return this
    }
    public setMaxLevel(level: GLint): this
    {
        this.gl.texParameteri(this.target,this.gl2.TEXTURE_MAX_LEVEL,level)
        return this
    }
    public setMaxLOD(lod: GLfloat): this
    {
        this.gl.texParameterf(this.target,this.gl2.TEXTURE_MAX_LOD,lod)
        return this
    }
    public setMinLOD(lod: GLfloat): this
    {
        this.gl.texParameterf(this.target,this.gl2.TEXTURE_MIN_LOD,lod)
        return this
    }
    public setWarpR(wrap: OpenGLTexture.Wrap): this
    {
        this.gl.texParameteri(this.target,this.gl2.TEXTURE_WRAP_R,wrap)
        return this
    }
}

namespace OpenGLTexture
{
    export type Target = OpenGL["TEXTURE_2D"] | OpenGL["TEXTURE_CUBE_MAP_NEGATIVE_X"] | OpenGL["TEXTURE_CUBE_MAP_POSITIVE_X"] | OpenGL["TEXTURE_CUBE_MAP_NEGATIVE_Y"] | OpenGL["TEXTURE_CUBE_MAP_POSITIVE_Y"] | OpenGL["TEXTURE_CUBE_MAP_NEGATIVE_Z"] | OpenGL["TEXTURE_CUBE_MAP_POSITIVE_Z"] | OpenGL["TEXTURE_CUBE_MAP"] | WebGL2RenderingContext["TEXTURE_3D"] | WebGL2RenderingContext["TEXTURE_2D_ARRAY"]
    export type CompressedFormat = GLenum
    export type CopyFormat = OpenGL["ALPHA"] | OpenGL["RGB"] | OpenGL["RGBA"] | OpenGL["LUMINANCE"] | OpenGL["LUMINANCE_ALPHA"]
    export type MagFilter = OpenGL["LINEAR"] | OpenGL["NEAREST"]
    export type MinFilter = OpenGL["LINEAR"] | OpenGL["NEAREST"] | OpenGL["NEAREST_MIPMAP_NEAREST"] | OpenGL["LINEAR_MIPMAP_NEAREST"] | OpenGL["NEAREST_MIPMAP_LINEAR"] | OpenGL["LINEAR_MIPMAP_LINEAR"]
    export type Wrap = OpenGL["REPEAT"] | OpenGL["CLAMP_TO_EDGE"] | OpenGL["MIRRORED_REPEAT"]
    export type CompareFunction = WebGL2RenderingContext["LEQUAL"] | WebGL2RenderingContext["GEQUAL"] | WebGL2RenderingContext["LESS"] | WebGL2RenderingContext["GREATER"] | WebGL2RenderingContext["EQUAL"] | WebGL2RenderingContext["NOTEQUAL"] | WebGL2RenderingContext["ALWAYS"] | WebGL2RenderingContext["NEVER"]
    export type CompareMode = WebGL2RenderingContext["NONE"] | WebGL2RenderingContext["COMPARE_REF_TO_TEXTURE"]
    export type FormatMap = {
        [6407]: [OpenGL["RGB"],OpenGL["UNSIGNED_BYTE"] | OpenGL["UNSIGNED_SHORT_5_6_5"]]
        [6408]: [OpenGL["RGBA"],OpenGL["UNSIGNED_BYTE"] | OpenGL["UNSIGNED_SHORT_4_4_4_4"] | OpenGL["UNSIGNED_SHORT_5_5_5_1"]]
        [6410]: [OpenGL["LUMINANCE_ALPHA"],OpenGL["UNSIGNED_BYTE"]]
        [6409]: [OpenGL["LUMINANCE"],OpenGL["UNSIGNED_BYTE"]]
        [6406]: [OpenGL["ALPHA"],OpenGL["UNSIGNED_BYTE"]]
    }
}

export default OpenGLTexture