#ifndef BOUSTROPHEDONCELLULARDECOMPOSITION_H
#define BOUSTROPHEDONCELLULARDECOMPOSITION_H

#pragma once
#include "PolygonDecomposition.h"
namespace MRCP {
class BoustrophedonCellularDecomposition : public PolygonDecomposition {
   public:
    BoustrophedonCellularDecomposition(std::shared_ptr<PolygonWithHoles>);
    ~BoustrophedonCellularDecomposition();
    std::list<Polygon_2> decompose() override;

   private:
};
}  // namespace MRCP
#endif