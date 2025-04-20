#ifndef APPLICATION_H
#define APPLICATION_H

#include "engine/core/EngineContext.h"

namespace core {

    /**
     * @class Application
     * @brief Abstract base class (interface) for the user's game or application logic.
     *
     * Users should derive from this class and implement the virtual methods
     * to define the behavior of their specific application. The Engine will
     * call these methods during its lifecycle.
     */
    class Application {
        public:
            /** @brief Virtual destructor to ensure proper cleanup of derived classes. */
            virtual ~Application() = default;

            /**
             * @brief Called once when the application is initialized by the Engine.
             * Use this to load resources, set up initial game state, etc.
             * @param ctx Pointer to the EngineContext, providing access to engine subsystems.
             */
            virtual void onInit(EngineContext* ctx) {}

            /**
             * @brief Called every frame by the Engine.
             * Use this for game logic updates, physics, input handling, etc.
             * @param deltaTime The time elapsed since the last frame, in seconds.
             */
            virtual void onUpdate(float deltaTime) {}

            /**
             * @brief Called every frame by the Engine after updates, specifically for rendering.
             * Use this to issue draw calls via the Renderer.
             */
            virtual void onRender() {}

            /**
             * @brief Called once when the application is about to shut down.
             * Use this to release resources, save state, etc.
             */
            virtual void onShutdown() {}
    };
}

#endif
