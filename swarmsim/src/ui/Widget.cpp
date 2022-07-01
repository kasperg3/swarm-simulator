#include "Widget.h"

#include "imgui_glfw_opengl3_impl/imgui.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_glfw.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_opengl3.h"
namespace SwarmSim {
void Widget::dragFloat(const char *name, float *value, float steps, float min, float max) {
    ImGui::DragFloat(name, value, steps, min, max, "%.3f", 16);
}

void Widget::begin(const char *name) {
    ImGui::Begin(name);
}

void Widget::end() {
    ImGui::End();
}

bool Widget::button(const char *name) {
    return ImGui::Button(name);
}

}  // namespace SwarmSim