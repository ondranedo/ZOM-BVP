/*
	ZOM engine by: https://www.github.com/ondranedo/
				   https://www.github.com/Sutiama/
				   https://www.github.com/Karnatour/
	
	License: https://github.com/ondranedo/ZOM/blob/main/LICENSE
*/

////////////////////////////
//     Header files       //
////////////////////////////
#include "./../../src/Application.h"
#include "./../../src/layers/Layer.h"

#include "./../../src/events/Event.h"
#include "./../../src/events/MouseEvents.h"
#include "./../../src/events/KeyEvents.h"
#include "./../../src/events/WindowEvents.h"

#include "./../../src/Logger.h"

#include "./../../src/codes/Keycodes.h"
#include "./../../src/codes/Mousecodes.h"

////////////////////////////
//      Game creation     //
////////////////////////////
#define ZOM_CREATE_GAME(x) ZOM::ZOMGameEngine* createApp() { return new x; }