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
add_library(ZOM STATIC "src/Application.cpp" "src/Application.h" "src/Core.h" )

# precimpiled headers
target_precompile_headers(ZOM PUBLIC
	"src/Core.h"
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

# projects
add_subdirectory("vendor/spdlog")

# vendor links
target_link_libraries(ZOM "spdlog")

# install
install(TARGETS spdlog DESTINATION "${CMAKE_SOURCE_DIR}/out/install/lib")

###################################
#        install scripts          #
###################################
install(TARGETS ZOM DESTINATION "${CMAKE_SOURCE_DIR}/out/install/lib")


