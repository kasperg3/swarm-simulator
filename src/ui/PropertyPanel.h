#ifndef __PROPERTYPANEL_H__
#define __PROPERTYPANEL_H__
#include "src/sim/Simulator.h"
class PropertyPanel {
   public:
    PropertyPanel();

    void draw();

   private:
    float mCohesion = 0.5;
    float mSeparation = 0.3;
    float mAllignment = 0.2;
    float mAttractor = 0.0;
    float mRadiusToNeighbour = 5;
    glm::dvec3 mTarget;
};
#endif  // __PROPERTYPANEL_H__