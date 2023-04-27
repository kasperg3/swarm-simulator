#include "SwarmSimulator.h"

#define GRAPHICS_API_OPENGL_33
#include <iostream>
#include <string>
#include "uuid/uuid.h"
namespace SwarmSim
{

    SwarmSimulator::SwarmSimulator(bool hl, std::map<std::string, Robot *> robots, std::list<Widget *> widgetList) : SwarmSimulator(hl, std::make_shared<EnvironmentState>(robots), widgetList)
    {
    }

    SwarmSimulator::SwarmSimulator(bool hl, std::shared_ptr<EnvironmentState> state, std::list<Widget *> widgetList) : mHeadless(hl)
    {
        // init logger
        Log log;
        log.Init();

        // init simulation
        mSimulator = std::make_shared<Simulator>(state);

        if (!mHeadless)
        {
            // init the view
            mSimulatorView = std::make_unique<SimulatorView>(mSimulator, widgetList, 1920, 1080);
        }
    }
    SwarmSimulator::~SwarmSimulator()
    {
    }

    void SwarmSimulator::addRobot(Robot *robot)
    {
        this->mSimulator->addRobot(robot);
    }

    bool SwarmSimulator::hasRobot(std::string rId)
    {
        return this->mSimulator->hasRobot(rId);
    }

    bool SwarmSimulator::shouldClose()
    {
        return mHeadless ? false : WindowShouldClose();
    }

    void SwarmSimulator::loop()
    {
        while (!shouldClose())
        {
            // step SwarmSimulator
            mSimulator->step();

            if (!mHeadless)
            {
                // handle input
                mSimulatorView->update();
                // render state
                mSimulatorView->render();
            }
        }
    }

    void SwarmSimulator::loopOnce()
    {
        // step SwarmSimulator
        mSimulator->step();

        if (!mHeadless)
        {
            // handle input
            mSimulatorView->update();
            // render state
            mSimulatorView->render();
        }
    }

    void SwarmSimulator::setRobotPosition(std::string id, glm::dvec3 pos)
    {

        if (mSimulator->getState()->hasRobot(id))
        {
            mSimulator->getRobot(id)->setPosition(pos);
        }
        else
        {
            SWARMSIM_CORE_ERROR("Did not find robot with id: %s", id);
        }
    }

    std::shared_ptr<Simulator> SwarmSimulator::getSimulator()
    {
        return mSimulator;
    }

    std::map<std::string, SwarmSim::Robot *> SwarmSimulator::getNeighbors(std::string id, glm::dvec3 position, float range)
    {
        std::map<std::string, SwarmSim::Robot *> robots = mSimulator->getState()->getRobots();
        std::map<std::string, SwarmSim::Robot *> neighbors;

        // Add robot to list of neighbors, if within range
        std::copy_if(robots.begin(), robots.end(), std::inserter(neighbors, neighbors.end()),
                     [&id, &position, &range](std::pair<std::string, SwarmSim::Robot *> map_robot)
                     {
                         if (id != std::get<0>(map_robot))
                         {
                             return glm::length(std::get<1>(map_robot)->getPosition() - position) < range;
                         }
                         return false;
                     });

        return neighbors;
    }

} // namespace SwarmSim
