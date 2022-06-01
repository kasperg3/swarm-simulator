#include "SimulatorView.h"

#include "raylib.h"
#define GRAPHICS_API_OPENGL_33
#include <iostream>
#include <string>

#include "GLFW/glfw3.h"  // Note: Provided with Raylib but needs to be in GLFW folder to work correctly
#include "include/imgui_glfw_opengl3_impl/imgui.h"
#include "include/imgui_glfw_opengl3_impl/imgui_impl_glfw.h"
#include "include/imgui_glfw_opengl3_impl/imgui_impl_opengl3.h"
#include "rlgl.h"

SimulatorView::SimulatorView(std::shared_ptr<Simulator> simPtr, int width, int height) : mScreenHeight(height), mScreenWidth(width), mSimulator(simPtr) {
    // raylib init
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

    mPropertyPanel = PropertyPanel();
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
    UpdateCamera(&mCamera);  // Update camera

    // if (IsKeyDown(KEY_RIGHT)) cubePosition.x -= .1f;
    // if (IsKeyDown(KEY_LEFT)) cubePosition.x += .1f;
    // if (IsKeyDown(KEY_UP)) cubePosition.z += .1f;
    // if (IsKeyDown(KEY_DOWN)) cubePosition.z -= .1f;
    // if (IsKeyDown(KEY_LEFT_CONTROL)) cubePosition.y -= .1f;
    // if (IsKeyDown(KEY_SPACE)) cubePosition.y += .1f;

    // if (cubePosition.y > 0.0f) {
    //     cubePosition.y -= .01f;
    // }
}

void SimulatorView::drawUI() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    mPropertyPanel.draw();
    rlDrawRenderBatchActive();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

#include "src/core/Log.h"

void SimulatorView::drawSimulationView() {
    BeginMode3D(mCamera);
    DrawGrid(50, 1.0f);
    for (auto &&r : mSimulator->getState().mRobots) {
        auto pos = r.getPosition();
        Vector3 rlPos = {(float)pos.x, (float)pos.y, (float)pos.z};
        DrawCube(rlPos, 0.5f, .5f, .5f, RED);
        DrawCubeWires(rlPos, 0.5f, 0.5f, 0.5f, MAROON);
        DrawCircle3D(rlPos, r.getAttributes().radiusToNeighbour, {1, 0, 0}, -90, BLUE);
    }

    EndMode3D();
}
