#ifndef ENGINE_CONTEXT_H
#define ENGINE_CONTEXT_H

#include "engine/system/Window.h"
#include "engine/system/Input.h"

namespace core {

    struct EngineContext {
        sys::Window* window = nullptr;
        sys::Input* input = nullptr;
        // Renderer* renderer = nullptr; // mais tarde
    };
}

#endif