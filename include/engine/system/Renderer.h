#ifndef RENDERER_H
#define RENDERER_H

#include <vector>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "graphics/Camera.h"
#include "graphics/Mesh.h"

namespace sys {


    /** @brief Manages core rendering setup and execution */
    class Renderer {
        public:
            Renderer();
            ~Renderer();

            bool init();
            void shutdown();

            void beginFrame(const graphics::Camera3D& camera, float aspectRatio);

            void submit(const graphics::Mesh& mesh);
            void renderAll();
            void clear();

        private:
            std::vector<graphics::Mesh> meshQueue;
            const graphics::Camera3D* activeCamera;
            float currentAspectRatio;
    };
}
#endif
