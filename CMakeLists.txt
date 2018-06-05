cmake_minimum_required(VERSION 3.6)
project(SerialChain)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/ChainHandler.cpp header/ChainHandler.h src/ChainList.cpp header/ChainList.h src/ResultMsg.cpp header/ResultMsg.h main.cpp src/StudentService.cpp header/StudentService.h)
add_executable(SerialChain ${SOURCE_FILES})