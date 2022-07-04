#include "sim/Simulator.h"

#include "core/Log.h"
namespace SwarmSim {

Simulator::~Simulator() {
    // Make sure to delete the robots
    for (auto r : mState->getRobots()) {
        delete r;
    }
}

void Simulator::step() {
    // act once with every agent
    if (!mState->isPaused()) {
        std::list<Robot*> robots = mState->getRobots();
        for (std::list<Robot*>::iterator it = robots.begin(); it != robots.end(); ++it) {
            (*it)->sense(getState());
            (*it)->act();
        }
    }
}

void Simulator::step(int steps) {
    for (int i = steps; i > 0; i--) {
        step();
    }
}

void Simulator::restart() {
    SWARMSIM_CORE_INFO("Restarting simulation...");
    mState.reset();
}

void Simulator::addRobot(Robot* robot) {
    SWARMSIM_CORE_WARN("TODO Implement addRobot function");
    // TODO
    // this->mState->getRobots().emplace_back(robot);
}

std::shared_ptr<SimulatorState> Simulator::getState() {
    return mState;
}

}  // namespace SwarmSim
