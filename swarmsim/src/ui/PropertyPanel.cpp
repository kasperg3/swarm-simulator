#include "PropertyPanel.h"

#include "Boids.h"
#include "imgui_glfw_opengl3_impl/imgui.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_glfw.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_opengl3.h"
namespace SwarmSim {
PropertyPanel::PropertyPanel() : mRestart(false) {
}

void PropertyPanel::draw() {
    // Settings menu
    begin("Settings");
    if (button("Restart")) {
        setRestart(true);
    }

    dragFloat("Cohesion", &mCohesion, 0.01f, 0.0f, 1.0f);
    dragFloat("Seperation", &mSeparation, 0.01f, 0.0f, 1.0f);
    dragFloat("Allignment", &mAllignment, 0.01f, 0.0f, 1.0f);
    dragFloat("Attractor", &mAttractor, 0.01f, 0.0f, 1.0f);
    dragFloat("Neighbouring radius", &mRadiusToNeighbour, 0.1f, 0.0f, 10.0f);
    end();
}

void PropertyPanel::update(std::shared_ptr<SwarmSim::SimulatorState> state) {
    if (getRestart()) {
        state->reset();
        setRestart(false);
    }

    // TODO this is not the right way. Find a way of updating robot parameters without casting to a type
    for (Robot* robot : state->getRobots()) {
        Boids* b = static_cast<Boids*>(robot);
        b->setCohesionWeight(mCohesion);
        b->setSeparationWeight(mSeparation);
        b->setAllignmentWeight(mAllignment);
        b->setRadiusToNeighbour(mRadiusToNeighbour);
    }
}

}  // namespace SwarmSim