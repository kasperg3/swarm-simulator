#include "SwarmSimulator.h"

#define GRAPHICS_API_OPENGL_33
#include <iostream>
#include <string>

#include "Boids.h"
namespace SwarmSim {
SwarmSimulator::SwarmSimulator(bool hl) {
    SwarmSimulator(hl, std::list<Robot*>());
}

SwarmSimulator::SwarmSimulator(bool hl, std::list<Robot*> robots) : mHeadless(hl) {
    // init logger
    Log log;
    log.Init();

    // init simulation
    mSimulator = std::make_shared<Simulator>(robots);

    if (!mHeadless) {
        // init the view
        mSimulatorView = std::make_unique<SimulatorView>(mSimulator, 1000, 720);
    }
}

SwarmSimulator::~SwarmSimulator() {
}

void SwarmSimulator::addRobot(Robot* robot) {
}

bool SwarmSimulator::shouldClose() {
    return mHeadless ? false : WindowShouldClose();
}

void SwarmSimulator::loop() {
    while (!shouldClose()) {
        // step SwarmSimulator
        mSimulator->step();
        if (!mHeadless) {
            // handle input
            mSimulatorView->update();
            // render state
            mSimulatorView->render();
        }
    }
}

}  // namespace SwarmSim
