#include "PropertyPanel.h"

#include "include/imgui_glfw_opengl3_impl/imgui.h"
#include "include/imgui_glfw_opengl3_impl/imgui_impl_glfw.h"
#include "include/imgui_glfw_opengl3_impl/imgui_impl_opengl3.h"

PropertyPanel::PropertyPanel() {
}

void PropertyPanel::draw() {
    //  // Create menubar
    //  if (ImGui::BeginMenuBar()) {
    //      if (ImGui::BeginMenu("Options")) {
    //          // Disabling fullscreen would allow the window to be moved to the front of other windows,
    //          // which we can't undo at the moment without finer window depth/z control.
    //          ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen);
    //          // ImGui::MenuItem("Padding", NULL, &opt_padding);
    //          // ImGui::Separator();

    //          // if (ImGui::MenuItem("Flag: NoSplit", "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0)) {
    //          //     dockspace_flags ^= ImGuiDockNodeFlags_NoSplit;
    //          // }
    //          // if (ImGui::MenuItem("Flag: NoResize", "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0)) {
    //          //     dockspace_flags ^= ImGuiDockNodeFlags_NoResize;
    //          // }
    //          // if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0)) {
    //          //     dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode;
    //          // }
    //          // if (ImGui::MenuItem("Flag: AutoHideTabBar", "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0)) {
    //          //     dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar;
    //          // }
    //          // if (ImGui::MenuItem("Flag: PassthruCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, opt_fullscreen)) {
    //          //     dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode;
    //          // }
    //          // ImGui::Separator();
    //          ImGui::EndMenu();
    //      }

    //      ImGui::EndMenuBar();
    //  }
    //  ImGui::End();

    // Settings menu
    ImGui::Begin("Settings");
    ImGui::Button("Test");
    // ImGui::DragFloat3("Value", value);
    ImGui::End();

    // TODO create a trace following the robot in x timesteps
}