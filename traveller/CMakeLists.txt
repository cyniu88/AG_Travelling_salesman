cmake_minimum_required(VERSION 2.8)
LINK_DIRECTORIES(/usr/local/lib )
project(traveller)
set(INCLUDE_DIRECTORIES "../../libs/")
include_directories(${INCLUDE_DIRECTORIES})
set(SOURCE_FILES  "main.cpp"
    "types.h"
    "ag.h"
    "ag.cpp"
    "random.hpp"
    )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -DBT_TEST -DNOSSL")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
#TARGET_LINK_LIBRARIES( ${PROJECT_NAME}  pthread gtest curl rt pthread gmock)
