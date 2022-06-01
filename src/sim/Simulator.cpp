#include "Simulator.h"

Simulator::Simulator() {
    std::list<Robot> robots;
    for (size_t i = 0; i < 100; i++) {
        robots.emplace_back(Robot(i));
    }

    mState = SimulatorState(robots);
}

Simulator::~Simulator() {}

void Simulator::step() {
    // act once with every agent
    // Todo create a getter in SimulatorState to get the robot iterator
    for (std::list<Robot>::iterator it = mState.mRobots.begin(); it != mState.mRobots.end(); ++it) {
        it->sense(mState);
        it->act();
    }
}

void Simulator::step(int steps) {
    for (int i = steps; i > 0; i--) {
        step();
    }
}

SimulatorState Simulator::getState() {
    // TODO make simulator return a pointer to a const state
    return mState;
}
