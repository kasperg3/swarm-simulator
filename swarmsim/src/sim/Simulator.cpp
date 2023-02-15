#include "sim/Simulator.h"

#include "core/Log.h"
#include "Simulator.h"
namespace SwarmSim
{

    Simulator::~Simulator()
    {
        // Make sure to delete the robots
        for (auto r : mState->getRobots())
        {
            delete r.second;
        }
    }

    void Simulator::step()
    {
        // act once with every agent
        if (!mState->isPaused())
        {
            std::map<std::string, Robot *> robots = mState->getRobots();
            for (auto const &[key, val] : robots)
            {
                // TODO Set the robot state
                val->sense(getState());
                val->act();
            }
        }
    }

    void Simulator::step(int steps)
    {
        for (int i = steps; i > 0; i--)
        {
            step();
        }
    }

    void Simulator::restart()
    {
        SWARMSIM_CORE_INFO("Restarting simulation...");

        mState.reset();
    }

    void Simulator::addRobot(Robot *robot)
    {
        this->mState->addRobot(robot);
    }

    Robot *Simulator::getRobot(std::string id)
    {
        return this->mState->getRobot(id);
    }

    bool Simulator::hasRobot(std::string id)
    {
        return this->mState->hasRobot(id);
    }

    std::shared_ptr<EnvironmentState> Simulator::getState()
    {
        return mState;
    }

} // namespace SwarmSim
