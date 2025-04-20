#ifndef RENDERER_H
#define RENDERER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "graphics/Shader.h"

namespace sys {

    /** @brief Manages core rendering setup and execution (currently a simple triangle). */
    class Renderer {
        public:
            /** @brief Initializes shaders and geometry (VAO/VBO). */
            bool init();

            /** @brief Renders the current scene (binds VAO and draws). */
            void render();

        private:
            // --- Attributes ---
            unsigned int VAO; ///< Vertex Array Object handle.
            unsigned int VBO; ///< Vertex Buffer Object handle.
            graphics::Shader* shader = nullptr; ///< Shader program used for rendering.
            // ---

            /** @brief Sets up VAO/VBO for a hardcoded triangle. */
            void initTriangle();
    };
}


#endif
