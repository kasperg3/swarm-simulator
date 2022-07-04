#include "ui/SimulatorView.h"

#include "raylib.h"
#define GRAPHICS_API_OPENGL_33
#include <iostream>
#include <string>

#include "GLFW/glfw3.h"  // Note: Provided with Raylib but needs to be in GLFW folder to work correctly
#include "core/Log.h"
#include "imgui_glfw_opengl3_impl/imgui.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_glfw.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_opengl3.h"
#include "raymath.h"
#include "rlgl.h"
namespace SwarmSim {
SimulatorView::SimulatorView(std::shared_ptr<Simulator> simPtr, std::list<Widget *> w, int width, int height) : mScreenHeight(height), mScreenWidth(width), mSimulator(simPtr) {
    // raylib init
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);  // Window configuration flags
    InitWindow(mScreenWidth, mScreenHeight, std::string("swarm sim").c_str());

    // imgui init
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(glfwGetCurrentContext(), true);

    ImGui_ImplOpenGL3_Init("#version 130");
    SetTargetFPS(60);

    // Define the camera to look into our 3d world
    mCamera = {0};
    mCamera.position = (Vector3){0.0f, 50.0f, -0.01f};  // Camera position
    mCamera.target = (Vector3){0.0f, 0.0f, 0.0f};       // Camera looking at point
    mCamera.up = (Vector3){0.0f, 1.0f, 0.0f};           // Camera up vector (rotation towards target)
    mCamera.fovy = 45.0f;                               // Camera field-of-view Y
    mCamera.projection = CAMERA_PERSPECTIVE;            // Camera mode type

    SetCameraMode(mCamera, CAMERA_FREE);

    // set the widgets
    mWidgets = w;
}

SimulatorView::~SimulatorView() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    CloseWindow();  // Close window and OpenGL context
}

void SimulatorView::render() {
    // render
    BeginDrawing();
    ClearBackground(RAYWHITE);
    // environment
    DrawFPS(10, 10);

    drawSimulationView();

    drawUI();

    EndDrawing();
}

void SimulatorView::update() {
    // TODO make the SimulatorView a builder so that:
    // SimulatorView.builder().camera(Enum(cameraType)).widgets(List<Widget>).drawFPS().background(Enum(Color))..build()
    UpdateCamera(&mCamera);  // Update camera
    auto state = mSimulator->getState();

    // Handle key inputs
    if (IsKeyPressed(KEY_SPACE)) {
        state->setPaused(!state->isPaused());
    }
    // Widget inputs
    for (auto w : mWidgets) {
        w->update(state);
    }
}

void SimulatorView::drawUI() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    for (auto w : mWidgets) {
        w->draw();
    }

    rlDrawRenderBatchActive();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void SimulatorView::drawSimulationView() {
    BeginMode3D(mCamera);
    DrawGrid(50, 1.0f);
    for (auto &&r : mSimulator->getState()->getRobots()) {
        r->draw();
    }

    EndMode3D();
}

}  // namespace SwarmSim
