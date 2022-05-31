#include "Robot.h"

#include <cstdlib>
#include <iostream>

#include "time.h"
Robot::Robot() {
    srand(time(NULL));
    std::cout << "constructing robot" << std::endl;
    // TODO remove this
    mAttributes = {
        2.0,
        0.0,
        glm::dvec3(0.0, 0.0, 0.0),
        glm::dvec3(0.0, 0.0, 0.0),
        glm::dvec3(0.0, 0.0, 0.0),
    };
}

Robot::Robot(RobotAttributes attr) : mAttributes(attr) {
}

glm::dvec3 Robot::getPosition() {
    return this->mAttributes.mPosition;
}

void Robot::update() {
    std::cout << "pos before: " << getPosition().x << std::endl;
    this->mAttributes.mPosition = mAttributes.mPosition + glm::dvec3((rand() % 100) / 100.0, (rand() % 100) / 100.0, (rand() % 100) / 100.0);
    std::cout << "pos after: " << getPosition().x << std::endl;
}

Robot::~Robot() {
}