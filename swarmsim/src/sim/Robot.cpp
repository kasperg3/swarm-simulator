#include "sim/Robot.h"

#include <math.h>

#include <cstdlib>
#include <iostream>

#include "glm/glm.hpp"
#include "sim/SimulatorState.h"
#include "time.h"
namespace SwarmSim {
Robot::Robot() {
}

Robot::~Robot() {
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

bool Robot::isNeighbouring(Robot* robot) {
    // if the robot is not itself and is within radius
    return glm::notEqual(getPosition(), robot->getPosition()).b && glm::length(this->getPosition() - robot->getPosition()) < this->mAttributes.radiusToNeighbour;
}

}  // namespace SwarmSim