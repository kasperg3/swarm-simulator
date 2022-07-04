#include "SwarmSimulator.h"

#define GRAPHICS_API_OPENGL_33
#include <iostream>
#include <string>

namespace SwarmSim {

SwarmSimulator::SwarmSimulator(bool hl, std::list<Robot*> robots, std::list<Widget*> widgetList) : mHeadless(hl) {
    // init logger
    Log log;
    log.Init();

    // init simulation
    mSimulator = std::make_shared<Simulator>(robots);

    if (!mHeadless) {
        // init the view
        mSimulatorView = std::make_unique<SimulatorView>(mSimulator, widgetList, 1920, 1080);
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
