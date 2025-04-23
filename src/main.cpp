#include "engine/core/Engine.h"
#include "Test/PiramidGame.h"
#include "Test/TestGame.h"

/**
 * TO_DO:
 * 
 * - Modificar a criação da engine e do Game para que seja o game a definir
 *   as dimensões da tela e o nome da Janela
 * 
 * - ? modificar Engine para ser instânciada usando o padrão Builder ?
 * 
 * - criar a camerâ em sua própria classe
 * - adicionar uma configuração para alternar entre renderização 2D e 3D 
 * 
 */

int main() {

    core::Engine engine(800, 600, "Triton Engine");
    gametest::PiramidGame testGame;
    engine.run(&testGame);
    return 0;
}