#ifndef SIMULATORSTATE_H
#define SIMULATORSTATE_H

#pragma once
#include <list>

// time delta to define the size of the timesteps in the sim, this is default 1 TODO move this to a core/config header file
#define DELTA_TIME 0.01
#define MAX_SPEED 10.0
#define BOUNDING_RADIUS 50.0

#include "Robot.h"
namespace SwarmSim {
class SimulatorState {
   public:
    SimulatorState();
    SimulatorState(std::list<Robot*>);
    ~SimulatorState();

    std::list<Robot*> getRobots() { return mRobots; }

    void reset();

   private:
    std::list<Robot*> mRobots;
};
}  // namespace SwarmSim

#endif