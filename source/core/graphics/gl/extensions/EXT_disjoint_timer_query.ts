export type GLuint64EXT = number

interface EXT_disjoint_timer_query
{
    readonly QUERY_COUNTER_BITS_EXT: GLenum
    readonly CURRENT_QUERY_BIT: GLenum
    readonly QUERY_RESULT_EXT: GLenum
    readonly QUERY_RESULT_AVAILABLE_EXT: GLenum
    readonly TIME_ELAPSED_EXT: GLenum
    readonly TIMESTAMP_EXT: GLenum
    readonly GPU_DISJOINT_EXT: GLenum
    createQueryEXT(): WebGLQuery
    deleteQueryEXT(query: WebGLQuery): void
    isQueryEXT(query: unknown): query is WebGLQuery
    beginQueryEXT(target: GLenum,query: WebGLQuery): void
    endQueryEXT(target: GLenum): void
    queryCounterEXT(query: WebGLQuery,target: GLenum): void
    getQueryEXT(target: GLenum,pname: GLenum): unknown
    getQueryObjectEXT(query: WebGLQuery,pname: GLenum): unknown
}

export default EXT_disjoint_timer_query