
// Raylib headers
//#include "raygui.h"
#include "raylib.h"
#define GRAPHICS_API_OPENGL_33
#include "GLFW/glfw3.h"  // Note: Provided with Raylib but needs to be in GLFW folder to work correctly
#include "rlgl.h"

// Dear ImGui headers
#include "vendor/imgui_glfw_opengl3_impl/imgui.h"
#include "vendor/imgui_glfw_opengl3_impl/imgui_impl_glfw.h"
#include "vendor/imgui_glfw_opengl3_impl/imgui_impl_opengl3.h"

int main(void) {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(1600, 900, "Title");
    ImGui::CreateContext();
    GLFWwindow *glfwWindow = glfwGetCurrentContext();
    ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Define the camera to look into our 3d world
    Camera3D camera = {0};
    camera.position = (Vector3){0.0f, 50.0f, -0.01f};  // Camera position
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};       // Camera looking at point
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};           // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                               // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;            // Camera mode type

    Vector3 cubePosition = {0.0f, 1.0f, 0.0f};
    float value[3] = {cubePosition.x, cubePosition.y, cubePosition.z};

    SetTargetFPS(144);  // Set our game to run at 60 frames-per-second

    //--------------------------------------------------------------------------------------

    SetCameraMode(camera, CAMERA_FREE);  // Set a free camera mode

    // Main game loop
    while (!WindowShouldClose())  // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        UpdateCamera(&camera);  // Update camera

        cubePosition.x = value[0];
        cubePosition.y = value[1];
        cubePosition.z = value[2];

        if (IsKeyDown(KEY_RIGHT)) cubePosition.x += .1f;
        if (IsKeyDown(KEY_LEFT)) cubePosition.x -= .1f;
        if (IsKeyDown(KEY_UP)) cubePosition.z -= .1f;
        if (IsKeyDown(KEY_DOWN)) cubePosition.z += .1f;
        if (IsKeyDown(KEY_LEFT_CONTROL)) cubePosition.y -= .1f;
        if (IsKeyDown(KEY_SPACE)) cubePosition.y += .1f;

        if (cubePosition.y > 0.0f) {
            cubePosition.y -= .01f;
        }

        // TODO create a simulator object

        // TODO step simulator

        BeginDrawing();
        // TODO move to SimulatorView

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawCube(cubePosition, 0.5f, .5f, .5f, RED);
        DrawCubeWires(cubePosition, 0.5f, 0.5f, 0.5f, MAROON);

        DrawGrid(50, 1.0f);

        DrawCircle3D(cubePosition, 1, {1, 0, 0}, 90, BLUE);

        EndMode3D();

        DrawFPS(10, 10);

        // TODO move to property panel
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Settings");
        ImGui::Button("Test");

        ImGui::DragFloat3("Value", value);
        ImGui::End();

        rlDrawRenderBatchActive();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // TODO create a trace
        EndDrawing();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    CloseWindow();  // Close window and OpenGL context

    return 0;
}