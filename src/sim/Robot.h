#ifndef ROBOT_H
#define ROBOT_H

#pragma once
#include "glm/glm.hpp"

struct RobotAttributes {
    float maxSpeed;
    float minSpeed;
    glm::dvec3 mPosition;
    glm::dvec3 mVelocity;
    glm::dvec3 mDirection;
};

class Robot {
   public:
    Robot();
    Robot(RobotAttributes);
    glm::dvec3 getPosition();
    void update();
    ~Robot();

   private:
    RobotAttributes mAttributes;
};

#endif