#include "sim/EnvironmentState.h"

#include "core/Log.h"
namespace SwarmSim
{
    EnvironmentState::~EnvironmentState()
    {
    }

    void EnvironmentState::reset()
    {
        SWARMSIM_CORE_INFO("Resetting EnvironmentState...");
        for (auto r : mRobots)
        {
            r.second->reset();
        }
    }

    EnvironmentState::EnvironmentState()
    {
    }

    EnvironmentState::EnvironmentState(std::map<std::string, Robot *> robots)
    {
        mRobots = robots;
        mEnvironment = std::make_shared<Environment>();
    }

    EnvironmentState::EnvironmentState(std::map<std::string, Robot *> r, Environment e)
    {
        mRobots = r;
        mEnvironment = std::make_shared<Environment>(e);
    }

    void EnvironmentState::addRobot(Robot *r)
    {
        mRobots.emplace(r->getId(), r);
    }

} // namespace SwarmSim
