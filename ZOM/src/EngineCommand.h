#pragma once

#include "Engine.h"

/*
	Controls whole engine
*/
namespace ZOM {
	class ZOM_API EngineCommand {
	public:
		static void create();
		static void run();
		static void terminate();
		static void close();

	private:
		static ZOMGameEngine* s_Engine;
		static bool s_Created;
	};
};