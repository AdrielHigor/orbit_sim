#include "CelestialBody.h"
#include <string>

CelestialBody::CelestialBody() : PhysicsObject() {
    this->radius = 0.0f;
    this->mass = 0.0f;
    this->G = 2000.0f;
    this->color = sf::Color::White;
    this->name = "Celestial Body";
    this->historyLength = 5000;
    shape.setRadius(0.0f);
    shape.setFillColor(color);
    shape.setOrigin({0.0f, 0.0f});
    shape.setPosition({0.0f, 0.0f});
}

CelestialBody::CelestialBody(Vector2 position, Vector2 velocity, Vector2 acceleration, float mass, float radius, sf::Color color, std::string name) : PhysicsObject(position, velocity, acceleration) {
    this->radius = radius;
    this->mass = mass;
    this->G = 2000.0f;
    this->color = color;
    this->name = name;
    this->historyLength = 5000;
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin({radius, radius});
    shape.setPosition({position.getX(), position.getY()});
}

CelestialBody::CelestialBody(Vector2 position, Vector2 velocity, Vector2 acceleration, float mass, float radius, sf::Color color, std::string name, int historyLength) : PhysicsObject(position, velocity, acceleration) {
    this->radius = radius;
    this->mass = mass;
    this->G = 2000.0f;
    this->color = color;
    this->name = name;
    this->historyLength = historyLength;
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin({radius, radius});
    shape.setPosition({position.getX(), position.getY()});
}

float CelestialBody::getRadius() const {
    return radius;
}

float CelestialBody::getMass() const {
    return mass;
}

float CelestialBody::getGravity() const {
    return G * mass / (radius * radius);
}

sf::Color CelestialBody::getColor() const {
    return color;
}

sf::CircleShape CelestialBody::getShape() const {
    return shape;
}

int CelestialBody::getHistoryLength() const {
    return historyLength;
}

std::deque<Vector2> CelestialBody::getHistoricalPositions() const {
    return historicalPositions;
}

void CelestialBody::setHistoryLength(int historyLength) {
    this->historyLength = historyLength;
}

void CelestialBody::setRadius(float radius) {
    this->radius = radius;
}

void CelestialBody::setMass(float mass) {
    this->mass = mass;
}

void CelestialBody::setColor(sf::Color color) {
    this->color = color;
}

void CelestialBody::setName(std::string name) {
    this->name = name;
}

void CelestialBody::addHistoricalPosition(Vector2 position) {
    historicalPositions.push_back(position);
    if (historicalPositions.size() > historyLength) {
        historicalPositions.pop_front();
    }
}

void CelestialBody::clearHistoricalPositions() {
    historicalPositions.clear();
}

void CelestialBody::draw(sf::RenderWindow& window) {
    Vector2 position = getPosition();
    shape.setPosition({position.getX(), position.getY()});
    shape.setFillColor(color);
    shape.setRadius(radius);
    window.draw(shape);
}

std::string CelestialBody::getName() const {
    return name;
}

Vector2 CelestialBody::calculateGravitationalForce(CelestialBody& other) {
    Vector2 direction = other.getPosition() - this->getPosition();
    float distance = direction.magnitude();

    if (distance < (this->getRadius() + other.getRadius()) || distance < 1.0f) {
        return Vector2(0.0f, 0.0f);
    }

    float force = G * mass * other.getMass() / (distance * distance);
    return direction.normalized() * force;
}

void CelestialBody::applyForce(Vector2 force) {
    Vector2 acceleration = force / mass;
    setAcceleration(getAcceleration() + acceleration);
}

void CelestialBody::resetForce() {
    setAcceleration(Vector2(0.0f, 0.0f));
}

void CelestialBody::drawHistoricalPositions(sf::RenderWindow& window) {
    sf::VertexArray vertices(sf::PrimitiveType::LineStrip, historicalPositions.size());
    for (int i = 0; i < historicalPositions.size(); i++) {
        vertices[i].position = {historicalPositions[i].getX(), historicalPositions[i].getY()};
        vertices[i].color = color;
    }
    window.draw(vertices);
}