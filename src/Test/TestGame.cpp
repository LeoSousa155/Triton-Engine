#include "TestGame.h"


namespace gametest {


    void TestGame::onInit(core::EngineContext* ctx) {
    
        // init renderer
        this->renderer = ctx->renderer;
    
        // init triangle vertices
        vertices[0][0] = -0.5f;
        vertices[0][1] = -0.5f;
        vertices[0][2] =  0.0f;
        vertices[1][0] =  0.5f;
        vertices[1][1] = -0.5f;
        vertices[1][2] =  0.0f;
        vertices[2][0] =  0.0f;
        vertices[2][1] =  0.5f;
        vertices[2][2] =  0.0f;
    
        // init triangle shader
        shader = new graphics::Shader(
            "/home/leo/projects/triton_engine/assets/shaders/vertex.glsl",
            "/home/leo/projects/triton_engine/assets/shaders/fragment.glsl",
            {{0, "aPos"}}
        );
    
        triangle = graphics::createTriangleMesh(shader, vertices, sizeof(vertices));
    }


    void TestGame::onUpdate(float deltatime) {
        if (sys::Input::isKeyPressed(GLFW_KEY_UP)) {
            std::cout << "Tecla cima pressionada!" << std::endl;
            vertices[0][1] += 0.01f;
            vertices[1][1] += 0.01f;
            vertices[2][1] += 0.01f;
        }
        if (sys::Input::isKeyPressed(GLFW_KEY_DOWN)) {
            std::cout << "Tecla baixo pressionada!" << std::endl;
            vertices[0][1] -= 0.01f;
            vertices[1][1] -= 0.01f;
            vertices[2][1] -= 0.01f;
        }
        if (sys::Input::isKeyPressed(GLFW_KEY_RIGHT)) {
            std::cout << "Tecla direita pressionada!" << std::endl;
            vertices[0][0] += 0.01f;
            vertices[1][0] += 0.01f;
            vertices[2][0] += 0.01f;
        }
        if (sys::Input::isKeyPressed(GLFW_KEY_LEFT)) {
            std::cout << "Tecla esquerda pressionada!" << std::endl;
            vertices[0][0] -= 0.01f;
            vertices[1][0] -= 0.01f;
            vertices[2][0] -= 0.01f;
        }
        if (sys::Input::isKeyPressed(GLFW_KEY_Q))  {
            triangle.transform.rotation = glm::vec3(0.0f, triangle.transform.rotation.y + 1.0f, 0.0f);
        }

        glm::vec3 cur_rot = triangle.transform.rotation;
        triangle.transform.rotation = glm::vec3(cur_rot.x + 1.0f, cur_rot.y + 1.0f, cur_rot.z + 1.0f);

        triangle.updateVertices(vertices, sizeof(vertices)); 
    }


    void TestGame::onRender() {
        //Triangle rendering
        glClear(GL_COLOR_BUFFER_BIT); 
        renderer->submit(triangle);
        renderer->renderAll();
        renderer->clear();
    }

    
    void TestGame::onShutdown() {
        if (shader) {
            delete shader;
            shader = nullptr;
        }
    }
}