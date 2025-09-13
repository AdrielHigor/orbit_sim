cmake_minimum_required(VERSION 3.16)
project(OrbitSimulator LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML 3.0.0 using modern CMake
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Window System)

# Configure imgui-sfml options
set(IMGUI_SFML_FIND_SFML OFF CACHE BOOL "" FORCE)
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui CACHE PATH "" FORCE)

# Add imgui-sfml subdirectory
add_subdirectory(external/imgui-sfml)

# Create executable
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/Vector2.cpp
    src/PhysicsObject.cpp
    src/CelestialBody.cpp
)

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui-sfml
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
    sfml-graphics-s
    sfml-window-s
    sfml-system-s
    ImGui-SFML::ImGui-SFML
    GL
)


