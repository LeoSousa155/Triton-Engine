#include "engine/Engine.h"
#include "graphics/Shader.h"
#include "utils/Logger.h"


int main() {
    utils::Logger::log("Stating Engine execution...");

    engine::Engine engine(800, 600, "Triton Engine");
    engine.run();

    utils::Logger::log("Ending Engine execution");
    return 0;
}