// PCH
#pragma once

#define ZOM_API 

// ASSERTS
#ifdef ZOM_DEBUG
    #define ZOM_ASSERT(x, ...) if(!(x)){ ZOM::Log::getCore()->critical(__VA_ARGS__); __debugbreak(); }
#elif ZOM_RELEASE
    #define ZOM_ASSERT(x, ...) if(!(x))  ZOM::Log::getCore()->critical(__VA_ARGS__);
#elif ZOM_DISTRIBUTE
    #define ZOM_ASSERT(x, ...) (x)
#endif

