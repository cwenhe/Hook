cmake_minimum_required(VERSION 3.0)

project(Hook)

set(ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${ROOT}/cmake_common)
include(common)

include_directories(${ROOT})
add_subdirectory(${ROOT}/Hook)
add_subdirectory(${ROOT}/QtHook)
