#include "PropertyPanel.hpp"

#include "vendor/imgui_glfw_opengl3_impl/imgui.h"
// struct ExampleAppLog {
//     ImGuiTextBuffer Buf;
//     ImGuiTextFilter Filter;
//     ImVector<int> LineOffsets;  // Index to lines offset. We maintain this with AddLog() calls.
//     bool AutoScroll;            // Keep scrolling if already at the bottom.

//     ExampleAppLog() {
//         AutoScroll = true;
//         Clear();
//     }

//     void Clear() {
//         Buf.clear();
//         LineOffsets.clear();
//         LineOffsets.push_back(0);
//     }

//     void AddLog(const char* fmt, ...) IM_FMTARGS(2) {
//         int old_size = Buf.size();
//         va_list args;
//         va_start(args, fmt);
//         Buf.appendfv(fmt, args);
//         va_end(args);

//         for (int new_size = Buf.size(); old_size < new_size; old_size++)
//             if (Buf[old_size] == '\n')
//                 LineOffsets.push_back(old_size + 1);
//     }

//     void Draw(const char* title, bool* p_open = NULL) {
//         if (!ImGui::Begin(title, p_open)) {
//             ImGui::End();
//             return;
//         }

//         // Options menu
//         if (ImGui::BeginPopup("Options")) {
//             ImGui::Checkbox("Auto-scroll", &AutoScroll);
//             ImGui::EndPopup();
//         }

//         // Main window
//         if (ImGui::Button("Options"))
//             ImGui::OpenPopup("Options");
//         ImGui::SameLine();
//         bool clear = ImGui::Button("Clear");
//         ImGui::SameLine();
//         bool copy = ImGui::Button("Copy");
//         ImGui::SameLine();
//         Filter.Draw("Filter", -100.0f);

//         ImGui::Separator();
//         ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

//         if (clear)
//             Clear();
//         if (copy)
//             ImGui::LogToClipboard();

//         ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
//         const char* buf = Buf.begin();
//         const char* buf_end = Buf.end();
//         if (Filter.IsActive()) {
//             // In this example we don't use the clipper when Filter is enabled.
//             // This is because we don't have a random access on the result on our filter.
//             // A real application processing logs with ten of thousands of entries may want to store the result of
//             // search/filter.. especially if the filtering function is not trivial (e.g. reg-exp).
//             for (int line_no = 0; line_no < LineOffsets.Size; line_no++) {
//                 const char* line_start = buf + LineOffsets[line_no];
//                 const char* line_end = (line_no + 1 < LineOffsets.Size) ? (buf + LineOffsets[line_no + 1] - 1) : buf_end;
//                 if (Filter.PassFilter(line_start, line_end))
//                     ImGui::TextUnformatted(line_start, line_end);
//             }
//         } else {
//             // The simplest and easy way to display the entire buffer:
//             //   ImGui::TextUnformatted(buf_begin, buf_end);
//             // And it'll just work. TextUnformatted() has specialization for large blob of text and will fast-forward
//             // to skip non-visible lines. Here we instead demonstrate using the clipper to only process lines that are
//             // within the visible area.
//             // If you have tens of thousands of items and their processing cost is non-negligible, coarse clipping them
//             // on your side is recommended. Using ImGuiListClipper requires
//             // - A) random access into your data
//             // - B) items all being the  same height,
//             // both of which we can handle since we an array pointing to the beginning of each line of text.
//             // When using the filter (in the block of code above) we don't have random access into the data to display
//             // anymore, which is why we don't use the clipper. Storing or skimming through the search result would make
//             // it possible (and would be recommended if you want to search through tens of thousands of entries).
//             ImGuiListClipper clipper;
//             clipper.Begin(LineOffsets.Size);
//             while (clipper.Step()) {
//                 for (int line_no = clipper.DisplayStart; line_no < clipper.DisplayEnd; line_no++) {
//                     const char* line_start = buf + LineOffsets[line_no];
//                     const char* line_end = (line_no + 1 < LineOffsets.Size) ? (buf + LineOffsets[line_no + 1] - 1) : buf_end;
//                     ImGui::TextUnformatted(line_start, line_end);
//                 }
//             }
//             clipper.End();
//         }
//         ImGui::PopStyleVar();

