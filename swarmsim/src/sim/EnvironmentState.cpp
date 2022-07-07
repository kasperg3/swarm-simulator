#include "sim/EnvironmentState.h"

#include "core/Log.h"
namespace SwarmSim {
EnvironmentState::~EnvironmentState() {
}

void EnvironmentState::reset() {
    SWARMSIM_CORE_INFO("Resetting EnvironmentState...");
    for (auto r : mRobots) {
        r->reset();
    }
}

EnvironmentState::EnvironmentState() {
}

EnvironmentState::EnvironmentState(std::list<Robot*> robots) {
    mRobots = robots;
    mEnvironment = std::make_shared<Environment>();
}

EnvironmentState::EnvironmentState(std::list<Robot*> r, Environment e) {
    mRobots = r;
    mEnvironment = std::make_shared<Environment>(e);
}

}  // namespace SwarmSim
