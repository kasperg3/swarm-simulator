#include "Application.h"

#define GRAPHICS_API_OPENGL_33
#include <iostream>
#include <string>

Application::Application() {
    Application(false);
}

Application::Application(bool headless) : mHeadless(headless) {
    // init logger
    Log log;
    log.Init();

    // init simulation
    mSimulator = std::make_shared<Simulator>();

    if (!mHeadless) {
        // init the view
        mSimulatorView = std::make_unique<SimulatorView>(mSimulator, 1000, 720);
    }
}

Application::~Application() {
}

bool Application::shouldClose() {
    return mHeadless ? false : WindowShouldClose();
}

void Application::loop() {
    while (!shouldClose()) {
        // step simulator
        mSimulator->step();
        if (!mHeadless) {
            // handle input
            mSimulatorView->update();
            // render state
            mSimulatorView->render();
        }
    }
}
