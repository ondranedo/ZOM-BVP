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


////////////////////////////
//      Game creation     //
////////////////////////////
#define ZOM_CREATE_GAME(x) ZOM::ZOMGameEngine* createApp() { return new x; }