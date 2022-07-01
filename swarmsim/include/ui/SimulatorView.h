#ifndef SIMULATOR_VIEW_H
#define SIMULATOR_VIEW_H

#pragma once
#include <list>
#include <memory>

#include "../sim/Simulator.h"
#include "PropertyPanel.h"
#include "raylib.h"
namespace SwarmSim {

class SimulatorView {
   public:
    SimulatorView(std::shared_ptr<Simulator>, int, int);

    ~SimulatorView();
    void render();
    void update();

   private:
    void drawUI();
    void drawSimulationView();

    PropertyPanel mPropertyPanel;
    Camera3D mCamera;

    std::shared_ptr<Simulator> mSimulator;

    int mScreenWidth;
    int mScreenHeight;
};

class SimulatorViewBuilder {
   private:
    bool fps = false;
    Color color;
    std::shared_ptr<Simulator> simulator;
    int width = 1000;
    int height = 720;
    std::list<Widget*> widgetList;

   public:
    SimulatorViewBuilder(std::shared_ptr<Simulator> sim) {
        simulator = sim;
    }

    SimulatorView* build() {
        return new SimulatorView(simulator, 1000, 720);
    };

    // TODO
    //  SimulatorViewBuilder* camera(Camera c) {came return this; };

    SimulatorViewBuilder* widgets(std::list<Widget*> w) {
        widgetList = w;
        return this;
    };

    SimulatorViewBuilder* drawFPS() {
        fps = true;
        return this;
    };
    SimulatorViewBuilder* backgroundColor(Color c) {
        color = c;
        return this;
    };

    SimulatorViewBuilder* windowHeight(int h) {
        height = h;
        return this;
    };

    SimulatorViewBuilder* windowWidth(int w) {
        width = w;
        return this;
    };
};

}  // namespace SwarmSim

#endif