cmake_minimum_required(VERSION 3.6)
add_library(
        imgui STATIC
        imconfig.h
        imgui.h imgui.cpp
        imgui_impl_glfw.h  imgui_impl_glfw.cpp
        imgui_impl_opengl3_loader.h
        imgui_impl_opengl3.h imgui_impl_opengl3.cpp
        imgui_widgets.cpp
        imgui_draw.cpp
        imgui_demo.cpp
        imgui_tables.cpp
        )
