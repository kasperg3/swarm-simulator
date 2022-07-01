#ifndef SWARMSIM_H
#define SWARMSIM_H

#pragma once
#include <memory>
#include <string>

#include "../core/Log.h"
#include "../sim/Simulator.h"
#include "../ui/SimulatorView.h"

namespace SwarmSim {
class SwarmSimulator {
   public:
    SwarmSimulator(bool, std::list<Robot*> robots, std::list<Widget*>);
    ~SwarmSimulator();

    void addRobot(Robot* robot);
    bool shouldClose();
    void loop();

   private:
    bool mHeadless;
    std::unique_ptr<SimulatorView> mSimulatorView;
    std::shared_ptr<Simulator> mSimulator;
};

}  // namespace SwarmSim

#endif  // SWARMSIM_H
