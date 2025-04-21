#ifndef RENDERER_H
#define RENDERER_H

#include <vector>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "graphics/Mesh.h"

namespace sys {


    /** @brief Manages core rendering setup and execution (currently a simple triangle). */
    class Renderer {
        public:
            void submit(const graphics::Mesh& mesh) {
                meshes.push_back(mesh);
            }

            void renderAll() {
                for(const auto& mesh : meshes) {
                    mesh.draw();
                }
            }

            void clear() {
                meshes.clear();
            }

        private:
            std::vector<graphics::Mesh> meshes;
    };
}


#endif
