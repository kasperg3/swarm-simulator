#include "sim/Simulator.h"

#include "core/Log.h"
Simulator::Simulator() {
    std::list<Robot> robots;
    for (size_t i = 0; i < 100; i++) {
        robots.emplace_back(Robot(i));
    }

    mState = std::make_shared<SimulatorState>(robots);
}

Simulator::~Simulator() {}

void Simulator::step() {
    // act once with every agent
    for (std::list<Robot>::iterator it = mState->mRobots.begin(); it != mState->mRobots.end(); ++it) {
        it->sense(getState());
        it->act();
    }
}

void Simulator::step(int steps) {
    for (int i = steps; i > 0; i--) {
        step();
    }
}

void Simulator::restart() {
    HERD_CORE_INFO("Restarting simulation...");
    // Reinitialize robots
    std::list<Robot> robots;
    for (size_t i = 0; i < 100; i++) {
        robots.emplace_back(Robot(i));
    }

    mState = std::make_shared<SimulatorState>(robots);
}

SimulatorState* Simulator::getState() {
    return mState.get();
}
