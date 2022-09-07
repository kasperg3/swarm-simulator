#include "Widget.h"

#include "ImGuiUtil.h"
namespace SwarmSim
{

    // TODO Look into adding a plotting tool to the library: https://github.com/epezent/implot
    void Widget::dragFloat(const char *name, float *value, float steps, float min, float max)
    {
        ImGui::DragFloat(name, value, steps, min, max, "%.3f", 16);
    }

    void Widget::begin(const char *name)
    {
        ImGui::Begin(name);
    }

    void Widget::end()
    {
        ImGui::End();
    }

    bool Widget::button(const char *name)
    {
        return ImGui::Button(name);
    }

} // namespace SwarmSim