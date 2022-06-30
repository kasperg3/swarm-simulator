#include "sim/Simulator.h"

#include "Boids.h"
#include "core/Log.h"
namespace SwarmSim {
Simulator::Simulator(std::list<Robot*> robots) {
    mState = std::make_shared<SimulatorState>(robots);
}

Simulator::~Simulator() {}

void Simulator::step() {
    // act once with every agent
    for (std::list<Robot*>::iterator it = mState->mRobots.begin(); it != mState->mRobots.end(); ++it) {
        (*it)->sense(getState());
        (*it)->act();
    }
}

void Simulator::step(int steps) {
    for (int i = steps; i > 0; i--) {
        step();
    }
}

void Simulator::restart() {
    SWARMSIM_CORE_INFO("Restarting simulation... TODO");
}

void Simulator::addRobot(Robot* robot) {
    this->mState->mRobots.emplace_back(robot);
}

SimulatorState* Simulator::getState() {
    return mState.get();
}

}  // namespace SwarmSim
