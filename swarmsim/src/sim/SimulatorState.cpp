#include "sim/SimulatorState.h"

#include "core/Log.h"
namespace SwarmSim {
SimulatorState::~SimulatorState() {
}

void SimulatorState::reset() {
    SWARMSIM_CORE_INFO("Resetting simulatorstate...");
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
