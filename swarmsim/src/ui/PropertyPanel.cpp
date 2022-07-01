#include "ui/PropertyPanel.h"

#include "Boids.h"
#include "imgui_glfw_opengl3_impl/imgui.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_glfw.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_opengl3.h"
namespace SwarmSim {
PropertyPanel::PropertyPanel() : mRestart(false) {
}

void PropertyPanel::draw() {
    // Settings menu
    ImGui::Begin("Settings");
    if (ImGui::Button("Restart")) {
        setRestart(true);
    }
    ImGui::DragFloat("Cohesion", &mCohesion, 0.01, 0.0, 1.0, "%.3f", 16);
    ImGui::DragFloat("Seperation", &mSeparation, 0.01, 0.0, 1.0, "%.3f", 16);
    ImGui::DragFloat("Allignment", &mAllignment, 0.01, 0.0, 1.0, "%.3f", 16);
    ImGui::DragFloat("Attractor", &mAttractor, 0.01, 0.0, 1.0, "%.3f", 16);
    ImGui::DragFloat("Neighbouring radius", &mRadiusToNeighbour, 0.1, 0.0, 10.0, "%.3f", 16);
    // ImGui::DragFloat3("Target", {&mTarget.x, &mTarget.x, &mTarget.x});
    ImGui::End();
}

void PropertyPanel::update(std::shared_ptr<SimulatorState> state) {
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