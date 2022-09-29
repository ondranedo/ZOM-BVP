#pragma once

#include "spdlog/spdlog.h"

namespace ZOM {
	using logPtr = std::shared_ptr<spdlog::logger>;

	class ZOM_API Log {
	public:
		static bool init();
		inline static const logPtr& getCore() { return s_Core; }
		inline static const logPtr& getClient() { return s_Client; }

	private:
		static logPtr s_Core;
		static logPtr s_Client;
	};
}

// Client logger
#ifdef ZOM_DEBUG
	#define ZOM_CLIENT_TRACE(...)		Log::getClient()->trace(__VA_ARGS__)
	#define ZOM_CLIENT_INFO(...)		Log::getClient()->info(__VA_ARGS__)
	#define ZOM_CLIENT_WARNING(...)		Log::getClient()->warn(__VA_ARGS__)
	#define ZOM_CLIENT_ERROR(...)		Log::getClient()->error(__VA_ARGS__)
	#define ZOM_CLIENT_CRITICAL(...)	Log::getClient()->critical(__VA_ARGS__); __debugbreak()
#elif ZOM_RELEASE
	#define ZOM_CLIENT_TRACE(...)		Log::getClient()->trace(__VA_ARGS__)
	#define ZOM_CLIENT_INFO(...)		Log::getClient()->info(__VA_ARGS__)
	#define ZOM_CLIENT_WARNING(...)		Log::getClient()->warn(__VA_ARGS__)
	#define ZOM_CLIENT_ERROR(...)		Log::getClient()->error(__VA_ARGS__)
	#define ZOM_CLIENT_CRITICAL(...)	Log::getClient()->critical(__VA_ARGS__);
#elif ZOM_DISTRIBUTE
	#define ZOM_CLIENT_TRACE(...)		Log::getClient()->trace(__VA_ARGS__)
	#define ZOM_CLIENT_INFO(...)		Log::getClient()->info(__VA_ARGS__)
	#define ZOM_CLIENT_WARNING(...)		Log::getClient()->warn(__VA_ARGS__)
	#define ZOM_CLIENT_ERROR(...)		Log::getClient()->error(__VA_ARGS__)
	#define ZOM_CLIENT_CRITICAL(...)	Log::getClient()->critical(__VA_ARGS__);
#endif

// Core logger
#ifdef ZOM_DEBUG
	#define ZOM_TRACE(...)		Log::getCore()->trace(__VA_ARGS__)
	#define ZOM_INFO(...)		Log::getCore()->info(__VA_ARGS__)
	#define ZOM_WARNING(...)	Log::getCore()->warn(__VA_ARGS__)
	#define ZOM_ERROR(...)		Log::getCore()->error(__VA_ARGS__)
	#define ZOM_CRITICAL(...)	Log::getCore()->critical(__VA_ARGS__); __debugbreak()
#elif ZOM_RELEASE
	#define ZOM_TRACE(...)		Log::getCore()->trace(__VA_ARGS__)
	#define ZOM_INFO(...)		Log::getCore()->info(__VA_ARGS__)
	#define ZOM_WARNING(...)	Log::getCore()->warn(__VA_ARGS__)
	#define ZOM_ERROR(...)		Log::getCore()->error(__VA_ARGS__)
	#define ZOM_CRITICAL(...)	Log::getCore()->critical(__VA_ARGS__);
#elif ZOM_DISTRIBUTE
	#define ZOM_TRACE(...) 
	#define ZOM_INFO(...) 
	#define ZOM_WARNING(...) 
	#define ZOM_ERROR(...) 
	#define ZOM_CRITICAL(...) 
#endif