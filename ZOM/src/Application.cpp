#include "Application.h"

namespace ZOM {
	ZOMGameEngine::ZOMGameEngine():
		m_Running(false)
	{
		Log::init();
	}

	void ZOMGameEngine::run()
	{
		m_Running = true;

		while (m_Running)
		{

		}
	}

	void ZOMGameEngine::close()
	{
		m_Running = false;
	}

	ZOMGameEngine::~ZOMGameEngine()
	{
	}
}

