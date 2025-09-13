#include "PhysicsObject.h"

PhysicsObject::PhysicsObject() {
    position = Vector2(0.0f, 0.0f);
    velocity = Vector2(0.0f, 0.0f);
    acceleration = Vector2(0.0f, 0.0f);
}

PhysicsObject::PhysicsObject(Vector2 position, Vector2 velocity, Vector2 acceleration) {
    this->position = position;
    this->velocity = velocity;
    this->acceleration = acceleration;
}

Vector2 PhysicsObject::getPosition() const {
    return position;
}

Vector2 PhysicsObject::getVelocity() const {
    return velocity;
}

Vector2 PhysicsObject::getAcceleration() const {
    return acceleration;
}

void PhysicsObject::setPosition(Vector2 position) {
    this->position = position;
}

void PhysicsObject::setVelocity(Vector2 velocity) {
    this->velocity = velocity;
}

void PhysicsObject::setAcceleration(Vector2 acceleration) {
    this->acceleration = acceleration;
}

void PhysicsObject::update(float deltaTime) {
    position += velocity * deltaTime;
    velocity += acceleration * deltaTime;
}