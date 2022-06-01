#ifndef SIMULATOR_H
#define SIMULATOR_H

#pragma once

#include <list>

#include "Robot.h"
#include "SimulatorState.h"

class Simulator {
   public:
    Simulator();
    ~Simulator();
    SimulatorState getState();
    void step();
    void step(int);

   private:
    SimulatorState mState;
};

#endif