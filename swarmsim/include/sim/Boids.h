#ifndef BOIDS_H
#define BOIDS_H
#include "Robot.h"
#pragma once
namespace SwarmSim {

class Boids : public Robot {
   public:
    Boids();
    ~Boids();

    void sense(std::shared_ptr<SimulatorState>) override;
    void act() override;
    void draw() override;
    bool isNeighbouring(Robot*);

    double getSeparationWeight() const { return separationWeight; }
    void setSeparationWeight(float separationWeight_) { separationWeight = separationWeight_; }

    double getCohesionWeight() const { return cohesionWeight; }
    void setCohesionWeight(float cohesionWeight_) { cohesionWeight = cohesionWeight_; }

    double getAllignmentWeight() const { return allignmentWeight; }
    void setAllignmentWeight(float allignmentWeight_) { allignmentWeight = allignmentWeight_; }

    double getAttractorWeight() const { return attractorWeight; }
    void setAttractorWeight(float attractorWeight_) { attractorWeight = attractorWeight_; }

    double getRadiusToNeighbour() const { return radiusToNeighbour; }
    void setRadiusToNeighbour(float radiusToNeighbour_) { radiusToNeighbour = radiusToNeighbour_; }

   private:
    double cohesionWeight = 0.5f;
    double separationWeight = 0.3f;
    double allignmentWeight = 0.2f;
    double attractorWeight = 0.0f;
    double radiusToNeighbour = 5.0f;
};
}  // namespace SwarmSim

#endif