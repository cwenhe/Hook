cmake_minimum_required(VERSION 3.0)

project(QtHook)
set(__ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB_RECURSE __UI_FILES "${__ROOT}/*.ui")
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} __CPPFILES)
find_package(Qt5Widgets  5.11.2 CONFIG REQUIRED)
add_executable(${PROJECT_NAME} WIN32 ${__CPPFILES} ${__UI_FILES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
set_property(TARGET ${PROJECT_NAME} PROPERTY DEBUG_POSTFIX d)