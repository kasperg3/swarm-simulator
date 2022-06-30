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
    Simulator(std::list<Robot*> robots);
    ~Simulator();
    void step();
    void step(int);
    void restart();
    void addRobot(Robot*);

    SimulatorState* getState();

   private:
    std::shared_ptr<SimulatorState> mState;
};
}  // namespace SwarmSim

#endif