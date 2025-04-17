#include "engine/core/Engine.h"
#include "graphics/Shader.h"
#include "utils/Logger.h"
#include "game/TestGame.h"


int main() {

    core::Engine engine(800, 600, "Triton Engine");
    TestGame testGame;
    engine.run(&testGame);
    return 0;
}