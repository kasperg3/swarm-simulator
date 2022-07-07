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
namespace SwarmSim {
Robot::Robot() {
}

Robot::~Robot() {
}

void Robot::draw() {
    auto pos = getPosition();
    Vector3 rlPos = {(float)pos.x, (float)pos.y, (float)pos.z};

    // TODO draw a triangle instead
    auto direction = glm::normalize(getVelocity());
    DrawCube(rlPos, 0.5f, .5f, .5f, RED);
    DrawCubeWires(rlPos, 0.5f, 0.5f, 0.5f, MAROON);
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

glm::dvec3 Robot::clampMagnitude(glm::dvec3 vector, double max = 10.0) {
    return glm::normalize(vector) * std::min(glm::length(vector), max);
}

}  // namespace SwarmSim