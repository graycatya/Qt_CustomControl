﻿cmake_minimum_required(VERSION 3.10)

project(Cat_Animation LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Lib)

file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")

aux_source_directory(. DIR_LIB_SRCS)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
message(${DIR_LIB_SRCS})
#add_library(Cat_Animation SHARED ${DIR_LIB_SRCS})
add_library(Cat_Animation STATIC ${DIR_LIB_SRCS})

#SET_TARGET_PROPERTIES(Cat_Animation_Static PROPERTIES OUTPUT_NAME "Cat_Animation")
SET_TARGET_PROPERTIES(Cat_Animation PROPERTIES VERSION 1.0.0.0 SOVERSION 1)
#SET_TARGET_PROPERTIES(Cat_Animation_Static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

target_link_libraries(Cat_Animation PRIVATE Qt5::Core)
target_link_libraries(Cat_Animation PRIVATE Qt5::Gui)
target_link_libraries(Cat_Animation PRIVATE Qt5::Widgets)
