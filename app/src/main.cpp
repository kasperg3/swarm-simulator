#include "Boids.h"
#include "CoveragePlanner.h"
#include "SwarmSimulator.h"
void simulator() {
    // Create robot instances
    std::list<SwarmSim::Robot*> robots;
    for (size_t i = 0; i < 10; i++) {
        robots.emplace_back(new SwarmSim::Boids());
    }

    SwarmSim::SwarmSimulator sim(false, robots);

    // TODO app.addDrone()

    // TODO addPropertyPanel(map<Property> properties)

    // TODO Create a Robot / Environment abstraction for users to implement

    sim.loop();
}

void plannerFunc() {
    MRCP::CoveragePlanner p;
}

int main(void) {
    plannerFunc();
    simulator();

    return 0;
}