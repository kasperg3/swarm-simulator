#include "Robot.h"

#include <math.h>

#include <cstdlib>
#include <iostream>

#include "SimulatorState.h"
#include "glm/glm.hpp"
#include "time.h"

Robot::Robot(int id) : mId(id) {
    mAttributes = {
        // TODO move non robot attributes into simulatorstate
        0.5,                           // cohesion
        0.3,                           // separation
        0.2,                           // allignment
        0.0,                           // attractor
        5,                             // neighbourhood
        glm::dvec3(20.0, 20.0, 20.0),  // Attractor target
        glm::dvec3((rand() % 200 - 100) / 10.0, (rand() % 200 - 100) / 10.0, (rand() % 200 - 100) / 10.0),
        glm::dvec3((rand() % 200 - 100) / 10.0, (rand() % 200 - 100) / 10.0, (rand() % 200 - 100) / 10.0),
    };
}

glm::dvec3 Robot::getPosition() {
    return this->mAttributes.position;
}

glm::dvec3 Robot::getVelocity() {
    return this->mAttributes.velocity;
}

RobotAttributes Robot::getAttributes() {
    return mAttributes;
}

void Robot::setPosition(glm::dvec3 pos) {
    mAttributes.position = std::move(pos);
}

void Robot::setVelocity(glm::dvec3 vel) {
    mAttributes.velocity = std::move(vel);
}

glm::dvec3 Robot::clampMagnitude(glm::dvec3 vector) {
    return glm::normalize(vector) * std::min(glm::length(vector), MAX_SPEED);
}

void Robot::sense(SimulatorState* state) {
    glm::dvec3 allignment(0.0, 0.0, 0.0);
    glm::dvec3 flockCenter(0.0, 0.0, 0.0);
    glm::dvec3 separation(0.0, 0.0, 0.0);
    glm::dvec3 cohesion(0.0, 0.0, 0.0);
    int neighbourCount = 0;

    for (auto&& robot : state->mRobots) {
        if (isNeighbouring(robot)) {
            neighbourCount++;
            allignment += robot.mAttributes.velocity;
            flockCenter += robot.mAttributes.position;
            separation += robot.mAttributes.position - getPosition();
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

    // TODO move this into act function
    // Weights
    double separationWeight = mAttributes.separation;
    double allignmentWeight = mAttributes.allignment;
    double cohesionWeight = mAttributes.cohesion;
    double attractorWeight = mAttributes.attractor;
    // calculate the new position:
    glm::dvec3 newVelocity = getVelocity() +
                             repellant +
                             attractorWeight * attractor +
                             separationWeight * separation +
                             cohesionWeight * cohesion +
                             allignmentWeight * allignment;

    glm::dvec3 newPosition = getPosition() + clampMagnitude(newVelocity) * DELTA_TIME;
    setPosition(newPosition);
    setVelocity(clampMagnitude(newVelocity));
}

bool Robot::isNeighbouring(Robot robot) {
    // if the robot is not itself and is within radius
    return glm::notEqual(getPosition(), robot.getPosition()).b && glm::length(this->getPosition() - robot.getPosition()) < this->mAttributes.radiusToNeighbour;
}

void Robot::act() {
    // todo seperate sense/act
}

Robot::~Robot() {
}
