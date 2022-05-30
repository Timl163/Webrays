cmake_minimum_required(VERSION 3.8)

set(This Example)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    Tuple.hpp
    Helper.hpp
    Color.hpp
)

set(Source
    Tuple.cpp
    Main.cpp
    Color.cpp
)

add_library(${This} STATIC ${Source} ${Headers})

add_subdirectory(test)

add_executable(Main Main.cpp)
target_link_libraries(Main PUBLIC ${This})