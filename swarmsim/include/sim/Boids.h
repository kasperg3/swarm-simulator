#ifndef BOIDS_H
#define BOIDS_H
#include "Robot.h"
#pragma once
namespace SwarmSim {
class Boids : public Robot {
   public:
    Boids();
    ~Boids();
    void sense(SimulatorState*) override;
    void act() override;

   private:
};

}  // namespace SwarmSim

#endif