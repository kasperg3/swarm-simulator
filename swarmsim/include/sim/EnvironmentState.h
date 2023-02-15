#ifndef EnvironmentState_H
#define EnvironmentState_H

#pragma once
#include <list>
#include <map>

#define BOUNDING_RADIUS 50.0

#include "Environment.h"
#include "Robot.h"
namespace SwarmSim
{
    class EnvironmentState
    {
    public:
        EnvironmentState();
        EnvironmentState(std::map<std::string, Robot *> r);
        EnvironmentState(std::map<std::string, Robot *> r, Environment);
        ~EnvironmentState();
        void addRobot(Robot *);
        std::map<std::string, Robot *> getRobots() { return mRobots; }
        std::shared_ptr<Environment> getEnvironment() { return mEnvironment; }

        void reset();
        bool hasRobot(std::string r)
        {
            bool result = true;
            auto it = mRobots.find(r);
            if (it == mRobots.end())
            {
                result = false;
            }
            return result;
        }

        Robot *getRobot(std::string key)
        {
            Robot *result = nullptr;
            auto it = mRobots.find(key);
            if (it == mRobots.end())
            {
                result = it->second;
            }
            return result;
        }

        bool isPaused() { return mIsPaused; }
        void setPaused(bool p) { mIsPaused = p; }

    private:
        bool mIsPaused = false;
        std::map<std::string, Robot *> mRobots;
        std::shared_ptr<Environment> mEnvironment;
    };
} // namespace SwarmSim

#endif