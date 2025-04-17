#include "engine/system/Window.h"
#include "utils/Logger.h"

namespace sys {


    Window::Window() : window(nullptr) {}


    Window::~Window() {
        if(window) {
            glfwDestroyWindow(window);
            window = nullptr;
        }
    }


    bool Window::init(int width, int height, std::string title) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if(!window) {
            utils::Logger::log("Window Creation Failed", utils::LogLevel::ERROR);
            return false; 
        }

        glfwMakeContextCurrent(window);
        utils::Logger::log("Window created successfully", utils::LogLevel::INFO);
        return true;
    }


    void Window::swapBuffers() {
        if(window) {
            glfwSwapBuffers(window);
        }
    }


    bool Window::shouldClose() const {
        return window && glfwWindowShouldClose(window);
    }


    GLFWwindow* Window::getNativeHandle() {
        if (!window) {
            utils::Logger::log("Accessing native handle before window initialization!", utils::LogLevel::WARNING);
        }
        return window;
    }
}