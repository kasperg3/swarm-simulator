#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#pragma once
#include <memory>

#include "raylib.h"
namespace SwarmSim {
class Environment {
   public:
    virtual void draw() {
        DrawGrid(1000, 1.0f);  // Default environment is a simple grid plane
    };

    Environment();
    ~Environment();

   private:
};

}  // namespace SwarmSim

#endif