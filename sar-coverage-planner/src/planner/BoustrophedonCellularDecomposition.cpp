#include "BoustrophedonCellularDecomposition.h"
namespace MRCP {

BoustrophedonCellularDecomposition::BoustrophedonCellularDecomposition(std::shared_ptr<PolygonWithHoles> p)
    : PolygonDecomposition(p) {
}

BoustrophedonCellularDecomposition::~BoustrophedonCellularDecomposition() {
}

std::list<Polygon_2> BoustrophedonCellularDecomposition::decompose() {
    // TODO implement

    return std::list<Polygon_2>();
}
}  // namespace MRCP