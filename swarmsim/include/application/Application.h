#ifndef APPLICATION_H
#define APPLICATION_H

#pragma once
#include <memory>
#include <string>

#include "../core/Log.h"
#include "../sim/Simulator.h"
#include "../ui/SimulatorView.h"

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