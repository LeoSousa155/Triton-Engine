#ifndef INPUT_H
#define INPUT_H

#include "GLFW/glfw3.h"

namespace sys {
    
    class Input {
        public:
            static void init(GLFWwindow* window);
            static void setKeyState(int key, int action);
            static bool isKeyPressed(int key);


        private:
            static bool keys[1024];
    };
}

#endif