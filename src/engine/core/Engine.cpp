#include <iostream>

#include "utils/Logger.h"
#include "engine/core/Engine.h"


namespace core {


    Engine::Engine(int width, int height, const char* title) 
    : width(width), height(height), title(title) {}


    Engine::~Engine() {
        glfwTerminate();
    }


    bool Engine::init() {
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

        inputHandler.init(window.getNativeHandle());
        
        context.window = &window;
        context.renderer = &renderer;
        context.input = &inputHandler;

        return true;
    }


    void Engine::run(Application* app) {
        if(!init()) return;
        utils::Logger::log("Starting Engine execution", utils::LogLevel::INFO);

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

        app->onShutdown();
        utils::Logger::log("Ending Engine execution",utils::LogLevel::INFO);
    }
}