cmake_minimum_required(VERSION 3.21)
project(2lab)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML COMPONENTS system graphics REQUIRED)
set(CLASSES
        RightPyramid.h RightPyramid.cpp
        Scene.cpp Scene.h
        Object.cpp Object.h
        Math.cpp Math.h
        Figure.h
        RightTruncatedPyramid.cpp RightTruncatedPyramid.h
        Polygon.cpp Polygon.h
        Observer.cpp Observer.h
        Matrix.h
        Vector.h)
add_executable(2lab main.cpp ${CLASSES})
target_link_libraries(2lab sfml-graphics sfml-system)