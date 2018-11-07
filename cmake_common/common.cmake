include_guard()
include(common_function)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
## compile flag
if(WIN32)
    set(CMAKE_CXX_FLAGS_RELEASE "/Zi /nologo /W3 /WX- /MP /O2 /D \"WIN32\" /D \"_CONSOLE\" /Gm- /EHa /MD /GS /fp:precise /Zc:wchar_t /Zc:forScope /openmp /Fp\"x64\\Release\\rostering.pch\" /Fa\"x64\\Release\" /Fo\"x64\\Release\" /Fd\"x64\\Release\\vc100.pdb\" /Gd /errorReport:queue" )
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zi /nologo /W3 /WX- /MP /Od /D \"WIN32\" /D \"_DEBUG\" /D \"_CONSOLE\" /Gm- /EHa /RTC1 /MDd /GS /fp:precise /Zc:wchar_t /Zc:forScope /openmp /Fp\"x64\\Debug\\rostering.pch\" /Fa\"x64\\Debug\" /Fo\"x64\\Debug\" /Fd\"x64\\Debug\\vc100.pdb\" /Gd /errorReport:queue" )
    set(CMAKE_DEBUG_POSTFIX "d")

else()
    set(CMAKE_CXX_FLAGS "-std=c++0x -Wno-deprecated-declarations -g -O3 -Wall  -fopenmp -Werror=return-type -std=c++0x")
endif()

if(WIN32)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

else(WIN32)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif(WIN32)

#set_runfile_path(${CMAKE_BINARY_DIR}/bin)
#set_archive_path(${CMAKE_BINARY_DIR}/lib)
