#include "sim/Boids.h"

#include <math.h>

#include <cstdlib>
#include <iostream>

#include "glm/glm.hpp"
#include "raylib.h"
#include "sim/SimulatorState.h"
#include "time.h"
namespace SwarmSim {
Boids::Boids() {
    mAttributes = {
        glm::dvec3(20.0, 20.0, 20.0),  // Attractor target
        glm::dvec3((rand() % 200 - 100) / 10.0, (rand() % 200 - 100) / 10.0, (rand() % 200 - 100) / 10.0),
        glm::dvec3((rand() % 200 - 100) / 10.0, (rand() % 200 - 100) / 10.0, (rand() % 200 - 100) / 10.0),
    };
}

void Boids::sense(std::shared_ptr<SimulatorState> state) {
    glm::dvec3 allignment(0.0, 0.0, 0.0);
    glm::dvec3 flockCenter = getPosition();
    glm::dvec3 separation(0.0, 0.0, 0.0);
    glm::dvec3 cohesion(0.0, 0.0, 0.0);
    int neighbourCount = 0;

    for (auto&& robot : state->getRobots()) {
        if (isNeighbouring(robot)) {
            neighbourCount++;
            allignment += robot->getAttributes().velocity;
            flockCenter += robot->getAttributes().position;
            separation += robot->getAttributes().position - getPosition();
        }
    }

    if (neighbourCount != 0) {
        // allignment
        allignment *= 1 / neighbourCount;

        // Cohesion
        flockCenter *= 1 / neighbourCount;
        cohesion = flockCenter - getPosition();

        // Separation
        separation = -separation;
    }

    // this only works when the sphere is at 0.0
    // Repel = P0 - ((C + V) / |V|) * R
    glm::dvec3 repellant = std::abs(glm::length(getPosition())) > BOUNDING_RADIUS ? -getPosition() : glm::dvec3(0.0, 0.0, 0.0);

    glm::dvec3 attractor = glm::dvec3(mAttributes.taget - getPosition());

    // calculate the new position:
    glm::dvec3 newVelocity = getVelocity() +
                             repellant +
                             //  attractorWeight * attractor +
                             getSeparationWeight() * separation +
                             getCohesionWeight() * cohesion +
                             getAllignmentWeight() * allignment;

    glm::dvec3 newPosition = getPosition() + clampMagnitude(newVelocity) * DELTA_TIME;
    setPosition(newPosition);
    setVelocity(clampMagnitude(newVelocity));
}

void Boids::act() {
    // todo seperate sense/act
}

bool Boids::isNeighbouring(Robot* robot) {
    // if the robot is not itself and is within radius
    return glm::notEqual(getPosition(), robot->getPosition()).b && glm::length(this->getPosition() - robot->getPosition()) < getRadiusToNeighbour();
}
Boids::~Boids() {
}

void Boids::draw() {
    // Draw the default model
    Robot::draw();
    glm::dvec3 pos = getPosition();
    Vector3 rlPos = {(float)pos.x, (float)pos.y, (float)pos.z};
    DrawCircle3D(rlPos, getRadiusToNeighbour(), {1, 0, 0}, -90, LIGHTGRAY);
}

}  // namespace SwarmSim
