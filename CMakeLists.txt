# Project's build file
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(ZOM)



# Sub projects
add_subdirectory("ZOM")
add_subdirectory("demo")

# Vendor projects
# ...