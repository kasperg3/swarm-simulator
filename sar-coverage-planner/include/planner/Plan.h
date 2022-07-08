#ifndef PLAN_H
#define PLAN_H

#pragma once
#include "CGALDefinitions.h"
namespace MRCP {
class Plan {
   public:
    Plan(std::list<Polygon_2> p) { plan = p; };
    ~Plan();

   private:
    std::list<Polygon_2> plan;
};

}  // namespace MRCP
#endif