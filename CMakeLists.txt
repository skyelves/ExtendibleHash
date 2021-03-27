cmake_minimum_required(VERSION 3.10)
project(ExtendibleHash)

add_subdirectory(fastalloc)
add_subdirectory(extendibleHash)

set(CMAKE_CXX_STANDARD 17)
SET(GCC_COMPILE_FLAGS "-pthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

add_executable(test test.cpp)

target_link_libraries(test extendible_hash)
