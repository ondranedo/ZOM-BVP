#include <ZOM/ZOM.hpp>

#include "GameLayer.h"

class Game : public ZOM::ZOMGameEngine {
public:
	Game()
	{
		addLayer(m_GameLayer = new GameLayer("Game layer"));
	}
	~Game()
	{

	}
private:
	GameLayer* m_GameLayer;
};

ZOM_CREATE_GAME(Game);