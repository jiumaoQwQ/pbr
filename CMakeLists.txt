cmake_minimum_required(VERSION 3.20)

project(pbr)

add_executable(main main.cpp)

add_subdirectory(external)

target_link_libraries(main glad glfw glm::glm)

add_custom_command(
        TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/shader
                ${CMAKE_CURRENT_BINARY_DIR}/Debug/shader)

add_custom_command(
        TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/shader
                ${CMAKE_CURRENT_BINARY_DIR}/Release/shader)