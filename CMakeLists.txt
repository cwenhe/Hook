cmake_minimum_required(VERSION 3.0)

if(NOT WIN32)
    message(FATAL_ERROR "just support windows")
endif(NOT WIN32)

project(Hook)

set(ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${ROOT}/cmake_common)
include(common)

include_directories(${ROOT})
add_subdirectory(${ROOT}/Hook)
add_subdirectory(${ROOT}/QtHook)
