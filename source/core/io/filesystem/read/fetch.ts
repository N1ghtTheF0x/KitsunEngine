import { IReadonlyFileSystemProvider } from "../provider"

const fetchReadProvider: IReadonlyFileSystemProvider = {
    async readFile(filepath)
    {
        return (await fetch(filepath)).arrayBuffer()
    }
}

export default fetchReadProvider