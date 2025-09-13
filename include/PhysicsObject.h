#pragma once

#include "Vector2.h"
#include <SFML/Graphics.hpp>

class PhysicsObject {
    private:
        Vector2 position;
        Vector2 velocity;
        Vector2 acceleration;

    public:
        PhysicsObject();
        PhysicsObject(Vector2 position, Vector2 velocity, Vector2 acceleration);
        Vector2 getPosition() const;
        Vector2 getVelocity() const;
        Vector2 getAcceleration() const;
        
        void setPosition(Vector2 position);
        void setVelocity(Vector2 velocity);
        void setAcceleration(Vector2 acceleration);

        void update(float deltaTime);
};
