#include "ui/SimulatorView.h"

#include "raylib.h"
#define GRAPHICS_API_OPENGL_33
#include <iostream>
#include <string>

#include "core/Log.h"
#include "ui/ImGuiUtil.h"
#include "raymath.h"
#include "rlgl.h"
namespace SwarmSim
{
    SimulatorView::SimulatorView(std::shared_ptr<Simulator> simPtr, std::list<Widget *> w, int width, int height) : mScreenHeight(height), mScreenWidth(width), mSimulator(simPtr)
    {
        // raylib init
        SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Window configuration flags
        InitWindow(mScreenWidth, mScreenHeight, std::string("swarm sim").c_str());

        // imgui init
        ImGui::CreateContext();
        ImGui_ImplGlfw_InitForOpenGL(glfwGetCurrentContext(), true);

        setUIStyle();

        ImGui_ImplOpenGL3_Init("#version 130");
        SetTargetFPS(60);

        // Define the camera to look into our 3d world
        mCamera = {0};
        mCamera.position = (Vector3){0.0f, 50.0f, -0.01f}; // Camera position
        mCamera.target = (Vector3){0.0f, 0.0f, 0.0f};      // Camera looking at point
        mCamera.up = (Vector3){0.0f, 1.0f, 0.0f};          // Camera up vector (rotation towards target)
        mCamera.fovy = 45.0f;                              // Camera field-of-view Y
        mCamera.projection = CAMERA_PERSPECTIVE;           // Camera mode type

        SetCameraMode(mCamera, CAMERA_FREE);

        // set the widgets
        mWidgets = w;
    }

    SimulatorView::~SimulatorView()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        CloseWindow(); // Close window and OpenGL context
    }

    void SimulatorView::render()
    {
        // render
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // environment
        DrawFPS(10, 10);

        drawSimulationView();

        drawUI();

        EndDrawing();
    }

    void SimulatorView::update()
    {
        // TODO make the SimulatorView a builder so that:
        // SimulatorView.builder().camera(Enum(cameraType)).widgets(List<Widget>).drawFPS().background(Enum(Color))..build()
        UpdateCamera(&mCamera); // Update camera
        auto state = mSimulator->getState();

        // Handle key inputs
        if (IsKeyPressed(KEY_SPACE))
        {
            state->setPaused(!state->isPaused());
        }
        // Widget inputs
        for (auto w : mWidgets)
        {
            w->update(state);
        }
    }

    void SimulatorView::drawUI()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        for (auto w : mWidgets)
        {
            w->draw();
        }

        rlDrawRenderBatchActive();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void SimulatorView::drawSimulationView()
    {
        BeginMode3D(mCamera);

        mSimulator->getState()->getEnvironment()->draw();

        for (auto [key, r] : mSimulator->getState()->getRobots())
        {
            r->draw();
        }

        EndMode3D();
    }

    void SimulatorView::setUIStyle()
    {
        ImGuiStyle &style = ImGui::GetStyle();

        style.WindowPadding = ImVec2(15, 15);
        style.WindowRounding = 5.0f;
        style.FramePadding = ImVec2(5, 5);
        style.FrameRounding = 4.0f;
        style.ItemSpacing = ImVec2(12, 8);
        style.ItemInnerSpacing = ImVec2(8, 6);
        style.IndentSpacing = 25.0f;
        style.ScrollbarSize = 15.0f;
        style.ScrollbarRounding = 9.0f;
        style.GrabMinSize = 5.0f;
        style.GrabRounding = 3.0f;

        style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
        style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
        style.Colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
        style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
        style.Colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
        style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style.Colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.21f, 0.22f, 0.54f);
        style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.40f);
        style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.18f, 0.18f, 0.18f, 0.67f);
        style.Colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
        style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.29f, 0.29f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
        style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
        style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
        style.Colors[ImGuiCol_CheckMark] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
        style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
        style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
        style.Colors[ImGuiCol_Button] = ImVec4(0.44f, 0.44f, 0.44f, 0.40f);
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.46f, 0.47f, 0.48f, 1.00f);
        style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.42f, 0.42f, 0.42f, 1.00f);
        style.Colors[ImGuiCol_Header] = ImVec4(0.70f, 0.70f, 0.70f, 0.31f);
        style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.70f, 0.70f, 0.70f, 0.80f);
        style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.48f, 0.50f, 0.52f, 1.00f);
        style.Colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
        style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.72f, 0.72f, 0.72f, 0.78f);
        style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
        style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.91f, 0.91f, 0.91f, 0.25f);
        style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.81f, 0.81f, 0.81f, 0.67f);
        style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.46f, 0.46f, 0.46f, 0.95f);
        style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
        style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.73f, 0.60f, 0.15f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.87f, 0.87f, 0.87f, 0.35f);
        style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
        style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
        style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);

        style.WindowPadding = ImVec2(8, 6);
        style.WindowRounding = 0.0f;
        style.FramePadding = ImVec2(5, 7);
        // style.FrameRounding            = 0.0f;
        style.ItemSpacing = ImVec2(5, 5);
    }

} // namespace SwarmSim
