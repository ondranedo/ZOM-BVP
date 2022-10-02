#include "GameLayer.h"


void GameLayer::onUpdate()
{

}


void GameLayer::onEvent(ZOM::Event& event)
{
	ZOM::EventDispatcher d(event);

	d.dispatchEvent<ZOM::WindowCloseEvent>(ZOM_BIND_CLASS_FUNC(GameLayer::onCloseEvent));

	d.dispatchEvent<ZOM::KeyPressedEvent>(ZOM_BIND_CLASS_FUNC(GameLayer::onKey));
}

bool GameLayer::onCloseEvent(ZOM::WindowCloseEvent& wce)
{
	ZOM_WARNING("Window shloud close");

	return true;
}
	
bool GameLayer::onKey(ZOM::KeyPressedEvent& kpe)
{
	if (kpe.getRepeatcount() == 0)
	{
		ZOM_TRACE("Event: {}", ZOM::ZOMKeyCodeToString(kpe.getKeyCode()));
	}

	return true;
}
