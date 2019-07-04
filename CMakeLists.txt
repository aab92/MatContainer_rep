cmake_minimum_required(VERSION 2.8)
project( MatContainer )
find_package (OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( testMatClass source/testing_mat.cpp)
target_link_libraries( testMatClass  ${OpenCV_LIBS})


