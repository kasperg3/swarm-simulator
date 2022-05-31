#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once
#include <memory>
#include <string>

#include "src/sim/Simulator.h"
#include "src/ui/SimulatorView.h"

class Application {
   public:
    Application();
    Application(bool);
    ~Application();

    bool shouldClose();
    void loop();

   private:
    bool mHeadless;
    std::unique_ptr<SimulatorView> mSimulatorView;
    std::shared_ptr<Simulator> mSimulator;
};

#endif