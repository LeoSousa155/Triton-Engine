#ifndef RENDERER_H
#define RENDERER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "graphics/Shader.h"

namespace sys {


    class Renderer {
        public:
            bool init();
            void render();

        private:
            unsigned int VAO, VBO;
            graphics::Shader* shader = nullptr;

            void initTriangle();
    };
}


#endif