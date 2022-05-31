#ifndef SIMULATOR_H
#define SIMULATOR_H

#pragma once

#include <list>

#include "Robot.h"

struct SimulatorState {
    std::list<Robot> robots;
    // Todo add more states, like environment states
};

class Simulator {
   public:
    Simulator();
    Simulator(SimulatorState);
    ~Simulator();
    SimulatorState getState();
    void step();
    void step(int);

   private:
    SimulatorState mState;
};

#endif