#ifndef __PROPERTYPANEL_H__
#define __PROPERTYPANEL_H__
#include <memory>

#include "../sim/Simulator.h"
#include "Widget.h"
namespace SwarmSim
{

    class PropertyPanel : public SwarmSim::Widget
    {
    public:
        PropertyPanel();

        void draw() override;
        void update(std::shared_ptr<SwarmSim::EnvironmentState>) override;

        bool getRestart() const { return mRestart; }
        void setRestart(bool mRestart_) { mRestart = mRestart_; }

    private:
        bool mRestart;
        float mCohesion = 0.6;
        float mSeparation = 0.8;
        float mAllignment = 0.3;
        float mAttractor = 0.0;
        float mRadiusToNeighbour = 5;
        glm::dvec3 mTarget;
    };
}

#endif // __PROPERTYPANEL_H__