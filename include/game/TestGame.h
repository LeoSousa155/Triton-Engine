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
        }

        void onShutdown() override {
            // liberar recursos
        }
};
