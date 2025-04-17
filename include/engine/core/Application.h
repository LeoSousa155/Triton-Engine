#ifndef APPLICATION_H
#define APPLICATION_H

#include "engine/core/EngineContext.h"

namespace core {

    // Interface for game implementation
    class Application {
        public:
            virtual ~Application() = default;

            virtual void onInit(EngineContext* ctx) {}
            virtual void onUpdate(float deltaTime) {}
            virtual void onRender() {}
            virtual void onShutdown() {}
    };
}

#endif