#ifndef SWARMSIM_H
#define SWARMSIM_H

#pragma once
#include <memory>
#include <string>

#include "../core/Log.h"
#include "../sim/Simulator.h"
#include "../ui/SimulatorView.h"

class SwarmSim {
   public:
    SwarmSim();
    SwarmSim(bool);
    ~SwarmSim();

    bool shouldClose();
    void loop();

   private:
    bool mHeadless;
    std::unique_ptr<SimulatorView> mSimulatorView;
    std::shared_ptr<Simulator> mSimulator;
};

#endif  // SWARMSIM_H
