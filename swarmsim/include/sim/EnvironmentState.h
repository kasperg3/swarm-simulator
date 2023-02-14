#ifndef EnvironmentState_H
#define EnvironmentState_H

#pragma once
#include <list>

#define BOUNDING_RADIUS 50.0

#include "Environment.h"
#include "Robot.h"
namespace SwarmSim
{
    class EnvironmentState
    {
    public:
        EnvironmentState();
        EnvironmentState(std::list<Robot *>);
        EnvironmentState(std::list<Robot *>, Environment);
        ~EnvironmentState();
        void addRobot(Robot *);
        std::list<Robot *> getRobots() { return mRobots; }
        std::shared_ptr<Environment> getEnvironment() { return mEnvironment; }

        void reset();

        bool isPaused() { return mIsPaused; }
        void setPaused(bool p) { mIsPaused = p; }

    private:
        bool mIsPaused = false;
        std::list<Robot *> mRobots;
        std::shared_ptr<Environment> mEnvironment;
    };
} // namespace SwarmSim

#endif