#ifndef SIMULATOR_VIEW_H
#define SIMULATOR_VIEW_H

#pragma once
#include <list>
#include <memory>

#include "../sim/Simulator.h"
#include "Widget.h"
#include "raylib.h"
namespace SwarmSim {

class SimulatorView {
   public:
    SimulatorView(std::shared_ptr<Simulator>, std::list<Widget*> w, int, int);

    ~SimulatorView();
    void render();
    void update();

   private:
    void drawUI();
    void drawSimulationView();

    Camera3D mCamera;
    std::shared_ptr<Simulator> mSimulator;
    int mScreenWidth;
    int mScreenHeight;

    std::list<Widget*> mWidgets;
};
}  // namespace SwarmSim
#endif