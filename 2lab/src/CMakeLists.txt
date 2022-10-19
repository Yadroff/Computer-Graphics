cmake_minimum_required(VERSION 3.21)
project(2lab)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML COMPONENTS system graphics REQUIRED)
set(CLASSES
        RightPyramid.h
        RightPyramid.cpp GlobalSystem.cpp GlobalSystem.h Object.cpp Object.h Figure.h Math.cpp Math.h RightTruncatedPyramid.cpp RightTruncatedPyramid.h)
add_executable(2lab main.cpp ${CLASSES})
target_link_libraries(2lab sfml-graphics sfml-system)