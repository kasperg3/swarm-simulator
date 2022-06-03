#ifndef ROBOT_H
#define ROBOT_H

#pragma once

class SimulatorState;  // Forward declaration to avoid circular includes

#include <memory>

#include "glm/glm.hpp"
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
    Robot(int id);
    glm::dvec3 getPosition();
    glm::dvec3 getVelocity();
    RobotAttributes getAttributes();
    void sense(SimulatorState*);
    void act();
    ~Robot();

   private:
    void setPosition(glm::dvec3 pos);
    void setVelocity(glm::dvec3 vel);
    glm::dvec3 clampMagnitude(glm::dvec3 vector);
    bool isNeighbouring(Robot);
    int mId;
    RobotAttributes mAttributes;
};

#endif