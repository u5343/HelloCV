cmake_minimum_required(VERSION 2.8)

project(OpenCVTest)

find_package(OpenCV REQUIRED)

add_executable(test0 traffictest.cpp)

target_link_libraries(test0 ${OpenCV_LIBS})