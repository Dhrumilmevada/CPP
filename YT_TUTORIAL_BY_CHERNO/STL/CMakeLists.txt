cmake_minimum_required(VERSION 3.0)

#it won't allow to build project in source directory
if("${CMAKE_BINARY_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
    message(FATAL_ERROR "FATAL: In-source builds are not allowed.
    You should create a separate directory for build files.")
endif()

#to give name to project, it will create executable with same name
project(stl)

#to generate executable in bin directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#to build project with C++14 compiler
set(CMAKE_CXX_STANDARD 14)
message("CXX Standard:" ${CMAKE_CXX_STANDARD})

#collect all source files
file(GLOB source_files "${CMAKE_SOURCE_DIR}/*.cpp")

#create executable named as "hello"
add_executable(stl ${source_files})


