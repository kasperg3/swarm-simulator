#include "Boids.h"
#include "PropertyPanel.h"
#include "SwarmSimulator.h"

void simulator()
{
    // Create robot instances
    std::list<SwarmSim::Robot *> robots;
    for (size_t i = 0; i < 250; i++)
    {
        robots.emplace_back(new SwarmSim::Boids());
    }

    // Custom property menu
    std::list<SwarmSim::Widget *> widgetList;
    SwarmSim::Widget *menu = new SwarmSim::PropertyPanel();
    widgetList.push_back(menu);

    SwarmSim::SwarmSimulator sim(false, robots, widgetList);

    sim.loop();
}

int main(void)
{
    simulator();

    return 0;
}