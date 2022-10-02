// PCH
#pragma once

#define ZOM_API 

#define ZOM_BIND_CLASS_FUNC(x) std::bind(&x,this,std::placeholders::_1)

// Client logger

#include "logger.h"

#ifdef ZOM_DEBUG
#define ZOM_CLIENT_TRACE(...)		ZOM::Log::getClient()->trace(__VA_ARGS__)
#define ZOM_CLIENT_INFO(...)		ZOM::Log::getClient()->info(__VA_ARGS__)
#define ZOM_CLIENT_WARNING(...)		ZOM::Log::getClient()->warn(__VA_ARGS__)
#define ZOM_CLIENT_ERROR(...)		ZOM::Log::getClient()->error(__VA_ARGS__)
#define ZOM_CLIENT_CRITICAL(...)	ZOM::Log::getClient()->critical(__VA_ARGS__); __debugbreak()
#elif ZOM_RELEASE
#define ZOM_CLIENT_TRACE(...)		ZOM::Log::getClient()->trace(__VA_ARGS__)
#define ZOM_CLIENT_INFO(...)		ZOM::Log::getClient()->info(__VA_ARGS__)
#define ZOM_CLIENT_WARNING(...)		ZOM::Log::getClient()->warn(__VA_ARGS__)
#define ZOM_CLIENT_ERROR(...)		ZOM::Log::getClient()->error(__VA_ARGS__)
#define ZOM_CLIENT_CRITICAL(...)	ZOM::Log::getClient()->critical(__VA_ARGS__);
#elif ZOM_DISTRIBUTE
#define ZOM_CLIENT_TRACE(...)		ZOM::Log::getClient()->trace(__VA_ARGS__)
#define ZOM_CLIENT_INFO(...)		ZOM::Log::getClient()->info(__VA_ARGS__)
#define ZOM_CLIENT_WARNING(...)		ZOM::Log::getClient()->warn(__VA_ARGS__)
#define ZOM_CLIENT_ERROR(...)		ZOM::Log::getClient()->error(__VA_ARGS__)
#define ZOM_CLIENT_CRITICAL(...)	ZOM::Log::getClient()->critical(__VA_ARGS__);
#endif

// Core logger
#ifdef ZOM_DEBUG
#define ZOM_TRACE(...)		ZOM::Log::getCore()->trace(__VA_ARGS__)
#define ZOM_INFO(...)		ZOM::Log::getCore()->info(__VA_ARGS__)
#define ZOM_WARNING(...)	ZOM::Log::getCore()->warn(__VA_ARGS__)
#define ZOM_ERROR(...)		ZOM::Log::getCore()->error(__VA_ARGS__)
#define ZOM_CRITICAL(...)	ZOM::Log::getCore()->critical(__VA_ARGS__); __debugbreak()
#elif ZOM_RELEASE
#define ZOM_TRACE(...)
#define ZOM_INFO(...)
#define ZOM_WARNING(...)	ZOM::Log::getCore()->warn(__VA_ARGS__)
#define ZOM_ERROR(...)		ZOM::Log::getCore()->error(__VA_ARGS__)
#define ZOM_CRITICAL(...)	ZOM::Log::getCore()->critical(__VA_ARGS__);
#elif ZOM_DISTRIBUTE
#define ZOM_TRACE(...) 
#define ZOM_INFO(...) 
#define ZOM_WARNING(...) 
#define ZOM_ERROR(...) 
#define ZOM_CRITICAL(...) 
#endif

// ASSERTS
#ifdef ZOM_DEBUG
#define ZOM_ASSERT(x, ...) if(!(x)){ ZOM::Log::getCore()->critical(__VA_ARGS__); __debugbreak(); }
#elif ZOM_RELEASE
#define ZOM_ASSERT(x, ...) if(!(x))  ZOM::Log::getCore()->critical(__VA_ARGS__);
#elif ZOM_DISTRIBUTE
#define ZOM_ASSERT(x, ...) if(x);
#endif
