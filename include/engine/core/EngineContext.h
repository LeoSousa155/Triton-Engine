#ifndef ENGINECONTEXT_H
#define ENGINECONTEXT_H

#include "engine/system/Input.h"
#include "engine/system/Window.h"
#include "engine/system/Renderer.h"


namespace core {

    
    /**
     * @struct EngineContext
     * @brief A container holding pointers to essential engine subsystems.
     *
     * This struct provides a convenient way to pass around references to core
     * systems like the window, input manager, and renderer throughout the engine.
     * Pointers are initialized to nullptr by default.
     */
    struct EngineContext {
        sys::Window* window = nullptr;      ///< Pointer to the main application window system.
        sys::Input* input = nullptr;        ///< Pointer to the input handling system.
        sys::Renderer* renderer = nullptr;  ///< Pointer to the rendering system.
    };
}

#endif // !ENGINECONTEXT_H
