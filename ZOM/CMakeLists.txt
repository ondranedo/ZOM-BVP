# Engine's build file

###################################
#       compile definitions       #
###################################

if(WIN32)
	add_compile_definitions(
		ZOM_PLATFORM_WINDOWS
	)
endif(WIN32)
	
if(UNIX AND NOT APPLE)
	add_compile_definitions(
		ZOM_PLATFORM_LINUX
	)
endif(UNIX)

if(APPLE)
	add_compile_definitions(
		ZOM_PLATFORM_MACOS
	)
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


