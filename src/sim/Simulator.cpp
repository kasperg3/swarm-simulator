#include "Simulator.h"

Simulator::Simulator() {
    mState = {{Robot(), Robot()}};
}

Simulator::Simulator(SimulatorState state) : mState(state) {
}

Simulator::~Simulator() {
}

void Simulator::step() {
    // act once with every agent
    for (auto robot : this->mState.robots) {
        robot.update();
    }
}

void Simulator::step(int steps) {
    for (int i = steps; i > 0; i--) {
        step();
    }
}

SimulatorState Simulator::getState() {
    return mState;
}
