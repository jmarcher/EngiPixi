#include <iostream>
#include "Engine.h"

int main(int argc, char **argv) {
    Engine engine;
    engine.start("game", 800, 600, false);

    while (engine.isRunning()) {
        engine.handleEvents();
        engine.update();
        engine.draw();
        engine.present();
    }

    engine.clean();
    return 0;
}

