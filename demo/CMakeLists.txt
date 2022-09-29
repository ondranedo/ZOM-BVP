# game's build file
add_executable(demo "demo.cpp" )

target_include_directories(demo PUBLIC
"${CMAKE_SOURCE_DIR}/ZOM/include"
)

# references to other projects
target_link_libraries(demo "ZOM")

# install script
install(TARGETS demo DESTINATION "${CMAKE_SOURCE_DIR}/out/install/bin")
