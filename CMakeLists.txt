cmake_minimum_required(VERSION 3.20)

project(pbr LANGUAGES CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(main main.cpp shader.h stb_image.h camera.h sphere.h)

add_subdirectory(external)

target_link_libraries(main glad glfw glm::glm)