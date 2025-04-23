#ifndef TESTGAME_H
#define TESTGAME_H

#include "graphics/Shader.h"
#include "engine/core/Application.h"
#include "utils/Logger.h"

namespace gametest {
    class TestGame : public core::Application {
        private:
            sys::Renderer* renderer;
            graphics::Shader* shader;
            graphics::Mesh triangle;
            float vertices[3][3];
    
    
        public:
            // init game elements
            void onInit(core::EngineContext* ctx) override;
            
            // game logic
            void onUpdate(float deltaTime) override;
    
            // render objects
            void onRender() override;
    
            // free resources
            void onShutdown() override;
    };
}

#endif // !TESTGAME_H