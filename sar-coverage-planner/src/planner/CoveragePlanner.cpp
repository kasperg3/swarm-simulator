#include "CoveragePlanner.h"

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Partition_traits_2.h>
#include <CGAL/Polygon_with_holes_2.h>
#include <CGAL/partition_2.h>
#include <CGAL/property_map.h>

#include "BCD.h"
#include "CGALconfig.h"
#include "Log.h"
#include "decomposition.h"
namespace MRCP {

CoveragePlanner::CoveragePlanner() {
    MRCP::Log::Init();

    // create a polygon with three holes
    Polygon_2 outer_polygon;
    outer_polygon.push_back(Point_2(0, 0));
    outer_polygon.push_back(Point_2(9, 0));
    outer_polygon.push_back(Point_2(6, 8));
    outer_polygon.push_back(Point_2(5, 3));
    outer_polygon.push_back(Point_2(2, 8));
    outer_polygon.push_back(Point_2(0, 8));
    std::vector<Polygon_2> holes(3);
    holes[0].push_back(Point_2(6, 2));
    holes[0].push_back(Point_2(7, 1));
    holes[0].push_back(Point_2(7, 3));
    holes[0].push_back(Point_2(6, 3));
    holes[0].push_back(Point_2(5, 2));
    holes[1].push_back(Point_2(2, 1));
    holes[1].push_back(Point_2(3, 1));
    holes[1].push_back(Point_2(3, 3));
    holes[1].push_back(Point_2(2, 2));
    holes[1].push_back(Point_2(1, 2));
    holes[2].push_back(Point_2(1, 4));
    holes[2].push_back(Point_2(2, 4));
    holes[2].push_back(Point_2(2, 5));
    holes[2].push_back(Point_2(3, 5));
    holes[2].push_back(Point_2(3, 6));
    holes[2].push_back(Point_2(1, 6));
    PolygonWithHoles p(outer_polygon);
    p.add_hole(holes[0]);
    p.add_hole(holes[1]);
    p.add_hole(holes[2]);

    std::vector<Polygon_2> result;

    if (computeBestBCDFromPolygonWithHoles(p, &result)) {
        MRCP_CORE_INFO("BCD computed {} cells", result.size());
    }
}

CoveragePlanner::~CoveragePlanner() {
}

}  // namespace MRCP