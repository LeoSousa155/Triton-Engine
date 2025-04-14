#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    if(!glfwInit()) {
        std::cerr << "Initialization ERROR: Unable to initialize the GLFW library.\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Triton Engine", nullptr, nullptr);
    if(!window) {
        std::cerr << "Initialization ERROR: Window Creation Failed\n";
        glfwTerminate();
        return -1; 
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Initialization ERROR: Unable to load OpenGL functions with GLAD\n";
        return -1;
    }

    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}