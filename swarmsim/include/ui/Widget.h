#ifndef WIDGET_H
#define WIDGET_H

#pragma once
#include "SimulatorState.h"
namespace SwarmSim {
class Widget {
   public:
    virtual void draw() = 0;
    virtual void update(std::shared_ptr<SimulatorState>) = 0;

   private:
};
}  // namespace SwarmSim

#endif