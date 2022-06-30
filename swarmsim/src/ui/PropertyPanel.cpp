#include "ui/PropertyPanel.h"

#include "imgui_glfw_opengl3_impl/imgui.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_glfw.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_opengl3.h"
namespace SwarmSim {
PropertyPanel::PropertyPanel() : mRestart(false) {
}

void PropertyPanel::draw(SimulatorState* state) {
    // Settings menu
    ImGui::Begin("Settings");
    if (ImGui::Button("Restart")) {
        setRestart(true);
    }
    ImGui::DragFloat("Cohesion", &mCohesion);
    ImGui::DragFloat("Seperation", &mSeparation);
    ImGui::DragFloat("Allignment", &mAllignment);
    ImGui::DragFloat("Attractor", &mAttractor);
    ImGui::DragFloat("Neighbouring radius", &mRadiusToNeighbour);
    // ImGui::DragFloat3("Target", {&mTarget.x, &mTarget.x, &mTarget.x});
    ImGui::End();

    // TODO create a trace following the robot in x timesteps
}

}  // namespace SwarmSim