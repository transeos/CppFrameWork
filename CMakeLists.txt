cmake_minimum_required(VERSION 3.2)
project(FrameWork)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-ggdb3 -DDEBUG -Wall -Wextra -Werror -Wno-unused-function")
#set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Werror -Wno-unused-function")

# 3rd party include
include_directories(3rdparty/json/single_include)
include_directories(3rdparty/cpp-driver/include)

# include
include_directories(include)

# 3rd party libary files
add_library(Catch2 INTERFACE)

# source files
file(GLOB MAIN_SRC_FILES src/*.cpp)

# link 3rd party exe directories
link_directories(3rdparty/cpp-driver/build/lib)

# create library
add_library(FrameWork SHARED ${MAIN_SRC_FILES})

# link third party libraries
target_link_libraries(FrameWork	cassandra)

# create executable
add_executable(FrameWorkMain test_main/main.cpp)
target_link_libraries(FrameWorkMain FrameWork)

# add precompiled headers
target_include_directories(Catch2 INTERFACE 3rdparty/Catch2/single_include)

# create test executable
add_executable(TestFrameWork tests/test_main.cpp)
target_link_libraries(TestFrameWork FrameWork Catch2)
