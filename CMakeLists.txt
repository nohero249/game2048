cmake_minimum_required(VERSION 3.20)
project(game2048)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 REQUIRED CONFIG)

add_executable(${PROJECT_NAME} src/main.cpp
        src/main.h
)

target_include_directories(${PROJECT_NAME} PRIVATE SDL3::SDL3)

target_link_libraries(${PROJECT_NAME}
        ${SDL3_LIBRARIES}
)