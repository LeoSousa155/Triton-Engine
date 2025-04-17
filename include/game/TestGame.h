// MyGame.h
#include "engine/core/Application.h"

class TestGame : public core::Application {
public:
    void onInit(core::EngineContext* ctx) override {
        // carregar cena, texturas, etc
    }

    void onUpdate(float deltaTime) override {
        // lógica do jogo
    }

    void onRender() override {
        // renderizar objetos
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void onShutdown() override {
        // liberar recursos
    }
};
