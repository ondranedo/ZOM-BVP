# game's build file
add_executable(demo "src/demo.cpp"  "src/GameLayer.cpp" "src/GameLayer.h" "src/trinagle.h" "src/square.h")

target_include_directories(demo PUBLIC
"${CMAKE_SOURCE_DIR}/ZOM/include"
)

# references to other projects
target_link_libraries(demo "ZOM")

# install script
install(TARGETS demo DESTINATION ${CMAKE_INSTALL_PREFIX})
