#pragma once

#include "Window.h"

#include "events/Event.h"
#include "events/EventQueue.h"
#include "events/MouseEvents.h"
#include "events/KeyEvents.h"
#include "events/WindowEvents.h"

#include "layers/LayerManager.h"

namespace ZOM {
	class ZOM_API ZOMGameEngine {
	public:
		ZOMGameEngine();
		virtual ~ZOMGameEngine();

		void run();

	protected:
		void addLayer(Layer* layer);
		void close();

	private:
		void onFrame();


	private:
		bool m_Running;
		Window* m_Window;

		/*
			Stores all layers, and all events
		*/
		EventQueue m_EventQueue;
		LayerManager m_LayerManager;
	};
}