#include "PiramidGame.h"
#include "engine/system/Input.h"
#include <cstring> // Required for memcpy

namespace gametest {

    const float CAMERA_MOVEMENT_SPEED = 2.5f; // Units per second
    const float PYRAMID_ROTATION_SPEED_RPS = 0.1f; // Revolutions per second
    const float PYRAMID_MOVEMENT_SPEED_UPS = 1.0f; // Units per second


    void PiramidGame::onInit(core::EngineContext* ctx) {

        // init renderer
        this->renderer = ctx->renderer;
        this->engineCtx = ctx; // Store the context

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

        camera = graphics::Camera3D(glm::vec3(0.0f, 1.0f, 3.0f));
        piramid.transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
    }

    void PiramidGame::onUpdate(float deltatime) {
        // If the pyramid vertices were to change dynamically, you would update here.
        // For a static pyramid, this call might be removed or adapted for transformations later.
        // triangle.updateVertices(vertices, sizeof(vertices));

         // --- Camera Input ---
        if (sys::Input::isKeyPressed(GLFW_KEY_W))
            camera.processKeyboard(graphics::CameraMovement::FORWARD, deltatime);
        if (sys::Input::isKeyPressed(GLFW_KEY_S))
            camera.processKeyboard(graphics::CameraMovement::BACKWARD, deltatime);
        if (sys::Input::isKeyPressed(GLFW_KEY_A))
            camera.processKeyboard(graphics::CameraMovement::LEFT, deltatime);
        if (sys::Input::isKeyPressed(GLFW_KEY_D))
            camera.processKeyboard(graphics::CameraMovement::RIGHT, deltatime);
        if (sys::Input::isKeyPressed(GLFW_KEY_SPACE))
            camera.processKeyboard(graphics::CameraMovement::UP, deltatime);
        if (sys::Input::isKeyPressed(GLFW_KEY_LEFT_CONTROL))
            camera.processKeyboard(graphics::CameraMovement::DOWN, deltatime);

        // Basic mouse look (requires tracking last mouse position)
        static double lastMouseX = sys::Input::getMouseX();
        static double lastMouseY = sys::Input::getMouseY();
        double currentMouseX = sys::Input::getMouseX();
        double currentMouseY = sys::Input::getMouseY();

        float xoffset = static_cast<float>(currentMouseX - lastMouseX);
        float yoffset = static_cast<float>(lastMouseY - currentMouseY); // Reversed

        lastMouseX = currentMouseX;
        lastMouseY = currentMouseY;

        // Add a check if mouse is captured or a button is pressed to enable look
        // For now, always process if there's an offset and mouse is not at 0,0 (initial state)
        if ((xoffset != 0 || yoffset != 0) && (currentMouseX != 0 || currentMouseY != 0) /* && glfwGetInputMode(ctx->window->getNativeHandle(), GLFW_CURSOR) == GLFW_CURSOR_DISABLED */ ) {
             camera.processMouseMovement(xoffset, yoffset);
        }

        // --- Pyramid Transformation ---
        // Rotate the pyramid around its Y-axis (frame-rate independent)
        float rotationAngleDelta = PYRAMID_ROTATION_SPEED_RPS * 2.0f * glm::pi<float>() * deltatime;
        piramid.transform.rotation.y += glm::degrees(rotationAngleDelta);
    }

    void PiramidGame::onRender() {
        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Also clear depth buffer for 3D

        // Ensure engineCtx and its window pointer are valid before using
        if (!engineCtx || !engineCtx->window) {
            utils::Logger::log("EngineContext or window not available in PiramidGame::onRender", utils::LogLevel::ERROR);
            return;
        }
        float aspectRatio = 800.0f / 600.0f;
        renderer->beginFrame(camera, aspectRatio);

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
