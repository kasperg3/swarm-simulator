#ifndef SIMULATOR_H
#define SIMULATOR_H

#pragma once

#include <list>
#include <memory>

#include "Robot.h"
#include "SimulatorState.h"

class Simulator {
   public:
    Simulator();
    ~Simulator();
    void step();
    void step(int);
    void restart();

    SimulatorState* getState();

   private:
    std::shared_ptr<SimulatorState> mState;
};

#endif