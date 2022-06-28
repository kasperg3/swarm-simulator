#ifndef SIMULATOR_VIEW_H
#define SIMULATOR_VIEW_H

#pragma once
#include <list>
#include <memory>

#include "../sim/Simulator.h"
#include "PropertyPanel.h"
#include "raylib.h"

class SimulatorView {
   public:
    SimulatorView(std::shared_ptr<Simulator>, int, int);

    ~SimulatorView();
    void render();
    void update();

   private:
    void drawUI();
    void drawSimulationView();
    void drawRobot();

    PropertyPanel mPropertyPanel;
    Camera3D mCamera;

    std::shared_ptr<Simulator> mSimulator;

    int mScreenWidth;
    int mScreenHeight;
};

#endif