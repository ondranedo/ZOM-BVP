# Engine's build file

###################################
#       compile definitions       #
###################################

# build
if(CMAKE_BUILD_TYPE  STREQUAL "Debug")
	add_compile_definitions(ZOM_DEBUG)
endif(CMAKE_BUILD_TYPE  STREQUAL "Debug")

if(CMAKE_BUILD_TYPE  STREQUAL "RelWithDebInfo")
	add_compile_definitions(ZOM_RELEASE)
endif(CMAKE_BUILD_TYPE  STREQUAL "RelWithDebInfo")

if(CMAKE_BUILD_TYPE  STREQUAL "MinSizeRel")
	add_compile_definitions(ZOM_DISTRIBUTE)
endif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")

# platforms
if(WIN32)
	add_compile_definitions(ZOM_WINDOWS)
endif(WIN32)

if(UNIX AND NOT APPLE)
	add_compile_definitions(ZOM_LINUX)
endif(UNIX AND NOT APPLE) 

if(APPLE)
	add_compile_definitions(ZOM_MACOS)
endif(APPLE)

###################################
#          source files           #
###################################


# target
add_library(ZOM STATIC
"src/Config.cpp"
"src/Config.h"
"src/Core.h"
"src/Engine.cpp"
"src/Engine.h"
"src/EngineGame.cpp"
"src/EngineGame.h" 
"src/Entrypoint.cpp"
"src/Input.h"
"src/Input.cpp"
"src/Logger.cpp"
"src/Logger.h"
"src/pch.h"
"src/Profiling.cpp"
"src/Profiling.h"

"src/window/MainWindow.cpp"
"src/window/MainWindow.h"
"src/window/Window.h"

"src/events/Event.h"
"src/events/EventQueue.cpp"
"src/events/EventQueue.h"
"src/events/KeyEvents.h"
"src/events/MouseEvents.h"
"src/events/WindowEvents.h"

"src/platform/Windows/WInput.cpp"
"src/platform/Windows/WInput.h"
"src/platform/Windows/WWindow.h"
"src/platform/Windows/WWindows.cpp"

"src/codes/DataType.cpp"
"src/codes/DataType.h"
"src/codes/Keycodes.cpp"
"src/codes/Keycodes.h"
"src/codes/Mousecodes.cpp"
"src/codes/Mousecodes.h"
"src/codes/ComplexDataType.h" 
"src/codes/ComplexDataType.cpp"

"src/layers/Layer.h"
"src/layers/LayerManager.cpp"
"src/layers/LayerManager.h"

"src/renderer/buffers/IndexBuffer.cpp"
"src/renderer/buffers/IndexBuffer.h"
"src/renderer/buffers/VertexBuffer.cpp"
"src/renderer/buffers/VertexBuffer.h"
"src/renderer/buffers/VertexBufferLayout.cpp"
"src/renderer/buffers/VertexBufferLayout.h"
"src/renderer/Mesh.cpp"
"src/renderer/Mesh.h"
"src/renderer/RenderApplication.h" 
"src/renderer/RenderContext.h" 
"src/renderer/Renderer.cpp"
"src/renderer/Renderer.h"
"src/renderer/Shader.cpp"
"src/renderer/Shader.h"
"src/renderer/ShaderManager.cpp" 
"src/renderer/ShaderManager.h"
"src/renderer/VertexArray.cpp" 
"src/renderer/VertexArray.h" 

"src/renderingAPI/opengl/OpenGLCodes.cpp"
"src/renderingAPI/opengl/OpenGLCodes.h"
"src/renderingAPI/opengl/OpenGLCore.h"

"src/renderingAPI/opengl/buffers/OpenGLVertexBuffer.cpp"
"src/renderingAPI/opengl/buffers/OpenGLVertexBuffer.h"
"src/renderingAPI/opengl/buffers/OpenGLIndexBuffer.cpp"
"src/renderingAPI/opengl/buffers/OpenGLIndexBuffer.h"

"src/renderer/scene/Camera.h" 
"src/renderer/scene/Camera.cpp" 
"src/renderer/scene/CameraMovement.h"
"src/renderer/scene/OrthographicCamera.h" 
"src/renderer/scene/OrthographicCamera.cpp"

"src/renderingAPI/opengl/OpenGLMesh.cpp"
"src/renderingAPI/opengl/OpenGLMesh.h"
"src/renderingAPI/opengl/OpenGLRenderApplication.cpp"
"src/renderingAPI/opengl/OpenGLRenderApplication.h"
"src/renderingAPI/opengl/OpenGLRenderContext.cpp"
"src/renderingAPI/opengl/OpenGLRenderContext.h"
"src/renderingAPI/opengl/OpenGLShader.cpp"
"src/renderingAPI/opengl/OpenGLShader.h"
"src/renderingAPI/opengl/OpenGLVertexArray.cpp" 
"src/renderingAPI/opengl/OpenGlVertexArray.h"
)


# precompiled headers
target_precompile_headers(ZOM PUBLIC
	"src/pch.h"
	"src/Core.h"
	"src/events/Event.h"
	"src/renderer/renderer.h"
	"src/codes/DataType.h"
	"src/codes/ComplexDataType.h"
	"src/renderingAPI/opengl/OpenGLCore.h"
	"src/config.h"
	"src/Profiling.h"
)

###################################
#          include dirs           #
###################################

target_include_directories(ZOM PUBLIC
"${CMAKE_SOURCE_DIR}/ZOM/src"
)

###################################
#         Vendor projects         #
###################################

# settings
set(SPDLOG_BUILD_EXAMPLE OFF)
set(GLFW_INSTALL OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(JSONCPP_WITH_TESTS OFF)
set(BUILD_STATIC_LIBS ON)
set(JSONCPP_WITH_PKGCONFIG_SUPPORT OFF)
set(JSONCPP_WITH_CMAKE_PACKAGE OFF)
set(JSONCPP_WITH_TESTS OFF)

# projects
add_subdirectory("vendor/spdlog")
add_subdirectory("vendor/glfw")
add_subdirectory("vendor/glad/gl_4.0_core_debug")
add_subdirectory("vendor/jsoncpp")

# vendor links
target_link_libraries(ZOM "spdlog")
target_link_libraries(ZOM "glfw")
target_link_libraries(ZOM "glad")
target_link_libraries(ZOM "jsoncpp_static")

# include dirs
target_include_directories(ZOM PUBLIC
"${CMAKE_SOURCE_DIR}/ZOM/vendor/spdlog/include"
"${CMAKE_SOURCE_DIR}/ZOM/vendor/glfw/include"
"${CMAKE_SOURCE_DIR}/ZOM/vendor/glad/gl_4.0_core_debug/include"
"${CMAKE_SOURCE_DIR}/ZOM/vendor/glm/"
"${CMAKE_SOURCE_DIR}/ZOM/vendor/jsoncpp/include"
)

# install
install(TARGETS spdlog DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(TARGETS glfw DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(TARGETS jsoncpp_static DESTINATION  ${CMAKE_INSTALL_PREFIX}/lib)
install(TARGETS glad DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

###################################
#        install scripts          #
###################################

install(TARGETS ZOM DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

# pre build
install(CODE "execute_process(COMMAND 
		        ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/ZOM/config.json
                ${CMAKE_INSTALL_PREFIX}/config.json)")

install(CODE "execute_process(COMMAND 
		        ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/ZOM/resources
                ${CMAKE_INSTALL_PREFIX}/resources)")