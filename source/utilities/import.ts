export async function importString(content: string): Promise<unknown>
{
    const blob = new Blob([content],{type: "text/javascript"})
    const url = URL.createObjectURL(blob)
    const module = await import(url)
    URL.revokeObjectURL(url)
    return module
}