#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"
#include "CelestialBody.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include <string>
#include <vector>
#include <cstdio>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Orbit Simulator");
    if (!ImGui::SFML::Init(window)) {
        return -1;
    }
    
    float positionX = 640.0f;
    float positionY = 360.0f;
    float velocityX = 0.0f;
    float velocityY = 0.0f;
    float accelerationX = 0.0f;
    float accelerationY = 0.0f;
    float mass = 1.0f;
    float radius = 10.0f;
    sf::Color color = sf::Color::White;
    static char name[100] = "Celestial Body";

    static bool showAddObjectPopup = false;
    static int selectedObjectIndex = -1;

    std::vector<CelestialBody> objects;

    sf::Clock clock;

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);
            
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        sf::Time deltaTime = clock.restart();
        ImGui::SFML::Update(window, deltaTime);

        ImGui::Begin("Controls");
        if (ImGui::Button("Add Object")) {
            positionX = 640.0f;
            positionY = 360.0f;
            velocityX = 0.0f;
            velocityY = 0.0f;
            accelerationX = 0.0f;
            accelerationY = 0.0f;
            mass = 1.0f;
            radius = 10.0f;
            color = sf::Color::White;
            snprintf(name, sizeof(name), "Celestial Body");
            
            showAddObjectPopup = true;
        }

        if (showAddObjectPopup) {
            ImGui::InputText("Name", name, sizeof(name));
            ImGui::InputFloat("Position X", &positionX);
            ImGui::InputFloat("Position Y", &positionY);
            ImGui::InputFloat("Velocity X", &velocityX);
            ImGui::InputFloat("Velocity Y", &velocityY);
            ImGui::InputFloat("Acceleration X", &accelerationX);
            ImGui::InputFloat("Acceleration Y", &accelerationY);
            ImGui::InputFloat("Mass", &mass);
            ImGui::InputFloat("Radius", &radius);
            float colorFloat[3] = { color.r / 255.0f, color.g / 255.0f, color.b / 255.0f };
            if (ImGui::ColorEdit3("Color", colorFloat)) {
                color.r = static_cast<uint8_t>(colorFloat[0] * 255.0f);
                color.g = static_cast<uint8_t>(colorFloat[1] * 255.0f);
                color.b = static_cast<uint8_t>(colorFloat[2] * 255.0f);
            }

            if (ImGui::Button("Confirm")) {
                if (selectedObjectIndex != -1) {
                    objects[selectedObjectIndex] = CelestialBody(Vector2(positionX, positionY), Vector2(velocityX, velocityY), Vector2(accelerationX, accelerationY), mass, radius, color, std::string(name));
                } else {
                    objects.push_back(CelestialBody(Vector2(positionX, positionY), Vector2(velocityX, velocityY), Vector2(accelerationX, accelerationY), mass, radius, color, std::string(name)));
                }

                selectedObjectIndex = -1;
                showAddObjectPopup = false;
            }

            if (ImGui::Button("Cancel")) {
                showAddObjectPopup = false;
                selectedObjectIndex = -1;
            }
        }

        for (int index = 0; index < objects.size(); index++) {
            CelestialBody& object = objects[index];
            ImGui::PushID(index);
            ImGui::Text("%s", object.getName().c_str());
            ImGui::Text("Position: %f, %f", object.getPosition().getX(), object.getPosition().getY());

            if (ImGui::Button("Remove")) {
                objects.erase(objects.begin() + index);
                ImGui::PopID();
                break;
            }

            if (ImGui::Button("Edit")) {
                showAddObjectPopup = true;
                selectedObjectIndex = index;
                positionX = object.getPosition().getX();
                positionY = object.getPosition().getY();
                velocityX = object.getVelocity().getX();
                velocityY = object.getVelocity().getY();
                accelerationX = object.getAcceleration().getX();
                accelerationY = object.getAcceleration().getY();
                mass = object.getMass();
                radius = object.getRadius();
                color = object.getColor();
                snprintf(name, sizeof(name), "%s", object.getName().c_str());
                ImGui::PopID();
                break;
            }

            ImGui::PopID();
        }

        if (ImGui::Button("Scenario 1")) {
            objects.clear();
            objects.push_back(CelestialBody(Vector2(640.0f, 360.0f), Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f), 1000.0f, 50.0f, sf::Color::Yellow, "Sun"));
            objects.push_back(CelestialBody(Vector2(840.0f, 360.0f), Vector2(0.0f, -100.0f), Vector2(0.0f, 0.0f), 10.0f, 10.0f, sf::Color::Blue, "Planet"));
        }
        
        if (ImGui::Button("Scenario 2")) {
            objects.clear();
            objects.push_back(CelestialBody(Vector2(640.0f, 360.0f), Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f), 1000.0f, 50.0f, sf::Color::Yellow, "Sun"));
            objects.push_back(CelestialBody(Vector2(840.0f, 360.0f), Vector2(0.0f, -100.0f), Vector2(0.0f, 0.0f), 10.0f, 12.5f, sf::Color::Blue, "Planet"));
            objects.push_back(CelestialBody(Vector2(860.0f, 360.0f), Vector2(0.0f, -110.0f), Vector2(0.0f, 0.0f), 1.0f, 2.5f, sf::Color::White, "Moon"));
            objects.push_back(CelestialBody(Vector2(1000.0f, 360.0f), Vector2(0.0f, -75.0f), Vector2(0.0f, 0.0f), 7.5f, 7.5f, sf::Color::Red, "Planet 2"));
        }


        if (ImGui::Button("Clear")) {
            objects.clear();
        }

        ImGui::End();

        window.clear();


        for (CelestialBody& object : objects) {
            object.resetForce();
        }

        for (int i = 0; i < objects.size(); i++) {
            for (int j = i + 1; j < objects.size(); j++) {
                Vector2 force = objects[i].calculateGravitationalForce(objects[j]);
                
                objects[i].applyForce(force);
                objects[j].applyForce(force * -1.0f);
            }
        }

        for (CelestialBody& object : objects) {
            object.addHistoricalPosition(object.getPosition());
            object.update(deltaTime.asSeconds());
            object.draw(window);
            object.drawHistoricalPositions(window);
        }

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}