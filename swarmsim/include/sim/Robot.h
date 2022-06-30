#ifndef ROBOT_H
#define ROBOT_H

#pragma once

#include <memory>

#include "glm/glm.hpp"

namespace SwarmSim {
class SimulatorState;  // Forward declaration to avoid circular includes
// TODO the attributes should be all the static configs, others should be contained in robot
struct RobotAttributes {
    float cohesion;
    float separation;
    float allignment;
    float attractor;
    float radiusToNeighbour;
    glm::dvec3 taget;
    glm::dvec3 position;
    glm::dvec3 velocity;
};
class Robot {
   public:
    Robot();
    ~Robot();
    // TODO this is dirty, make them pure virtual
    virtual void sense(SimulatorState*){};
    virtual void act(){};

    glm::dvec3 getPosition();
    glm::dvec3 getVelocity();
    RobotAttributes getAttributes();

   protected:
    void setPosition(glm::dvec3 pos);
    void setVelocity(glm::dvec3 vel);
    glm::dvec3 clampMagnitude(glm::dvec3 vector);
    bool isNeighbouring(Robot*);
    RobotAttributes mAttributes;
};

}  // namespace SwarmSim

#endif