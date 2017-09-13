cmake_minimum_required(VERSION 2.8)

project(montey-hall-demo)

# enable C++11 flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# Define sources and executable
include_directories("${PROJECT_SOURCE_DIR}/includes")

file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp", "${PROJECT_SOURCE_DIR}/includes/*.h")

set(EXECUTABLE_NAME "montey-hall-demo")
add_executable(${EXECUTABLE_NAME} ${SRC_FILES})

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)