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
add_library(ZOM STATIC "Application.cpp" "Application.h" "Core.h" )

# precimpiled headers
target_precompile_headers(ZOM PUBLIC
	"Core.h"
)

###################################
#          include dirs           #
###################################

target_include_directories(ZOM PUBLIC
"${CMAKE_SOURCE_DIR}/ZOM/src"
)

###################################
#        install scripts          #
###################################
install(TARGETS ZOM DESTINATION "${CMAKE_SOURCE_DIR}/out/install/lib")


