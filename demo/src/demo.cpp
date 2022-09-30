#include <ZOM/ZOM.hpp>

#include "GameLayer.h"

class Game : public ZOM::ZOMGameEngine {
public:
	Game()
	{
		addLayer(new GameLayer("Obloha"));
		addLayer(new GameLayer("Hory"));
		addLayer(new GameLayer("Pole"));
		addLayer(new GameLayer("Ruce"));
	}
	~Game()
	{

	}

};

ZOM_CREATE_GAME(Game);