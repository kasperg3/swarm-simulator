#include "Boids.h"
#include "CoveragePlanner.h"
#include "PropertyPanel.h"
#include "SwarmSimulator.h"

void simulator() {
    // Create robot instances
    std::list<SwarmSim::Robot*> robots;
    for (size_t i = 0; i < 100; i++) {
        robots.emplace_back(new SwarmSim::Boids());
    }

    // Custom property menu
    SwarmSim::Widget* menu = new SwarmSim::PropertyPanel();
    std::list<SwarmSim::Widget*> widgetList;
    widgetList.push_back(menu);

    SwarmSim::SwarmSimulator sim(false, robots, widgetList);

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