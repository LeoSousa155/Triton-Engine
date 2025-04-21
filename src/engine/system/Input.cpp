#include "engine/system/Input.h"
#include "utils/Logger.h"


namespace sys {


    bool sys::Input::keys[1024] = { false };


    void sys::Input::setKeyState(int key, int action) {
        if(key >= 0 && key < 1024)
            keys[key] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }


    bool sys::Input::isKeyPressed(int key) {
        return keys[key];
    }


    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        
        // Exemplo: marca teclas como pressionadas
        Input::setKeyState(key, action);
    }
    


    void sys::Input::init(GLFWwindow* window) {
        glfwSetKeyCallback(window, keyCallback);
    }
}