#ifndef SIMULATOR_H
#define SIMULATOR_H

#pragma once

#include <list>
#include <memory>

#include "Robot.h"
#include "SimulatorState.h"
namespace SwarmSim {

class Simulator {
   public:
    Simulator(std::list<Robot*> robots) { mState = std::make_shared<SimulatorState>(robots); };
    Simulator(std::shared_ptr<SimulatorState> state) { mState = state; };
    ~Simulator();
    void step();
    void step(int);
    void restart();
    void addRobot(Robot*);

    std::shared_ptr<SimulatorState> getState();

   private:
    std::shared_ptr<SimulatorState> mState;
};
}  // namespace SwarmSim

#endif