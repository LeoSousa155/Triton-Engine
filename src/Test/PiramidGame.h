#ifndef PIRAMIDGAME_H
#define PIRAMIDGAME_H

#include "graphics/Shader.h"
#include "engine/core/Application.h"
#include "utils/Logger.h"
#include "graphics/Mesh.h" // Make sure Mesh.h is included if Mesh struct is used

namespace gametest {
    class PiramidGame : public core::Application {
        private:
            sys::Renderer* renderer;
            graphics::Shader* shader;
            graphics::Mesh piramid; // Renaming this to 'pyramidMesh' might be clearer later
            // Updated vertices array size for a pyramid (6 triangles * 3 vertices/triangle * 3 components/vertex)
            float vertices[18][3];

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

#endif // !PIRAMIDGAME_H
