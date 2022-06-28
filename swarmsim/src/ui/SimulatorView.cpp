#include "ui/SimulatorView.h"

#include "raylib.h"
#define GRAPHICS_API_OPENGL_33
#include <iostream>
#include <string>

#include "GLFW/glfw3.h"  // Note: Provided with Raylib but needs to be in GLFW folder to work correctly
#include "imgui_glfw_opengl3_impl/imgui.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_glfw.h"
#include "imgui_glfw_opengl3_impl/imgui_impl_opengl3.h"
#include "raymath.h"
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
    if (mPropertyPanel.getRestart()) {
        mSimulator->restart();
        mPropertyPanel.setRestart(false);
    }

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
    mPropertyPanel.draw(mSimulator->getState());
    rlDrawRenderBatchActive();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void SimulatorView::drawSimulationView() {
    BeginMode3D(mCamera);
    DrawGrid(50, 1.0f);
    for (auto &&r : mSimulator->getState()->mRobots) {
        auto pos = r.getPosition();
        Vector3 rlPos = {(float)pos.x, (float)pos.y, (float)pos.z};

        // TODO draw a triangle instead
        auto direction = glm::normalize(r.getVelocity());
        drawRobot();
        DrawCube(rlPos, 0.5f, .5f, .5f, RED);
        DrawCubeWires(rlPos, 0.5f, 0.5f, 0.5f, MAROON);

        // TODO rotate the object

        // DrawCircle3D(rlPos, r.getAttributes().radiusToNeighbour, {1, 0, 0}, -90, LIGHTGRAY);
    }

    EndMode3D();
}

void SimulatorView::drawRobot() {
    float width = 1;
    float height = 1;
    float angle = DEG2RAD * 30.0f;
    Vector3 point1 = (Vector3){0.0f, 0.0f, 0.0f};
    Vector3 point2 = (Vector3){sin(angle) * width, cos(angle) * width, 0.0};
    Vector3 point3 = (Vector3){width, 0.f, 0.0f};

    Vector3 point4 = (Vector3){width / 2, 0.5f * width * height * sin(90.0f * DEG2RAD)};

    // Front face
    DrawTriangle3D(point1, point2, point3, GREEN);
    DrawTriangle3D(point1, point2, point4, GREEN);
    DrawTriangle3D(point4, point2, point1, GREEN);
    DrawTriangle3D(point3, point2, point1, GREEN);

    // // Back face
    // DrawTriangle3D(back3, back2, back1, BLACK);

    // // Slanted side
    // DrawTriangle3D(back1, point1, back3, BLACK);
    // DrawTriangle3D(point1, point3, back3, BLACK);

    // // Back side
    // DrawTriangle3D(point2, back2, back3, BLACK);
    // DrawTriangle3D(back3, point3, point2, BLACK);

    // Bottom side
    // DrawTriangle3D(back1, back2, point2, BLACK);
    // DrawTriangle3D(point2, point1, back1, BLACK);
}
