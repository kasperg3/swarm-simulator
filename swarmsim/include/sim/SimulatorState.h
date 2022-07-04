#ifndef SIMULATORSTATE_H
#define SIMULATORSTATE_H

#pragma once
#include <list>

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

    bool isPaused() { return mIsPaused; }
    void setPaused(bool p) { mIsPaused = p; }

   private:
    bool mIsPaused = false;
    std::list<Robot*> mRobots;
};
}  // namespace SwarmSim

#endif