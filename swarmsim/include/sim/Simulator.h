#ifndef SIMULATOR_H
#define SIMULATOR_H

#pragma once

#include <list>
#include <memory>

#include "EnvironmentState.h"
#include "Robot.h"
namespace SwarmSim
{

    class Simulator
    {
    public:
        Simulator(std::map<std::string, Robot *> robots) { mState = std::make_shared<EnvironmentState>(robots); };
        Simulator(std::shared_ptr<EnvironmentState> state) { mState = state; };
        ~Simulator();
        void step();
        void step(int);
        void restart();
        void addRobot(Robot *);
        Robot *getRobot(std::string id);
        bool hasRobot(std::string id);

        std::shared_ptr<EnvironmentState> getState();

    private:
        std::shared_ptr<EnvironmentState> mState;
    };
} // namespace SwarmSim

#endif