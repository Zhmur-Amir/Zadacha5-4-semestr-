cmake_minimum_required(VERSION 3.1)

project(CLntN)

include_directories(${PROJECT_SOURCE_DIR})

set (ClntN_SRC  main.cpp auto.cpp func.cpp CObject.cpp CPlane.cpp CVect.cpp Light.cpp Reader.cpp)
set (ClntN_HDR CObject.h CPlane.h CVect.h Light.h wh.h factory.h)

add_executable (${PROJECT_NAME} ${ClntN_SRC} ${ClntN_HDR})