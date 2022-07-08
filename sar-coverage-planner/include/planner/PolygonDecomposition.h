#ifndef POLYGONDECOMPOSITION_H
#define POLYGONDECOMPOSITION_H

#pragma once
#include <memory>

#include "CGALDefinitions.h"

namespace MRCP {
class PolygonDecomposition {
   public:
    PolygonDecomposition(std::shared_ptr<PolygonWithHoles> p) { polygonPtr = p; };

    ~PolygonDecomposition(){};

    virtual std::list<Polygon_2> decompose() = 0;

   private:
    std::shared_ptr<PolygonWithHoles> polygonPtr;
};
}  // namespace MRCP
#endif