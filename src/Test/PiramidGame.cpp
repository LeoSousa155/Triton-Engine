#include "PiramidGame.h"
#include "engine/system/Input.h"
#include <cstring> // Required for memcpy

namespace gametest {

    void PiramidGame::onInit(core::EngineContext* ctx) {

        // init renderer
        this->renderer = ctx->renderer;

        // init pyramid vertices
        // Vertices for a square-based pyramid
        float verts[18][3] = {
            // Base (2 triângulos)
            // Triangle 1
            {-0.5f, 0.0f, -0.5f}, // Bottom-left base
            { 0.5f, 0.0f, -0.5f}, // Bottom-right base
            { 0.5f, 0.0f,  0.5f}, // Top-right base

            // Triangle 2
            {-0.5f, 0.0f, -0.5f}, // Bottom-left base
            { 0.5f, 0.0f,  0.5f}, // Top-right base
            {-0.5f, 0.0f,  0.5f}, // Top-left base

            // Lados (4 triângulos)
            // Side 1 (Front)
            {-0.5f, 0.0f, -0.5f}, // Bottom-left base
            { 0.5f, 0.0f, -0.5f}, // Bottom-right base
            { 0.0f, 0.8f,  0.0f}, // Apex

            // Side 2 (Right)
            { 0.5f, 0.0f, -0.5f}, // Bottom-right base
            { 0.5f, 0.0f,  0.5f}, // Top-right base
            { 0.0f, 0.8f,  0.0f}, // Apex

            // Side 3 (Back)
            { 0.5f, 0.0f,  0.5f}, // Top-right base
            {-0.5f, 0.0f,  0.5f}, // Top-left base
            { 0.0f, 0.8f,  0.0f}, // Apex

            // Side 4 (Left)
            {-0.5f, 0.0f,  0.5f}, // Top-left base
            {-0.5f, 0.0f, -0.5f}, // Bottom-left base
            { 0.0f, 0.8f,  0.0f}  // Apex
        };
        memcpy(vertices, verts, sizeof(verts)); // Copy the pyramid vertices into the member variable

        // init triangle shader (assuming this path is correct)
        shader = new graphics::Shader(
            "../assets/shaders/vertex3D.glsl",
            "../assets/shaders/fragment.glsl",
            {{0, "aPos"}}
        );

        // Create the mesh using the new vertices and size
        piramid = graphics::createTriangleMesh(shader, vertices, sizeof(vertices));

        // Note: updateVertices in onUpdate might not be necessary unless the vertices change dynamically
        // For a static pyramid, you only need to set up the mesh once in onInit.

        glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
    }

    void PiramidGame::onUpdate(float deltatime) {
        // If the pyramid vertices were to change dynamically, you would update here.
        // For a static pyramid, this call might be removed or adapted for transformations later.
        // triangle.updateVertices(vertices, sizeof(vertices));

        glm::vec3 cur_rot = piramid.transform.rotation;
        piramid.transform.rotation = glm::vec3(cur_rot.x, cur_rot.y + 0.3f, cur_rot.z);

        if (sys::Input::isKeyPressed(GLFW_KEY_UP)) {
            piramid.transform.position.y += 0.01f;
        }
        if (sys::Input::isKeyPressed(GLFW_KEY_DOWN)) {
            piramid.transform.position.y -= 0.01f;
        }

        piramid.updateVertices(vertices, sizeof(vertices)); 

    }

    void PiramidGame::onRender() {
        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Also clear depth buffer for 3D


        // Triangle rendering (now pyramid rendering)
        renderer->submit(piramid);
        renderer->renderAll();
        renderer->clear();
    }


    void PiramidGame::onShutdown() {
        // Clean up shader if it was allocated with 'new'
        if (shader) {
            delete shader;
            shader = nullptr;
        }
        // Mesh cleanup might be needed depending on its internal structure
    }
}
