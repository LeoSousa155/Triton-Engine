#ifndef INPUT_H
#define INPUT_H

#include "GLFW/glfw3.h"

namespace sys {
    
    class Input {
        public:
            static void init(GLFWwindow* window);

            // Keyboard methods
            static void setKeyState(int key, int action);
            static bool isKeyPressed(int key);
            static bool isKeyReleased(int key);

            // Mouse methods
            static void setMousePosition(double xpos, double ypos);
            static void setMouseButtonState(int button, int action);
            static bool isMouseButtonPressed(int button);
            static bool isMouseButtonReleased(int button);
            static double getMouseX();
            static double getMouseY();

        private:
            // Keyboard state
            static bool keys[1024];

            // Mouse state
            static double mouseX, mouseY;
            static bool mouseButtons[GLFW_MOUSE_BUTTON_LAST + 1];
    };
}

#endif