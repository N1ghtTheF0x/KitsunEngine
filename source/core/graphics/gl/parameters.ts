import { OpenGL } from "@utilities/canvas"
import OpenGLBase from "./base"
import { RGBA, Vec2, Size, Rectangle } from "@ntf/math"
import { requiredType, requirePrototype, required, requireArray, requiredReference } from "@utilities/types"
import { GLuint64EXT } from "./extensions/EXT_disjoint_timer_query"

class OpenGLParameters<GL extends OpenGL = OpenGL> extends OpenGLBase<GL>
{
    public getActiveTexture(): GLenum
    {
        return requiredType(this.getParameter(this.gl.ACTIVE_TEXTURE),"number")
    }
    public getAliasedLineWidthRange(): Float32Array
    {
        return requirePrototype(this.getParameter(this.gl.ALIASED_LINE_WIDTH_RANGE),Float32Array)
    }
    public getAliasedPointSizeRange(): Float32Array
    {
        return requirePrototype(this.getParameter(this.gl.ALIASED_POINT_SIZE_RANGE),Float32Array)
    }
    public getAlphaBits(): GLint
    {
        return requiredType(this.getParameter(this.gl.ALPHA_BITS),"number")
    }
    public getArrayBufferBinding(): WebGLBuffer
    {
        return requirePrototype(this.getParameter(this.gl.ARRAY_BUFFER_BINDING),WebGLBuffer)
    }
    public getBlend(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.BLEND),"boolean")
    }
    public getBlendColor(): RGBA
    {
        const [red,green,blue,alpha] = requirePrototype<Float32Array,Float32ArrayConstructor>(this.getParameter(this.gl.BLEND_COLOR),Float32Array)
        return new RGBA(required(red),required(green),required(blue),required(alpha))
    }
    public getBlendDestinationAlpha(): GLenum
    {
        return requiredType(this.getParameter(this.gl.BLEND_DST_ALPHA),"number")
    }
    public getBlendDestinationRGB(): GLenum
    {
        return requiredType(this.getParameter(this.gl.BLEND_DST_RGB),"number")
    }
    public getBlendEquation(): GLenum
    {
        return requiredType(this.getParameter(this.gl.BLEND_EQUATION),"number")
    }
    public getBlendEquationAlpha(): GLenum
    {
        return requiredType(this.getParameter(this.gl.BLEND_EQUATION_ALPHA),"number")
    }
    public getBlendEquationRGB(): GLenum
    {
        return requiredType(this.getParameter(this.gl.BLEND_EQUATION_RGB),"number")
    }
    public getBlendSourceAlpha(): GLenum
    {
        return requiredType(this.getParameter(this.gl.BLEND_SRC_ALPHA),"number")
    }
    public getBlendSourceRGB(): GLenum
    {
        return requiredType(this.getParameter(this.gl.BLEND_SRC_RGB),"number")
    }
    public getBlueBits(): GLint
    {
        return requiredType(this.getParameter(this.gl.BLUE_BITS),"number")
    }
    public getClearColor(): RGBA
    {
        const [red,green,blue,alpha] = requirePrototype<Float32Array,Float32ArrayConstructor>(this.getParameter(this.gl.COLOR_CLEAR_VALUE),Float32Array)
        return new RGBA(required(red),required(green),required(blue),required(alpha))
    }
    public getWriteMask(): [boolean,boolean,boolean,boolean]
    {
        const [a,b,c,d] = requireArray(this.getParameter(this.gl.COLOR_WRITEMASK))
        return [requiredType(a,"boolean"),requiredType(b,"boolean"),requiredType(c,"boolean"),requiredType(d,"boolean")]
    }
    public getCompressedTextureFormats(): Array<GLenum>
    {
        const items = requirePrototype<Uint32Array,Uint32ArrayConstructor>(this.getParameter(this.gl.COMPRESSED_TEXTURE_FORMATS),Uint32Array)
        return [...items]
    }
    public getCullFace(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.CULL_FACE),"boolean")
    }
    public getCullFaceMode(): GLenum
    {
        return requiredType(this.getParameter(this.gl.CULL_FACE_MODE),"number")
    }
    public getCurrentProgram(): WebGLProgram | undefined
    {
        const program = this.getParameter(this.gl.CURRENT_PROGRAM)
        if(program === null)
            return undefined
        return requirePrototype(program,WebGLProgram)
    }
    public getDepthBits(): GLint
    {
        return requiredType(this.getParameter(this.gl.DEPTH_BITS),"number")
    }
    public getDepthClearValue(): GLfloat
    {
        return requiredType(this.getParameter(this.gl.DEPTH_CLEAR_VALUE),"number")
    }
    public getDepthFunction(): GLenum
    {
        return requiredType(this.getParameter(this.gl.DEPTH_FUNC),"number")
    }
    public getDepthRange(): Vec2
    {
        return Vec2.resolve([...requirePrototype<Float32Array,Float32ArrayConstructor>(this.getParameter(this.gl.COMPRESSED_TEXTURE_FORMATS),Float32Array)])
    }
    public getDepthTest(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.DEPTH_TEST),"boolean")
    }
    public getDepthWriteMask(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.DEPTH_WRITEMASK),"boolean")
    }
    public getDither(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.DITHER),"boolean")
    }
    public getElementArrayBufferBinding(): WebGLBuffer
    {
        return requirePrototype(this.getParameter(this.gl.DITHER),WebGLBuffer)
    }
    public getFramebufferBinding(): WebGLFramebuffer | undefined
    {
        const framebuffer = this.getParameter(this.gl.FRAMEBUFFER_BINDING)
        if(framebuffer === null)
            return undefined
        return requirePrototype(framebuffer,WebGLFramebuffer)
    }
    public getFrontFace(): GLenum
    {
        return requiredType(this.getParameter(this.gl.FRONT_FACE),"number")
    }
    public getGenerateMipmapHint(): GLenum
    {
        return requiredType(this.getParameter(this.gl.GENERATE_MIPMAP_HINT),"number")
    }
    public getGreenBits(): GLint
    {
        return requiredType(this.getParameter(this.gl.GREEN_BITS),"number")
    }
    public getImplementationColorReadFormat(): GLenum
    {
        return requiredType(this.getParameter(this.gl.IMPLEMENTATION_COLOR_READ_FORMAT),"number")
    }
    public getImplementationColorReadType(): GLenum
    {
        return requiredType(this.getParameter(this.gl.IMPLEMENTATION_COLOR_READ_TYPE),"number")
    }
    public getLineWidth(): GLfloat
    {
        return requiredType(this.getParameter(this.gl.LINE_WIDTH),"number")
    }
    public getMaxCombinedTextureImageUnits(): GLint
    {
        return requiredType(this.getParameter(this.gl.MAX_COMBINED_TEXTURE_IMAGE_UNITS),"number")
    }
    public getMaxCubeMapTextureSize(): GLint
    {
        return requiredType(this.getParameter(this.gl.MAX_CUBE_MAP_TEXTURE_SIZE),"number")
    }
    public getMaxRenderbufferSize(): GLint
    {
        return requiredType(this.getParameter(this.gl.MAX_RENDERBUFFER_SIZE),"number")
    }
    public getMaxTextureImageUnits(): GLint
    {
        return requiredType(this.getParameter(this.gl.MAX_TEXTURE_IMAGE_UNITS),"number")
    }
    public getMaxTextureSize(): GLint
    {
        return requiredType(this.getParameter(this.gl.MAX_TEXTURE_SIZE),"number")
    }
    public getMaxVaryingVectors(): GLint
    {
        return requiredType(this.getParameter(this.gl.MAX_VARYING_VECTORS),"number")
    }
    public getMaxVertexAttributes(): GLint
    {
        return requiredType(this.getParameter(this.gl.MAX_VERTEX_ATTRIBS),"number")
    }
    public getMaxVertexTextureImageUnits(): GLint
    {
        return requiredType(this.getParameter(this.gl.MAX_VERTEX_TEXTURE_IMAGE_UNITS),"number")
    }
    public getMaxVertexUniformVectors(): GLint
    {
        return requiredType(this.getParameter(this.gl.MAX_VERTEX_UNIFORM_VECTORS),"number")
    }
    public getMaxViewportDimensions(): Size
    {
        return Size.resolve([...requirePrototype<Int32Array,Int32ArrayConstructor>(this.getParameter(this.gl.MAX_VIEWPORT_DIMS),Int32Array)])
    }
    public getPackAlignment(): GLint
    {
        return requiredType(this.getParameter(this.gl.PACK_ALIGNMENT),"number")
    }
    public getPolygonOffsetFactor(): GLfloat
    {
        return requiredType(this.getParameter(this.gl.POLYGON_OFFSET_FACTOR),"number")
    }
    public getPolygonOffsetFill(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.POLYGON_OFFSET_FILL),"boolean")
    }
    public getPolygonOffsetUnits(): GLfloat
    {
        return requiredType(this.getParameter(this.gl.POLYGON_OFFSET_UNITS),"number")
    }
    public getRedBits(): GLint
    {
        return requiredType(this.getParameter(this.gl.RED_BITS),"number")
    }
    public getRenderbufferBinding(): WebGLRenderbuffer | undefined
    {
        const renderbuffer = this.getParameter(this.gl.RENDERBUFFER_BINDING)
        if(renderbuffer === null)
            return undefined
        return requirePrototype(renderbuffer,WebGLRenderbuffer)
    }
    public getRenderer(): string
    {
        return requiredType(this.getParameter(this.gl.RENDERER),"string")
    }
    public getSampleBuffers(): GLint
    {
        return requiredType(this.getParameter(this.gl.SAMPLE_BUFFERS),"number")
    }
    public getSampleCoverageInvert(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.SAMPLE_COVERAGE_INVERT),"boolean")
    }
    public getSampleCoverageValue(): GLfloat
    {
        return requiredType(this.getParameter(this.gl.SAMPLE_COVERAGE_INVERT),"number")
    }
    public getSamples(): GLint
    {
        return requiredType(this.getParameter(this.gl.SAMPLES),"number")
    }
    public getScissorBox(): Rectangle
    {
        return Rectangle.resolve([...requirePrototype<Int32Array,Int32ArrayConstructor>(this.getParameter(this.gl.SCISSOR_BOX),Int32Array)])
    }
    public getScissorTest(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.SCISSOR_TEST),"boolean")
    }
    public getShadingLanguageVersion(): string
    {
        return requiredType(this.getParameter(this.gl.SHADING_LANGUAGE_VERSION),"string")
    }
    public getStencilBackFail(): GLenum
    {
        return requiredType(this.getParameter(this.gl.STENCIL_BACK_FAIL),"number")
    }
    public getStencilBackFunction(): GLenum
    {
        return requiredType(this.getParameter(this.gl.STENCIL_BACK_FUNC),"number")
    }
    public getStencilBackPassDepthFail(): GLenum
    {
        return requiredType(this.getParameter(this.gl.STENCIL_BACK_PASS_DEPTH_FAIL),"number")
    }
    public getStencilBackPassDepthPass(): GLenum
    {
        return requiredType(this.getParameter(this.gl.STENCIL_BACK_PASS_DEPTH_PASS),"number")
    }
    public getStencilBackReference(): GLint
    {
        return requiredType(this.getParameter(this.gl.STENCIL_BACK_REF),"number")
    }
    public getStencilBackValueMask(): GLuint
    {
        return requiredType(this.getParameter(this.gl.STENCIL_BACK_VALUE_MASK),"number")
    }
    public getStencilBackWriteMask(): GLuint
    {
        return requiredType(this.getParameter(this.gl.STENCIL_BACK_WRITEMASK),"number")
    }
    public getStencilBits(): GLint
    {
        return requiredType(this.getParameter(this.gl.STENCIL_BITS),"number")
    }
    public getStencilClearValue(): GLint
    {
        return requiredType(this.getParameter(this.gl.STENCIL_CLEAR_VALUE),"number")
    }
    public getStencilFail(): GLenum
    {
        return requiredType(this.getParameter(this.gl.STENCIL_FAIL),"number")
    }
    public getStencilFunction(): GLenum
    {
        return requiredType(this.getParameter(this.gl.STENCIL_FUNC),"number")
    }
    public getStencilPassDepthFail(): GLenum
    {
        return requiredType(this.getParameter(this.gl.STENCIL_PASS_DEPTH_FAIL),"number")
    }
    public getStencilPassDepthPass(): GLenum
    {
        return requiredType(this.getParameter(this.gl.STENCIL_PASS_DEPTH_PASS),"number")
    }
    public getStencilReference(): GLint
    {
        return requiredType(this.getParameter(this.gl.STENCIL_REF),"number")
    }
    public getStencilTest(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.STENCIL_TEST),"boolean")
    }
    public getStencilValueMask(): GLuint
    {
        return requiredType(this.getParameter(this.gl.STENCIL_VALUE_MASK),"number")
    }
    public getStencilWriteMask(): GLint
    {
        return requiredType(this.getParameter(this.gl.STENCIL_WRITEMASK),"number")
    }
    public getSubpixelBits(): GLint
    {
        return requiredType(this.getParameter(this.gl.SUBPIXEL_BITS),"number")
    }
    public getTextureBinding2D(): WebGLTexture | undefined
    {
        const texture = this.getParameter(this.gl.TEXTURE_BINDING_2D)
        if(texture === null)
            return undefined
        return requirePrototype(texture,WebGLTexture)
    }
    public getTextureBindingCubeMap(): WebGLTexture | undefined
    {
        const texture = this.getParameter(this.gl.TEXTURE_BINDING_CUBE_MAP)
        if(texture === null)
            return undefined
        return requirePrototype(texture,WebGLTexture)
    }
    public getUnpackAlignment(): GLint
    {
        return requiredType(this.getParameter(this.gl.UNPACK_ALIGNMENT),"number")
    }
    public getUnpackColorspaceConversionWebGL(): GLenum
    {
        return requiredType(this.getParameter(this.gl.UNPACK_COLORSPACE_CONVERSION_WEBGL),"number")
    }
    public getUnpackFlipYWebGL(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.UNPACK_FLIP_Y_WEBGL),"boolean")
    }
    public getUnpackPremultiplyAlphaWebGL(): GLboolean
    {
        return requiredType(this.getParameter(this.gl.UNPACK_PREMULTIPLY_ALPHA_WEBGL),"boolean")
    }
    public getVendor(): string
    {
        return requiredType(this.getParameter(this.gl.VENDOR),"string")
    }
    public getVersion(): string
    {
        return requiredType(this.getParameter(this.gl.VERSION),"string")
    }
    public getViewport(): Rectangle
    {
        return Rectangle.resolve([...requirePrototype<Int32Array,Int32ArrayConstructor>(this.getParameter(this.gl.VIEWPORT),Int32Array)])
    }
    public getCopyReadBufferBinding(): WebGLBuffer | undefined
    {
        return this.getObjectParameter(this.gl2.COPY_READ_BUFFER_BINDING,WebGLBuffer)
    }
    public getCopyWriteBufferBinding(): WebGLBuffer | undefined
    {
        return this.getObjectParameter(this.gl2.COPY_WRITE_BUFFER_BINDING,WebGLBuffer)
    }
    public getDrawBuffer(i: number): GLenum
    {
        const pname = this.gl2[`DRAW_BUFFER${requiredReference(i,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15)}`]
        return this.getTypedParameter(pname,"number")
    }
    public getDrawFramebufferBinding(): WebGLFramebuffer | undefined
    {
        return this.getObjectParameter(this.gl2.DRAW_FRAMEBUFFER_BINDING,WebGLFramebuffer)
    }
    public getFragmentShaderDerivativeHint(): GLenum
    {
        return this.getTypedParameter(this.gl2.FRAGMENT_SHADER_DERIVATIVE_HINT,"number")
    }
    public getMax3DTextureSize(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_3D_TEXTURE_SIZE,"number")
    }
    public getMaxArrayTextureLayers(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_ARRAY_TEXTURE_LAYERS,"number")
    }
    public getMaxClientWaitTimeoutWebGL(): GLint64
    {
        return this.getTypedParameter(this.gl2.MAX_CLIENT_WAIT_TIMEOUT_WEBGL,"number")
    }
    public getMaxColorAttachments(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_COLOR_ATTACHMENTS,"number")
    }
    public getMaxCombinedFragmentUniformComponents(): GLint64
    {
        return this.getTypedParameter(this.gl2.MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS,"number")
    }
    public getMaxCombinedUniformBlocks(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_COMBINED_UNIFORM_BLOCKS,"number")
    }
    public getMaxCombinedVertexUniformComponents(): GLint64
    {
        return this.getTypedParameter(this.gl2.MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS,"number")
    }
    public getMaxDrawBuffers(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_DRAW_BUFFERS,"number")
    }
    public getMaxElementIndex(): GLint64
    {
        return this.getTypedParameter(this.gl2.MAX_ELEMENT_INDEX,"number")
    }
    public getMaxElementsIndices(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_ELEMENTS_INDICES,"number")
    }
    public getMaxElementsVertices(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_ELEMENTS_VERTICES,"number")
    }
    public getMaxFragmentInputComponents(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_FRAGMENT_INPUT_COMPONENTS,"number")
    }
    public getMaxFragmentUniformBlocks(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_FRAGMENT_UNIFORM_BLOCKS,"number")
    }
    public getMaxFragmentUniformComponents(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_FRAGMENT_UNIFORM_COMPONENTS,"number")
    }
    public getMaxProgramTexelOffset(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_PROGRAM_TEXEL_OFFSET,"number")
    }
    public getMaxSamples(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_SAMPLES,"number")
    }
    public getMaxServerWaitTimeout(): GLint64
    {
        return this.getTypedParameter(this.gl2.MAX_SERVER_WAIT_TIMEOUT,"number")
    }
    public getMaxTextureLODBias(): GLfloat
    {
        return this.getTypedParameter(this.gl2.MAX_TEXTURE_LOD_BIAS,"number")
    }
    public getMaxTransformFeedbackInterleavedComponents(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS,"number")
    }
    public getMaxTransformFeedbackSeperateAttributes(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS,"number")
    }
    public getMaxTransformFeedbackSeperateComponents(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS,"number")
    }
    public getMaxUniformBlockSize(): GLint64
    {
        return this.getTypedParameter(this.gl2.MAX_UNIFORM_BLOCK_SIZE,"number")
    }
    public getMaxUniformBufferBindings(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_UNIFORM_BUFFER_BINDINGS,"number")
    }
    public getMaxVaryingComponents(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_VARYING_COMPONENTS,"number")
    }
    public getMaxVertexOutputComponents(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_VERTEX_OUTPUT_COMPONENTS,"number")
    }
    public getMaxVertexUniformBlocks(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_VERTEX_UNIFORM_BLOCKS,"number")
    }
    public getMaxVertexUniformComponents(): GLint
    {
        return this.getTypedParameter(this.gl2.MAX_VERTEX_UNIFORM_COMPONENTS,"number")
    }
    public getMinProgramTexelOffset(): GLint
    {
        return this.getTypedParameter(this.gl2.MIN_PROGRAM_TEXEL_OFFSET,"number")
    }
    public getPackRowLength(): GLint
    {
        return this.getTypedParameter(this.gl2.PACK_ROW_LENGTH,"number")
    }
    public getPackSkipPixels(): GLint
    {
        return this.getTypedParameter(this.gl2.PACK_SKIP_PIXELS,"number")
    }
    public getPackSkipRows(): GLint
    {
        return this.getTypedParameter(this.gl2.PACK_SKIP_ROWS,"number")
    }
    public getPixelPackBufferBinding(): WebGLBuffer | undefined
    {
        return this.getObjectParameter(this.gl2.PIXEL_PACK_BUFFER_BINDING,WebGLBuffer)
    }
    public getPixelUnpackBufferBinding(): WebGLBuffer | undefined
    {
        return this.getObjectParameter(this.gl2.PIXEL_UNPACK_BUFFER_BINDING,WebGLBuffer)
    }
    public getRasterizerDiscard(): GLboolean
    {
        return this.getTypedParameter(this.gl2.RASTERIZER_DISCARD,"boolean")
    }
    public getReadBuffer(): GLenum
    {
        return this.getTypedParameter(this.gl2.READ_BUFFER,"number")
    }
    public getReadFramebufferBinding(): WebGLFramebuffer | undefined
    {
        return this.getObjectParameter(this.gl2.READ_FRAMEBUFFER_BINDING,WebGLFramebuffer)
    }
    public getSampleAlphaToCoverage(): GLboolean
    {
        return this.getTypedParameter(this.gl2.SAMPLE_ALPHA_TO_COVERAGE,"boolean")
    }
    public getSampleCoverage(): GLboolean
    {
        return this.getTypedParameter(this.gl2.SAMPLE_COVERAGE,"boolean")
    }
    public getSamplerBinding(): WebGLSampler | undefined
    {
        return this.getObjectParameter(this.gl2.SAMPLER_BINDING,WebGLSampler)
    }
    public getTextureBinding2DArray(): WebGLTexture | undefined
    {
        return this.getObjectParameter(this.gl2.TEXTURE_BINDING_2D_ARRAY,WebGLTexture)
    }
    public getTextureBinding3D(): WebGLTexture | undefined
    {
        return this.getObjectParameter(this.gl2.TEXTURE_BINDING_3D,WebGLTexture)
    }
    public getTransformFeedbackActive(): GLboolean
    {
        return this.getTypedParameter(this.gl2.TRANSFORM_FEEDBACK_ACTIVE,"boolean")
    }
    public getTransformFeedbackBufferBinding(): WebGLBuffer | undefined
    {
        return this.getObjectParameter(this.gl2.TRANSFORM_FEEDBACK_BINDING,WebGLBuffer)
    }
    public getTransformFeedbackPaused(): GLboolean
    {
        return this.getTypedParameter(this.gl2.TRANSFORM_FEEDBACK_PAUSED,"boolean")
    }
    public getUniformBufferBinding(): WebGLBuffer | undefined
    {
        return this.getObjectParameter(this.gl2.UNIFORM_BUFFER_BINDING,WebGLBuffer)
    }
    public getUniformBufferOffsetAlignment(): GLint
    {
        return this.getTypedParameter(this.gl2.UNIFORM_BUFFER_OFFSET_ALIGNMENT,"number")
    }
    public getUnpackImageHeight(): GLint
    {
        return this.getTypedParameter(this.gl2.UNPACK_IMAGE_HEIGHT,"number")
    }
    public getUnpackRowLength(): GLint
    {
        return this.getTypedParameter(this.gl2.UNPACK_ROW_LENGTH,"number")
    }
    public getUnpackSkipImages(): GLint
    {
        return this.getTypedParameter(this.gl2.UNPACK_SKIP_IMAGES,"number")
    }
    public getUnpackSkipPixels(): GLint
    {
        return this.getTypedParameter(this.gl2.UNPACK_SKIP_PIXELS,"number")
    }
    public getUnpackSkipRows(): GLint
    {
        return this.getTypedParameter(this.gl2.UNPACK_SKIP_ROWS,"number")
    }
    public getVertexArrayBinding(): WebGLVertexArrayObject | undefined
    {
        return this.getObjectParameter(this.gl2.VERTEX_ARRAY_BINDING,WebGLVertexArrayObject)
    }
    public getMaxTextureMaxAnisotropyExtension(): GLfloat
    {
        return this.getTypedParameter(this.getExtension("EXT_texture_filter_anisotropic").MAX_TEXTURE_MAX_ANISOTROPY_EXT,"number")
    }
    public getFragmentShaderDerivativeHintOES(): GLenum
    {
        return this.getTypedParameter(this.getExtension("OES_standard_derivatives").FRAGMENT_SHADER_DERIVATIVE_HINT_OES,"number")
    }
    public getMaxColorAttachmentsWEBGL(): GLint
    {
        return this.getTypedParameter(this.getExtension("WEBGL_draw_buffers").MAX_COLOR_ATTACHMENTS_WEBGL,"number")
    }
    public getMaxDrawBuffersWEBGL(): GLint
    {
        return this.getTypedParameter(this.getExtension("WEBGL_draw_buffers").MAX_DRAW_BUFFERS_WEBGL,"number")
    }
    public getDrawBufferWEBGL(i: number): GLenum
    {
        return this.getTypedParameter(this.getExtension("WEBGL_draw_buffers")[`DRAW_BUFFER${requiredReference(i,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15)}_WEBGL`],"number")
    }
    public getVertexArrayBindingOES(): WebGLVertexArrayObjectOES
    {
        const object = this.getParameter(this.getExtension("OES_vertex_array_object").VERTEX_ARRAY_BINDING_OES)
        // TODO: remove the as cast
        return object as WebGLVertexArrayObjectOES
    }
    public getTimestampExtension(): GLuint64EXT
    {
        return this.getTypedParameter(this.getExtension("EXT_disjoint_timer_query").TIMESTAMP_EXT,"number")
    }
    public getGPUDisjointExtension(): GLboolean
    {
        return this.getTypedParameter(this.getExtension("EXT_disjoint_timer_query").GPU_DISJOINT_EXT,"boolean")
    }
    public getMaxViewsOVR(): GLint
    {
        return this.getTypedParameter(this.getExtension("OVR_multiview2").MAX_VIEWS_OVR,"number")
    }
}

export default OpenGLParameters