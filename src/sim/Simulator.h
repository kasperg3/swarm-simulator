#ifndef SIMULATOR_H
#define SIMULATOR_H

#pragma once

#include <list>

#include "Robot.h"

class Simulator {
   public:
    Simulator();
    ~Simulator();

   private:
    std::list<Robot> robots;
};

#endif