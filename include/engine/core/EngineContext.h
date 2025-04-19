#ifndef ENGINECONTEXT_H
#define ENGINECONTEXT_H

#include "engine/system/Input.h"
#include "engine/system/Window.h"
#include "engine/system/Renderer.h"


namespace core {


    struct EngineContext {
        sys::Window* window = nullptr;
        sys::Input* input = nullptr;
        sys::Renderer* renderer = nullptr;
    };
}

#endif // !ENGINECONTEXT_H