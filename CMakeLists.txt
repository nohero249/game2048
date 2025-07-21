cmake_minimum_required(VERSION 3.20)
project(game2048)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG)

add_executable(${PROJECT_NAME} src/main.cpp
        src/main.h
)

target_include_directories(${PROJECT_NAME} PRIVATE 
        ${SDL3_INCLUDE_DIRS}
        ${SDL3IMAGE_INCLUDE_DIR}
        )

target_link_libraries(${PROJECT_NAME}
        ${SDL3_LIBRARIES}
        SDL3_image::SDL3_image
)