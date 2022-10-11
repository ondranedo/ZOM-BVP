/*
	ZOM engine by: https://www.github.com/ondranedo/
				   https://www.github.com/Sutiama/
				   https://www.github.com/Karnatour/
	
	License: https://github.com/ondranedo/ZOM/blob/main/LICENSE
*/

////////////////////////////
//     Header files       //
////////////////////////////
#include "./../../src/Engine.h"

#include "./../../src/layers/Layer.h"
#include "./../../src/EngineGame.h"

#include "./../../src/events/Event.h"
#include "./../../src/events/MouseEvents.h"
#include "./../../src/events/KeyEvents.h"
#include "./../../src/events/WindowEvents.h"


#include "./../../src/codes/Keycodes.h"
#include "./../../src/codes/DataType.h"
#include "./../../src/codes/ComplexDataType.h"
#include "./../../src/codes/Mousecodes.h"



#include "./../../src/renderer/renderer.h"
#include "./../../src/renderer/VertexBuffer.h"
#include "./../../src/renderer/IndexBuffer.h"
#include "./../../src/renderer/VertexBufferLayout.h"
#include "./../../src/renderer/VertexArray.h"


////////////////////////////
//      Game creation     //
////////////////////////////
#define ZOM_CREATE_GAME(x) ZOM::Game* createGame() { return new x; }


////////////////////////////
//    Logger remapping    //
////////////////////////////
#include "./../../src/Logger.h"


// Undefined
#undef ZOM_CLIENT_TRACE	
#undef ZOM_CLIENT_INFO	
#undef ZOM_CLIENT_WARNING	
#undef ZOM_CLIENT_ERROR	
#undef ZOM_CLIENT_CRITICAL

#undef ZOM_TRACE
#undef ZOM_INFO
#undef ZOM_WARNING
#undef ZOM_ERROR
#undef ZOM_CRITICAL

// redefine logger
#define ZOM_TRACE(...)		ZOM::Logger::getClient()->trace(__VA_ARGS__)
#define ZOM_INFO(...)		ZOM::Logger::getClient()->info(__VA_ARGS__)
#define ZOM_WARNING(...)	ZOM::Logger::getClient()->warn(__VA_ARGS__)
#define ZOM_ERROR(...)		ZOM::Logger::getClient()->error(__VA_ARGS__)
#define ZOM_CRITICAL(...)	ZOM::Logger::getClient()->critical(__VA_ARGS__)