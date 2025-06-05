#include "engine/system/Input.h"
#include "utils/Logger.h"


namespace sys {
    ///////////////////////////////
    // Initialize static members //
    ///////////////////////////////

    bool sys::Input::keys[1024] = { false };
    double sys::Input::mouseX = 0.0;
    double sys::Input::mouseY = 0.0;
    bool sys::Input::mouseButtons[GLFW_MOUSE_BUTTON_LAST + 1] = { false };


    // GLFW keyboard key callback function
    void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
        Input::setKeyState(key, action);
    }

    // GLFW mouse button callback function
    void glfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        Input::setMouseButtonState(button, action);
    }

    // GLFW cursor position callback function
    void glfwCursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
        Input::setMousePosition(xpos, ypos);
    }

    void sys::Input::init(GLFWwindow* window) {
        glfwSetKeyCallback(window, glfwKeyCallback);
        glfwSetMouseButtonCallback(window, glfwMouseButtonCallback);
        glfwSetCursorPosCallback(window, glfwCursorPosCallback);
        utils::Logger::log("Input system initialized and callbacks set.", utils::LogLevel::INFO);
    }

    //////////////////////
    // Keyboard Methods //
    //////////////////////

    void sys::Input::setKeyState(int key, int action) {
        if (key >= 0 && key < 1024)
        keys[key] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }


    bool sys::Input::isKeyPressed(int key) {
        return keys[key];
    }


    bool sys::Input::isKeyReleased(int key) {
        return !keys[key];
    }

    ///////////////////
    // Mouse Methods //
    ///////////////////

    void sys::Input::setMousePosition(double xpos, double ypos) {
        mouseX = xpos;
        mouseY = ypos;
    }


    void sys::Input::setMouseButtonState(int button, int action) {
        if (button >= 0 && button <= GLFW_MOUSE_BUTTON_LAST)
            mouseButtons[button] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }


    bool sys::Input::isMouseButtonPressed(int button) {
        return mouseButtons[button];
    }


    bool sys::Input::isMouseButtonReleased(int button) {
        return !mouseButtons[button];
    }


    double sys::Input::getMouseX() {
        return mouseX;
    }


    double sys::Input::getMouseY() {
        return mouseY;
    }
}