#include "engine/system/Renderer.h"
#include "utils/Logger.h"

#include "graphics/Mesh.h"
#include "graphics/Camera.h"


namespace sys {
    Renderer::Renderer() : activeCamera(nullptr), currentAspectRatio(800.0f / 600.0f) {
        utils::Logger::log("Renderer created.", utils::LogLevel::INFO);
    }

    Renderer::~Renderer() {
        utils::Logger::log("Renderer destroyed.", utils::LogLevel::INFO);
    }

    bool Renderer::init() {
       utils::Logger::log("Renderer initialized.", utils::LogLevel::INFO);
       return true;
    }

    void Renderer::shutdown() {
        utils::Logger::log("Renderer shutdown.", utils::LogLevel::INFO);
        meshQueue.clear();
        activeCamera = nullptr;
    }

    void Renderer::beginFrame(const graphics::Camera3D& camera, float aspectRatio) {
        this->activeCamera = &camera;
        this->currentAspectRatio = aspectRatio;
    }

    void Renderer::submit(const graphics::Mesh& mesh) {
        meshQueue.push_back(mesh);
    }

    void Renderer::renderAll() {
        if (!activeCamera) {
            utils::Logger::log("Renderer::renderAll() called without an active camera. Call beginFrame() first.", utils::LogLevel::WARNING);
            return;
        }

        for (const auto& mesh : meshQueue) {
            mesh.draw(*activeCamera, currentAspectRatio);
        }
    }

    void Renderer::clear() {
        meshQueue.clear();
    }
}