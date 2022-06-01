#include "SimulatorState.h"

SimulatorState::~SimulatorState() {
}

SimulatorState::SimulatorState() {
}

SimulatorState::SimulatorState(std::list<Robot> robots) {
    mRobots = robots;
}
