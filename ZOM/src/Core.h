#pragma once

#define ZOM_API 

#define ZOM_BIND_CLASS_FUNC(x) std::bind(&x,this,std::placeholders::_1)


#include "Profiling.h"
#define ZOM_FUNCTION_TIMER() ZOM::MeasureTime __FUNC__(__PRETTY_FUNCTION__)

// Client logger

#include "logger.h"

#ifdef ZOM_DEBUG
#define ZOM_CLIENT_TRACE(...)		ZOM::Logger::getClient()->trace(__VA_ARGS__)
#define ZOM_CLIENT_INFO(...)		ZOM::Logger::getClient()->info(__VA_ARGS__)
#define ZOM_CLIENT_WARNING(...)		ZOM::Logger::getClient()->warn(__VA_ARGS__)
#define ZOM_CLIENT_ERROR(...)		ZOM::Logger::getClient()->error(__VA_ARGS__)
#define ZOM_CLIENT_CRITICAL(...)	ZOM::Logger::getClient()->critical(__VA_ARGS__); __debugbreak()
#elif ZOM_RELEASE
#define ZOM_CLIENT_TRACE(...)		ZOM::Logger::getClient()->trace(__VA_ARGS__)
#define ZOM_CLIENT_INFO(...)		ZOM::Logger::getClient()->info(__VA_ARGS__)
#define ZOM_CLIENT_WARNING(...)		ZOM::Logger::getClient()->warn(__VA_ARGS__)
#define ZOM_CLIENT_ERROR(...)		ZOM::Logger::getClient()->error(__VA_ARGS__)
#define ZOM_CLIENT_CRITICAL(...)	ZOM::Logger::getClient()->critical(__VA_ARGS__);
#elif ZOM_DISTRIBUTE
#define ZOM_CLIENT_TRACE(...)		ZOM::Logger::getClient()->trace(__VA_ARGS__)
#define ZOM_CLIENT_INFO(...)		ZOM::Logger::getClient()->info(__VA_ARGS__)
#define ZOM_CLIENT_WARNING(...)		ZOM::Logger::getClient()->warn(__VA_ARGS__)
#define ZOM_CLIENT_ERROR(...)		ZOM::Logger::getClient()->error(__VA_ARGS__)
#define ZOM_CLIENT_CRITICAL(...)	ZOM::Logger::getClient()->critical(__VA_ARGS__);
#endif

// Core logger
#ifdef ZOM_DEBUG
#define ZOM_TRACE(...)		ZOM::Logger::getCore()->trace(__VA_ARGS__)
#define ZOM_INFO(...)		ZOM::Logger::getCore()->info(__VA_ARGS__)
#define ZOM_WARNING(...)	ZOM::Logger::getCore()->warn(__VA_ARGS__)
#define ZOM_ERROR(...)		ZOM::Logger::getCore()->error(__VA_ARGS__)
#define ZOM_CRITICAL(...)	ZOM::Logger::getCore()->critical(__VA_ARGS__); __debugbreak()
#elif ZOM_RELEASE
#define ZOM_TRACE(...)			
#define ZOM_INFO(...)			
#define ZOM_WARNING(...)	ZOM::Logger::getCore()->warn(__VA_ARGS__)
#define ZOM_ERROR(...)		ZOM::Logger::getCore()->error(__VA_ARGS__)
#define ZOM_CRITICAL(...)	ZOM::Logger::getCore()->critical(__VA_ARGS__);
#elif ZOM_DISTRIBUTE
#define ZOM_TRACE(...) 
#define ZOM_INFO(...) 
#define ZOM_WARNING(...) 
#define ZOM_ERROR(...) 
#define ZOM_CRITICAL(...) 
#endif

// ASSERTS
#ifdef ZOM_DEBUG
#define ZOM_ASSERT(x, ...) if(!(x)){ ZOM::Logger::getCore()->critical(__VA_ARGS__); __debugbreak(); }
#elif ZOM_RELEASE
#define ZOM_ASSERT(x, ...) if(!(x))  ZOM::Logger::getCore()->critical(__VA_ARGS__);
#elif ZOM_DISTRIBUTE
#define ZOM_ASSERT(x, ...) if(x);
#endif
