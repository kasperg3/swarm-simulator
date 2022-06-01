#ifndef SIMULATORSTATE_H
#define SIMULATORSTATE_H

#pragma once
#include <list>

// time delta to define the size of the timesteps in the sim, this is default 1 TODO move this to a core/config header file
#define DELTA_TIME 0.01
#define MAX_SPEED 10.0
#define BOUNDING_RADIUS 30.0

#include "Robot.h"
class SimulatorState {
   public:
    SimulatorState();
    SimulatorState(std::list<Robot>);
    ~SimulatorState();

    std::list<Robot> getRobots() { return mRobots; }

    std::list<Robot> mRobots;

   private:
    // Todo add more states, like environment states
};

#endif