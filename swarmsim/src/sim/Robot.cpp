#include "sim/Robot.h"

#include <math.h>

#include <cstdlib>
#include <iostream>
#include <random>

#include "core/Log.h"
#include "core/Random.h"
#include "glm/glm.hpp"
#include "raylib.h"
#include "sim/EnvironmentState.h"
#include "time.h"
#include "Robot.h"
namespace SwarmSim
{
    Robot::Robot()
    {
    }

    Robot::~Robot()
    {
    }

    void Robot::draw()
    {
        auto pos = getPosition();
        auto head = getHeading();
        auto headPoint = pos + head * 2.0; // 2 meters long

        Vector3 rlPos = {(float)pos.x, (float)pos.y, (float)pos.z};
        Vector3 rlHead = {(float)headPoint.x, (float)headPoint.y, (float)headPoint.z};

        // TODO draw a triangle instead
        // auto direction = glm::normalize(getVelocity());
        DrawCube(rlPos, 0.5f, 0.5f, 0.5f, RED);
        DrawCubeWires(rlPos, 0.5f, 0.5f, 0.5f, MAROON);
        DrawLine3D(rlPos, rlHead, MAROON);
    }

    glm::dvec3 Robot::getPosition()
    {
        return this->mAttributes.position;
    }

    glm::dvec3 Robot::getVelocity()
    {
        return this->mAttributes.velocity;
    }

    glm::dvec3 Robot::getHeading()
    {
        return this->mAttributes.heading;
    }

    RobotAttributes Robot::getAttributes()
    {
        return mAttributes;
    }

    void Robot::setPosition(glm::dvec3 pos)
    {
        mAttributes.position = std::move(pos);
    }

    void Robot::setVelocity(glm::dvec3 vel)
    {
        mAttributes.velocity = std::move(vel);
    }

    void Robot::setHeading(glm::dvec3 head)
    {
        mAttributes.heading = std::move(head);
    }

    std::string Robot::getId()
    {
        return uuid;
    }
    glm::dvec3 Robot::clampMagnitude(glm::dvec3 vector, double max = 10.0)
    {
        return glm::normalize(vector) * std::min(glm::length(vector), max);
    }

} // namespace SwarmSim