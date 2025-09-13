#pragma once

#include "PhysicsObject.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <deque>

class CelestialBody : public PhysicsObject {
    private:
        float radius;
        float mass;
        float G;
        std::string name;

        sf::Color color;
        sf::CircleShape shape;

        std::deque<Vector2> historicalPositions;
        int historyLength;

    public:
        CelestialBody();
        CelestialBody(Vector2 position, Vector2 velocity, Vector2 acceleration, float mass, float radius, sf::Color color, std::string name);
        CelestialBody(Vector2 position, Vector2 velocity, Vector2 acceleration, float mass, float radius, sf::Color color, std::string name, int historyLength);

        float getRadius() const;
        float getMass() const;
        std::string getName() const;
        float getGravity() const;
        sf::Color getColor() const;
        sf::CircleShape getShape() const;
        std::deque<Vector2> getHistoricalPositions() const;
        int getHistoryLength() const;
        
        void setRadius(float radius);
        void setMass(float mass);
        void setName(std::string name);
        void setColor(sf::Color color);
        void setHistoryLength(int historyLength);
        void draw(sf::RenderWindow& window);

        Vector2 calculateGravitationalForce(CelestialBody& other);
        void applyForce(Vector2 force);
        void resetForce();
        void addHistoricalPosition(Vector2 position);
        void clearHistoricalPositions();
        void drawHistoricalPositions(sf::RenderWindow& window);
};