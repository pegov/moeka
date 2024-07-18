cmake_minimum_required(VERSION 3.10)

project(moeka
    VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(moeka
    src/api/api.cpp
    src/main.cpp
)

target_include_directories(moeka PRIVATE
    ${THIRD_PARTY_DIR}/include
    ${THIRD_PARTY_DIR}/freetype/include
    ${THIRD_PARTY_DIR}/include/freetype
    ${THIRD_PARTY_DIR}/imgui
    ${THIRD_PARTY_DIR}/imgui/backends
    ${THIRD_PARTY_DIR}/imgui/misc/freetype
    ./src
)

target_link_directories(moeka PRIVATE
    ${THIRD_PARTY_DIR}/lib
)

target_sources(moeka PRIVATE
    "${THIRD_PARTY_DIR}/imgui/imgui.cpp"

    "${THIRD_PARTY_DIR}/imgui/imgui_demo.cpp"
    "${THIRD_PARTY_DIR}/imgui/imgui_draw.cpp"
    "${THIRD_PARTY_DIR}/imgui/imgui_widgets.cpp"
    "${THIRD_PARTY_DIR}/imgui/imgui_tables.cpp"
    "${THIRD_PARTY_DIR}/imgui/misc/freetype/imgui_freetype.cpp"

    "${THIRD_PARTY_DIR}/imgui/backends/imgui_impl_glfw.cpp"
    "${THIRD_PARTY_DIR}/imgui/backends/imgui_impl_opengl3.cpp"
)

target_link_libraries(moeka cpr GL glfw rt m dl glm pthread X11 Xxf86vm Xrandr Xi freetype z bz2 png16 harfbuzz graphite2 brotlidec brotlicommon)
