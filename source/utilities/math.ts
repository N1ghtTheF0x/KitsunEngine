import * as math from "@ntf/math"

(function()
{
    for(const [key,value] of Object.entries(math))
    {
        Object.defineProperty(Math,key,{value: value})
    }
})()