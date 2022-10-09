#include <ZOM/ZOM.hpp>

#include "GameLayer.h"

class Demo: public ZOM::Game {
public:
	Demo()
	{
		ZOM_INFO("Game created");

		ZOM::Engine::addLayer(new GameLayer("Game layer"));
	}
	~Demo()
	{
		ZOM_INFO("Game destroyed");
	}
};

ZOM_CREATE_GAME(Demo);