#ifndef COVERAGEPLANNER_H
#define COVERAGEPLANNER_H

#pragma once
#include "CGALDefinitions.h"

namespace MRCP {
class CoveragePlanner {
   public:
    CoveragePlanner();
    ~CoveragePlanner();

   private:
    PolygonWithHoles polygon;
    std::list<Polygon_2> decomposedPolygon;
};

}  // namespace MRCP

#endif