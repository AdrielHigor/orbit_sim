# Orbit Simulator

A real-time orbital mechanics simulation built with C++ and SFML. This project demonstrates gravitational physics, n-body interactions, and orbital dynamics through an interactive graphical interface.

## Overview

This orbit simulator was developed as a C++ learning project to explore:
- Object-oriented programming concepts
- Physics simulation and numerical integration
- Real-time graphics rendering with SFML
- GUI development with ImGui
- Game development fundamentals

The simulator features gravitational force calculations between celestial bodies, orbital trail visualization, and an interactive interface for creating and modifying objects in real-time.

## Features

- **N-body gravitational simulation** with realistic force calculations
- **Interactive GUI** for adding, editing, and removing celestial bodies
- **Orbital trail visualization** showing historical paths
- **Real-time physics** with customizable parameters
- **Predefined scenarios** including Earth-Sun-Moon systems
- **Collision detection** between celestial bodies

## Dependencies

This project requires the following external libraries:

### SFML (Simple and Fast Multimedia Library)
- **Version**: 3.0.x
- **Purpose**: Graphics rendering, window management, and input handling
- **Components Used**: Graphics, System, Window modules
- **Website**: https://www.sfml-dev.org/

### ImGui (Immediate Mode GUI)
- **Version**: 1.92.x
- **Purpose**: User interface for real-time parameter adjustment
- **Features**: Input fields, buttons, color pickers, and control panels
- **Website**: https://github.com/ocornut/imgui

### ImGui-SFML Integration
- **Version**: 3.0.x (compatible with SFML version)
- **Purpose**: Bridge between ImGui and SFML for seamless GUI integration
- **Functionality**: Renders ImGui interfaces within SFML windows
- **Website**: https://github.com/SFML/imgui-sfml

**Note**: The `external/` folder containing these libraries is not included in the repository. You'll need to download and set up these dependencies manually or use a package manager.

## Building the Project

### Prerequisites
- CMake 3.10 or higher
- C++17 compatible compiler (GCC, Clang, or MSVC)
- OpenGL development libraries

### Build Instructions

1. Clone the repository:
```bash
git clone <repository-url>
cd orbit_sim
```

2. Create a build directory:
```bash
mkdir build
cd build
```

3. Configure with CMake:
```bash
cmake ..
```

4. Build the project:
```bash
make
```

5. Run the simulator:
```bash
./OrbitSimulator
```

## Usage

### Basic Controls
- **Add Object**: Click the "Add Object" button to create new celestial bodies
- **Edit Object**: Select an object from the list and click "Edit" to modify its properties
- **Remove Object**: Click "Remove" next to any object to delete it
- **Scenarios**: Use predefined scenario buttons for quick setups

### Object Properties
- **Position**: X and Y coordinates in pixels
- **Velocity**: Initial velocity components
- **Mass**: Affects gravitational influence
- **Radius**: Visual size and collision detection
- **Color**: Visual appearance
- **Name**: Object identifier

## Project Structure

```
orbit_sim/
├── src/                    # Source files
│   ├── main.cpp           # Main application loop
│   ├── CelestialBody.cpp  # Celestial body implementation
│   ├── PhysicsObject.cpp  # Base physics object
│   └── Vector2.cpp        # 2D vector mathematics
├── include/               # Header files
│   ├── CelestialBody.h
│   ├── PhysicsObject.h
│   └── Vector2.h
├── external/              # External dependencies (gitignored)
│   ├── SFML/             # Graphics library (not in repo)
│   ├── imgui/            # GUI library (not in repo)
│   └── imgui-sfml/       # SFML-ImGui integration (not in repo)
├── build/                # Build output directory
├── CMakeLists.txt        # CMake configuration
└── README.md             # Project documentation
```

## Physics Implementation

The simulator implements Newton's law of universal gravitation:

```
F = G * (m1 * m2) / r²
```

Where:
- `F` = Gravitational force
- `G` = Gravitational constant (scaled for visualization)
- `m1`, `m2` = Masses of interacting bodies
- `r` = Distance between centers

Forces are calculated between all pairs of objects and integrated using Euler's method for position and velocity updates.

## License
This project is for educational purposes and personal skill development.

---
*This README was generated with assistance from AI*
