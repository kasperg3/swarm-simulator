#include "SwarmSim.h"

#define GRAPHICS_API_OPENGL_33
#include <iostream>
#include <string>

SwarmSim::SwarmSim(bool hl) : mHeadless(hl) {
    // init logger
    Log log;
    log.Init();

    // init simulation
    mSimulator = std::make_shared<Simulator>();

    if (!mHeadless) {
        // init the view
        mSimulatorView = std::make_unique<SimulatorView>(mSimulator, 1000, 720);
    }
}

SwarmSim::~SwarmSim() {
}

bool SwarmSim::shouldClose() {
    return mHeadless ? false : WindowShouldClose();
}

void SwarmSim::loop() {
    while (!shouldClose()) {
        // step simulator
        mSimulator->step();
        if (!mHeadless) {
            // handle input
            mSimulatorView->update();
            // render state
            mSimulatorView->render();
        }
    }
}
