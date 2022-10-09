﻿#pragma once

#include "Window.h"

#include "events/Event.h"
#include "events/EventQueue.h"
#include "events/MouseEvents.h"
#include "events/KeyEvents.h"
#include "events/WindowEvents.h"

#include "layers/LayerManager.h"
#include "renderer/RendererPack.h"
#include "EngineGame.h"

namespace ZOM {
	class ZOM_API Engine {
	public:
		static void init();
		static void release();

		static void run();
		static void close();
		static bool isRunning();

		static void addLayer(Layer* layer);

	private:
	    static void onFrame();

	private:
		 static bool s_Running;
		 static Window* s_Window;
		 static Game* s_Game;
		 static EventQueue s_EventQueue;
		 static LayerManager s_LayerManager;
	};
}