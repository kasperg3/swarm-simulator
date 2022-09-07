#include "Widget.h"

#include "ImGuiUtil.h"
namespace SwarmSim
{
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