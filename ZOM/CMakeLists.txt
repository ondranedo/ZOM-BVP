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
endif(UNIX) 

if(APPLE)
	add_compile_definitions(ZOM_MACOS)
endif(UNIX)

###################################
#          source files           #
###################################


# target
add_library(ZOM STATIC
"src/Application.cpp"
"src/Application.h"
"src/Logger.cpp"
"src/Logger.h"
"src/Core.h"
"src/Logger.h"
"src/pch.h"
"src/Entrypoint.cpp"
"src/events/Event.h"
"src/events/WindowEvents.h"
"src/events/KeyEvents.h"
"src/events/MouseEvents.h"
"src/Window.h"
"src/platform/Windows/WWindow.h"
"src/platform/Windows/WWindows.cpp")

# precimpiled headers
target_precompile_headers(ZOM PUBLIC
	"src/Core.h"
	"src/Logger.h"
	"src/pch.h"
	"src/events/Event.h"
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

# projects
add_subdirectory("vendor/spdlog")
add_subdirectory("vendor/glfw")

# vendor links
target_link_libraries(ZOM "spdlog")
target_link_libraries(ZOM "glfw")

# include dirs
target_include_directories(ZOM PUBLIC
"${CMAKE_SOURCE_DIR}/ZOM/vendor/spdlog/include"
"${CMAKE_SOURCE_DIR}/ZOM/vendor/glfw/include"
)

# install
install(TARGETS spdlog)
install(TARGETS glfw)

###################################
#        install scripts          #
###################################
install(TARGETS ZOM)


