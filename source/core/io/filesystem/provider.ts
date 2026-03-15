export interface IReadonlyFileSystemProvider
{
    readFile(filepath: string): Promise<ArrayBuffer>
}

export interface IWriteOnlyFileSystemProvider
{
    writeFile(filepath: string,data: ArrayBuffer): Promise<void>
}

type FileSystemProvider = IReadonlyFileSystemProvider & IWriteOnlyFileSystemProvider

export default FileSystemProvider