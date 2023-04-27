#ifndef ROBOT_H
#define ROBOT_H

#pragma once

#include <memory>

#include "glm/glm.hpp"

namespace SwarmSim
{
    class EnvironmentState; // Forward declaration to avoid circular includes
    struct RobotAttributes
    {
        glm::dvec3 taget;
        glm::dvec3 position;
        glm::dvec3 velocity;
        glm::dvec3 heading;
    };
    class Robot
    {
    public:
        Robot();
        ~Robot();
        // Simulator logic
        virtual void sense(std::shared_ptr<EnvironmentState>) = 0;
        virtual void act() = 0;

        // Drawing/rendering
        virtual void draw();

        // Utility
        glm::dvec3 getPosition();
        glm::dvec3 getVelocity();
        glm::dvec3 getHeading();
        RobotAttributes getAttributes();
        virtual void reset() = 0;

        void setPosition(glm::dvec3 pos);
        void setVelocity(glm::dvec3 vel);
        void setHeading(glm::dvec3 head);
        std::string getId();

    protected:
        std::string uuid;
        glm::dvec3 clampMagnitude(glm::dvec3 vector, double);
        bool isNeighbouring(Robot *);
        RobotAttributes mAttributes;
    };

} // namespace SwarmSim

#endif