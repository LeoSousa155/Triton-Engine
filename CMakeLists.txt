cmake_minimum_required(VERSION 3.10)
project(TritonEngine)

set(CMAKE_CXX_STANDARD 17)

# GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(
    include               
    ${GLFW_INCLUDE_DIRS}
    external/glad/include
)

# Add all .cpp files from src/ to the project
file(GLOB_RECURSE SRC_FILES
    src/*.cpp             
)

# Adds glad.c manually
list(APPEND SRC_FILES external/glad/src/glad.c)

# Create executable
add_executable(TritonEngine ${SRC_FILES})

# link libraries
target_link_libraries(TritonEngine ${GLFW_LIBRARIES} dl GL)
