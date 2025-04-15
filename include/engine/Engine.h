#ifndef ENGINE_H
#define ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace engine {


    class Engine {
        public:
            Engine(int width, int height, const char* title);
            ~Engine();
            void run();
    
        private:
            GLFWwindow* window;
            int width, height;
            const char* title;
    
            bool initWindow();
    };
}

#endif 