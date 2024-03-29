#include "Boids.h"

#include <math.h>

#include <cstdlib>
#include <iostream>

#include "EnvironmentState.h"
#include "core/Log.h"
#include "glm/glm.hpp"
#include "raylib.h"
#include "time.h"
#define MAX_SPEED 10.0
#define DELTA_TIME 0.1
#include "core/Random.h"

namespace SwarmSim
{

    Boids::Boids()
    {
        reset();
    }

    void Boids::sense(std::shared_ptr<SwarmSim::EnvironmentState> state)
    {
        glm::dvec3 allignment(0.0, 0.0, 0.0);
        glm::dvec3 flockCenter(0.0, 0.0, 0.0);
        glm::dvec3 separation(0.0, 0.0, 0.0);
        glm::dvec3 cohesion(0.0, 0.0, 0.0);
        int neighbourCount = 0;

        for (auto &&robot : state->getRobots())
        {
            if (isNeighbouring(robot.second))
            {
                neighbourCount++;
                allignment += robot.second->getVelocity();
                flockCenter += robot.second->getPosition();
                separation += robot.second->getPosition() - getPosition();
            }
        }
        if (neighbourCount > 0)
        {
            // allignment
            allignment *= 1.0 / neighbourCount;

            // Cohesion
            flockCenter *= 1.0 / neighbourCount;
            cohesion = flockCenter - getPosition();

            // Separation
            separation = -separation * (1.0 / neighbourCount);
            // TODO Implement leadership/Eccentricity: https://onlinelibrary.wiley.com/doi/pdf/10.1002/cav.123
        }

        // this only works when the sphere is at 0.0
        // TODO for other locations than centre use this formula: Repel = P0 - ((C + V) / |V|) * R
        mRepellant = std::abs(glm::length(getPosition())) > BOUNDING_RADIUS ? -getPosition() * 0.01 : glm::dvec3(0.0, 0.0, 0.0);

        mAttractor = glm::dvec3(mAttributes.taget - getPosition());
        mSeparation = separation;
        mAllignment = allignment;
        mCohesion = cohesion;
    }

    void Boids::act()
    {
        // calculate the new velocity:
        glm::dvec3 newVelocity = getVelocity() +
                                 mRepellant +
                                 mAttractorWeight * mAttractor +
                                 getSeparationWeight() * mSeparation +
                                 getCohesionWeight() * mCohesion +
                                 getAllignmentWeight() * mAllignment;

        // act:
        setVelocity(clampMagnitude(newVelocity, MAX_SPEED));
        setPosition(getPosition() + getVelocity() * DELTA_TIME);
    }

    bool Boids::isNeighbouring(Robot *robot)
    {
        bool result = false;
        // if the robot is not itself and is within radius
        if (glm::all(glm::notEqual(getPosition(), robot->getPosition())) &&
            glm::length(this->getPosition() - robot->getPosition()) < getRadiusToNeighbour())
        {
            // Only consider neighbours that within 0.8PI angle
            glm::vec3 A = this->getVelocity();
            glm::vec3 B = robot->getPosition() - this->getPosition();
            float angle = glm::acos(glm::dot(glm::normalize(A), glm::normalize(B)));
            if (angle < PI * 0.8)
            {
                result = true;
            }
        }
        return result;
    }

    void Boids::reset()
    {
        mAttributes = {
            glm::dvec3(20.0, 20.0, 20.0), // Attractor target
            glm::dvec3(
                Util::randomDouble(-20, 20),
                Util::randomDouble(-20, 20),
                Util::randomDouble(-20, 20)), // Position
            glm::dvec3(
                Util::randomDouble(-1, 1),
                Util::randomDouble(-1, 1),
                Util::randomDouble(-1, 1)), // Velocity
        };
    }

    Boids::~Boids()
    {
    }

    void Boids::draw()
    {
        // Draw the default model
        Robot::draw();
        glm::dvec3 pos = getPosition();
        Vector3 rlPos = {(float)pos.x, (float)pos.y, (float)pos.z};
        DrawCircle3D(rlPos, getRadiusToNeighbour(), {1, 0, 0}, -90, LIGHTGRAY);
    }
}
