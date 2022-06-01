#include "PropertyPanel.h"

#include "include/imgui_glfw_opengl3_impl/imgui.h"
#include "include/imgui_glfw_opengl3_impl/imgui_impl_glfw.h"
#include "include/imgui_glfw_opengl3_impl/imgui_impl_opengl3.h"

PropertyPanel::PropertyPanel() {
}

void PropertyPanel::draw() {
    // Settings menu
    ImGui::Begin("Settings");
    ImGui::DragFloat("Cohesion", &mCohesion);
    ImGui::DragFloat("Seperation", &mSeparation);
    ImGui::DragFloat("Allignment", &mAllignment);
    ImGui::DragFloat("Attractor", &mAttractor);
    ImGui::DragFloat("Neighbouring radius", &mRadiusToNeighbour);
    // ImGui::DragFloat3("Target", {&mTarget.x, &mTarget.x, &mTarget.x});
    ImGui::End();

    // TODO create a trace following the robot in x timesteps
}