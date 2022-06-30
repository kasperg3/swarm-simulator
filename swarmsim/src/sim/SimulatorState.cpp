#include "sim/SimulatorState.h"
namespace SwarmSim {
SimulatorState::~SimulatorState() {
}

SimulatorState::SimulatorState() {
}

SimulatorState::SimulatorState(std::list<Robot*> robots) {
    mRobots = robots;
}

}  // namespace SwarmSim
