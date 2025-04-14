cmake_minimum_required(VERSION 3.10)
project(TritonEngine)

set(CMAKE_CXX_STANDARD 17)

# GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# Include diretórios
include_directories(
    ${GLFW_INCLUDE_DIRS}
    external/glad/include
)

# Adiciona o executável e linka o glad.c
add_executable(TritonEngine
    src/main.cpp
    external/glad/src/glad.c
)

# Linka as bibliotecas
target_link_libraries(TritonEngine ${GLFW_LIBRARIES} dl GL)
