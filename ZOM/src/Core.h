// PCH
#pragma once

#define ZOM_API 

#define ZOM_BIND_CLASS_FUNC(x) std::bind(&x,this,std::placeholders::_1)

// ASSERTS
#ifdef ZOM_DEBUG
    #define ZOM_ASSERT(x, ...) if(!(x)){ ZOM::Log::getCore()->critical(__VA_ARGS__); __debugbreak(); }
#elif ZOM_RELEASE
    #define ZOM_ASSERT(x, ...) if(!(x))  ZOM::Log::getCore()->critical(__VA_ARGS__);
#elif ZOM_DISTRIBUTE
    #define ZOM_ASSERT(x, ...) (x)
#endif

