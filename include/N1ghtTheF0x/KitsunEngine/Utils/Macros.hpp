#ifndef __N1GHTTHEF0X_KITSUNENGINE_UTILS_MACROS_HPP
#define __N1GHTTHEF0X_KITSUNENGINE_UTILS_MACROS_HPP

#include <memory>

#define KITSUNENGINE_CLASS(type) \
class type; \
typedef const type Const##type; \
typedef std::shared_ptr<type> Ptr##type;

#endif