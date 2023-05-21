#include <Utils.hpp>

#include <cstring>

namespace KitsunEngine::Utils
{
    template <typename Type>
    Array<Type>::Array(Type *arr,size_t s):
        pointer(arr), size(s)
    {
        
    }
    template <typename Type>
    size_t Array<Type>::length()
    {
        return size;
    }
    template <typename Type>
    Type* Array<Type>::getValue(size_t index)
    {
        if(index >= 0 && index < size) return pointer + (index * sizeof(Type));
        else nullptr;
    }
    template <typename Type>
    void Array<Type>::setValue(size_t index,Type* value)
    {
        if(index >= 0 && index < size) memcpy(pointer + (index * sizeof(Type)),value,sizeof(value));
    }
}