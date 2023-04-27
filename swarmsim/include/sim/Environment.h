#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#pragma once
#include <memory>
#include <vector>

#include "glm/glm.hpp"
#include "raylib.h"
namespace SwarmSim
{
    class Environment
    {
    public:
        virtual void draw()
        {
            DrawGrid(1000, 1.0f); // Default environment is a simple grid plane
        };

        void drawScene();

        Environment();
        ~Environment();

        std::vector<std::vector<glm::dvec2>> scene_;
        std::vector<int> scene_types_;

    private:
        enum AreaTypes
        {
            OUT_OF_BOUNDS,
            AREA_OF_OPERATION,
            PLAIN,
            FOREST,
            LAKE
        };
    };

} // namespace SwarmSim

#endif