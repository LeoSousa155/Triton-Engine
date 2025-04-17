#include <iostream>

#include "utils/Logger.h"
#include "engine/core/Engine.h"


namespace core {


    Engine::Engine(int width, int height, const char* title) 
    : width(width), height(height), title(title) {}


    Engine::~Engine() {
        glfwTerminate();
    }


    bool Engine::initWindow() {
        if(!glfwInit()) {
            utils::Logger::log("Unable to initialize the GLFW library", utils::LogLevel::ERROR);
            return false;
        }

        if(!window.init(width, height, title)) {
            utils::Logger::log("Unable to initialize the window system", utils::LogLevel::ERROR);
            return false;
        }

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            utils::Logger::log("Unable to load OpenGL functions with GLAD", utils::LogLevel::ERROR);
            return false;
        }

        return true;
    }


    void Engine::run(Application* app) {
        if(!initWindow()) return;
        utils::Logger::log("Starting Engine execution", utils::LogLevel::INFO);

        context.window = &window;
        app->onInit(&context);

        while(!window.shouldClose()) {
            float currentTime = glfwGetTime();
            float deltaTime = currentTime - lastTimeFrame;
            lastTimeFrame = currentTime;

            app->onUpdate(deltaTime);
            app->onRender();

            
            window.swapBuffers();
            glfwPollEvents();
        }
        utils::Logger::log("Ending Engine execution",utils::LogLevel::INFO);
    }
}