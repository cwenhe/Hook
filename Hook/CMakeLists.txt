cmake_minimum_required(VERSION 3.0)

set(__ROOT ${CMAKE_CURRENT_SOURCE_DIR})
#set(CMAKE_MODULE_PATH ${__ROOT}/cmake_common)
#include(common)

project(Hook)

aux_source_directory(${__ROOT} __SOURCE_FILES)
add_library(${PROJECT_NAME} SHARED ${__SOURCE_FILES})
