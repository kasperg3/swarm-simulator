#include "sim/SimulatorState.h"
namespace SwarmSim {
SimulatorState::~SimulatorState() {
}

void SimulatorState::reset() {
    for (auto r : mRobots) {
        r->reset();
    }
}

SimulatorState::SimulatorState() {
}

SimulatorState::SimulatorState(std::list<Robot*> robots) {
    mRobots = robots;
}

}  // namespace SwarmSim
