#include "EngineCommand.h";

extern ZOM::ZOMGameEngine* createApp();

namespace ZOM {
	ZOM::ZOMGameEngine* EngineCommand::s_Engine;

	bool EngineCommand::s_Created = false;

	void EngineCommand::create()
	{
		if (!s_Created)
		{
			s_Engine = createApp();
			s_Created = true;
		}
		else
			ZOM_ERROR("Can't create already created application");
	}

	void EngineCommand::run()
	{
		if (!s_Engine->isRunning())
			s_Engine->run();
		else
			ZOM_ERROR("Can't run already running application");
	}

	void EngineCommand::close()
	{
		if (s_Created)
			s_Engine->close();
		else
			ZOM_ERROR("Can't close not running application");
	}

	void EngineCommand::terminate()
	{
		if (s_Created)
			delete s_Engine;
		else
			ZOM_ERROR("Can't terminate not created application");
	}
}