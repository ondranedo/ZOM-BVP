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
	std::cout << "Window close fun" << std::endl;

	return true;
}

bool GameLayer::onKey(ZOM::KeyPressedEvent& kpe)
{
	if(kpe.getRepeatcount() == 0)
		std::cout << ZOM::ZOMKeyCodeToString(kpe.getKeyCode());

	return true;
}
