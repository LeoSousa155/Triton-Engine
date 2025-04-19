#ifndef ENGINE_H
#define ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "engine/system/Window.h"
#include "engine/system/Input.h"
#include "engine/system/Renderer.h"

#include "engine/core/Application.h"
#include "engine/core/EngineContext.h"

namespace core {


    


    class Engine {
        public:
            Engine(int width, int height, const char* title);
            ~Engine();
            void run(Application* app);
    
        private:
            sys::Window window;
            sys::Renderer renderer;

            int width, height;
            std::string title;
            float lastTimeFrame = 0.0f;

            EngineContext context;
    
            bool initWindow();
    };
}

#endif 