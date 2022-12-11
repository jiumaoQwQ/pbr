file(GLOB IMGUI_SRC src/*.cpp)
file(GLOB IMGUI_INCLUDE include/*.h)

add_library(imgui STATIC ${IMGUI_SRC} ${IMGUI_INCLUDE})
target_include_directories(imgui PUBLIC include)