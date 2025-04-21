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
        
        inputHandler.init(window.getNativeHandle());
        
        context.window = &window;
        context.renderer = &renderer;
        context.input = &inputHandler;


        app->onInit(&context);

        //apagar ---- teste
        float vertices[3][3] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };
        //----------------

        while(!window.shouldClose()) {
            float currentTime = glfwGetTime();
            float deltaTime = currentTime - lastTimeFrame;
            lastTimeFrame = currentTime;

            app->onUpdate(deltaTime);
            app->onRender();

            //------------------------------------------------------------------------
            //apagar ---- teste
            
    
            graphics::Shader* shader = new graphics::Shader(
                "/home/leo/projects/triton_engine/assets/shaders/vertex.glsl",
                "/home/leo/projects/triton_engine/assets/shaders/fragment.glsl",
                {{0, "aPos"}}
            );
    
            graphics::Mesh triangle = graphics::createTriangleMesh(shader, vertices);

            if (sys::Input::isKeyPressed(GLFW_KEY_LEFT)) {
                std::cout << "Tecla esquerda pressionada!" << std::endl;
                vertices[0][1] += 0.01f;
                vertices[1][1] += 0.01f;
                vertices[2][1] += 0.01f;
            }

            renderer.submit(triangle);
            //Triangle rendering
            renderer.renderAll();
            renderer.clear();
            //------------------------------------------------

            
            window.swapBuffers();
            glfwPollEvents();
        }

        app->onShutdown();
        utils::Logger::log("Ending Engine execution",utils::LogLevel::INFO);
    }
}