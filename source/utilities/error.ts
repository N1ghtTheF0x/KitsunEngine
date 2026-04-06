export class AlertError extends Error
{
    public constructor(message?: string,options?: ErrorOptions)
    {
        super(message,options)
        alert(message)
    }
}

export const resolveUnknownError = (error: unknown) => Error.isError(error) ? error : new Error(String(error))