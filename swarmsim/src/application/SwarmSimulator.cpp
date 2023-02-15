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

} // namespace SwarmSim