//         if (AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
//             ImGui::SetScrollHereY(1.0f);

//         ImGui::EndChild();
//         ImGui::End();
//     }
// };

// namespace Herd {
// void RenderUI() {
//     static bool opt_fullscreen = true;
//     static bool opt_padding = false;
//     static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

//     // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
//     // because it would be confusing to have two docking targets within each others.
//     ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
//     if (opt_fullscreen) {
//         const ImGuiViewport* viewport = ImGui::GetMainViewport();
//         ImGui::SetNextWindowPos(viewport->WorkPos);
//         ImGui::SetNextWindowSize(viewport->WorkSize);
//         ImGui::SetNextWindowViewport(viewport->ID);
//         ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
//         ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
//         window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
//         window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
//     } else {
//         dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
//     }

//     // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
//     // and handle the pass-thru hole, so we ask Begin() to not render a background.
//     if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
//         window_flags |= ImGuiWindowFlags_NoBackground;

//     // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
//     // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
//     // all active windows docked into it will lose their parent and become undocked.
//     // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
//     // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
//     if (!opt_padding)
//         ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
//     ImGui::Begin("SwarmSim", NULL, window_flags);
//     if (!opt_padding)
//         ImGui::PopStyleVar();

//     if (opt_fullscreen)
//         ImGui::PopStyleVar(2);

//     // Submit the DockSpace
//     ImGuiIO& io = ImGui::GetIO();
//     if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
//         ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
//         ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
//     }

//     // Create menubar
//     if (ImGui::BeginMenuBar()) {
//         if (ImGui::BeginMenu("Options")) {
//             // Disabling fullscreen would allow the window to be moved to the front of other windows,
//             // which we can't undo at the moment without finer window depth/z control.
//             ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen);
//             // ImGui::MenuItem("Padding", NULL, &opt_padding);
//             // ImGui::Separator();

//             // if (ImGui::MenuItem("Flag: NoSplit", "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0)) {
//             //     dockspace_flags ^= ImGuiDockNodeFlags_NoSplit;
//             // }
//             // if (ImGui::MenuItem("Flag: NoResize", "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0)) {
//             //     dockspace_flags ^= ImGuiDockNodeFlags_NoResize;
//             // }
//             // if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0)) {
//             //     dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode;
//             // }
//             // if (ImGui::MenuItem("Flag: AutoHideTabBar", "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0)) {
//             //     dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar;
//             // }
//             // if (ImGui::MenuItem("Flag: PassthruCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, opt_fullscreen)) {
//             //     dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode;
//             // }
//             // ImGui::Separator();
//             ImGui::EndMenu();
//         }

//         ImGui::EndMenuBar();
//     }
//     ImGui::End();

//     // Settings menu
//     ImGui::Begin("Settings");
//     ImGui::Button("Test");
//     float value = 1.0f;
//     ImGui::DragFloat("Value", &value);
//     ImGui::End();

//     // Logger
//     static ExampleAppLog my_log;
//     my_log.Draw("Logger");
//     HERD_CORE_INFO("Test");

//     // OpenGL Simulator
//     ImGui::Begin("Simulator");
//     {
//         // Using a Child allow to fill all the space of the window.
//         // It also alows customization
//         ImGui::BeginChild("SimulatorRender");
//         // Get the size of the child (i.e. the whole draw size of the windows).
//         ImVec2 wsize = ImGui::GetWindowSize();
//         // Because I use the texture from OpenGL, I need to invert the V from the UV.

//         // TODO add a simulator class made with opengl that renders an image for the ui to use
//         // ImGui::Image((ImTextureID)tex, wsize, ImVec2(0, 1), ImVec2(1, 0));
//         ImGui::EndChild();
//     }
//     ImGui::End();
// }

PropertyPanel::PropertyPanel() {
}

void PropertyPanel::render() {
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
    float value = 1.0f;
    ImGui::DragFloat("Value", &value);
    ImGui::End();

    // Logger
    //  static ExampleAppLog my_log;
    //  my_log.Draw("Logger");
    //  HERD_CORE_INFO("Test");
}