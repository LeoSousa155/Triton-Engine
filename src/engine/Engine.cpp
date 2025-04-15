#include <iostream>

#include "utils/Logger.h"
#include "engine/Engine.h"


namespace engine {


    Engine::Engine(int width, int height, const char* title)
    : width(width), height(height), title(title), window(nullptr) {}


    Engine::~Engine() {
        if(window) {
            glfwDestroyWindow(window);
        }
        glfwTerminate();
    }


    bool Engine::initWindow() {
        if(!glfwInit()) {
            utils::Logger::log("Unable to initialize the GLFW library", utils::LogLevel::ERROR);
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if(!window) {
            utils::Logger::log("Window Creation Failed", utils::LogLevel::ERROR);
            glfwTerminate();
            return false; 
        }

        glfwMakeContextCurrent(window);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            utils::Logger::log("Unable to load OpenGL functions with GLAD", utils::LogLevel::ERROR);
            return false;
        }

        return true;
    }


    void Engine::run() {
        if(!initWindow()) return;

        while(!glfwWindowShouldClose(window)) {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
}