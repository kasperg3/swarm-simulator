#ifndef BOIDS_H
#define BOIDS_H
#include "Robot.h"
#pragma once
namespace SwarmSim
{

    class Boids : public Robot
    {
    public:
        Boids();
        ~Boids();

        void sense(std::shared_ptr<SwarmSim::EnvironmentState>) override;
        void act() override;
        void draw() override;
        bool isNeighbouring(SwarmSim::Robot *);

        double getSeparationWeight() const { return mSeparationWeight; }
        void setSeparationWeight(float separationWeight_) { mSeparationWeight = separationWeight_; }

        double getCohesionWeight() const { return mCohesionWeight; }
        void setCohesionWeight(float cohesionWeight_) { mCohesionWeight = cohesionWeight_; }

        double getAllignmentWeight() const { return mAllignmentWeight; }
        void setAllignmentWeight(float allignmentWeight_) { mAllignmentWeight = allignmentWeight_; }

        double getAttractorWeight() const { return mAttractorWeight; }
        void setAttractorWeight(float attractorWeight_) { mAttractorWeight = attractorWeight_; }

        double getRadiusToNeighbour() const { return mRadiusToNeighbour; }
        void setRadiusToNeighbour(float radiusToNeighbour_) { mRadiusToNeighbour = radiusToNeighbour_; }

        void reset() override;

    private:
        glm::dvec3 mSeparation;
        glm::dvec3 mCohesion;
        glm::dvec3 mAllignment;
        glm::dvec3 mAttractor;
        glm::dvec3 mRepellant;

        double mCohesionWeight = 0.6f;
        double mSeparationWeight = 0.8f;
        double mAllignmentWeight = 0.3f;
        double mAttractorWeight = 0.0f;
        double mRadiusToNeighbour = 5.0f;
    };
}

#endif