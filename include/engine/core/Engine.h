#ifndef ENGINE_H
#define ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "engine/system/Window.h"
#include "engine/core/Application.h"

namespace core {


    class Engine {
        public:
            Engine(int width, int height, const char* title);
            ~Engine();
            void run(Application* app);
    
        private:
            sys::Window window;
            int width, height;
            std::string title;
            float lastTimeFrame = 0.0f;

            EngineContext context;
    
            bool initWindow();
    };
}

#endif 