# The Coalition Race Simulation

A C++ simulation of coalition formation in political scenarios, implementing various agent strategies and policies for joining and selecting coalitions.

## 🎯 Project Overview

This project simulates a political coalition race where different parties (agents) attempt to form coalitions based on various strategies. The simulation uses graph theory to represent relationships between parties and implements multiple policies for decision-making.

## 🏗️ Project Structure

```
├── include/             # Header files
│   ├── Agent.h         # Agent base class and implementations
│   ├── Graph.h         # Graph data structure for party relationships
│   ├── JoinPolicy.h    # Policies for joining coalitions
│   ├── Party.h         # Party class definition
│   ├── SelectionPolicy.h # Policies for selecting parties
│   ├── Simulation.h    # Main simulation controller
│   ├── Parser.h        # JSON configuration parser
│   └── json.hpp        # JSON library
├── src/                # Source files
│   ├── Agent.cpp
│   ├── Graph.cpp
│   ├── Party.cpp
│   ├── Simulation.cpp
│   ├── Parser.cpp
│   ├── main.cpp
│   ├── EdgeWeightSelectionPolicy.cpp
│   ├── LastOfferJoinPolicy.cpp
│   ├── MandatesJoinPolicy.cpp
│   └── MandatesSelectionPolicy.cpp
├── bin/                # Compiled binaries (created during build)
├── makefile           # Build configuration
└── Assignment1_v3.pdf # Project specification
```

## 🚀 Getting Started

### Prerequisites

- C++ compiler with C++11 support (g++)
- Make utility
- JSON configuration files for simulation input

### Building the Project

1. Clone the repository:
```bash
git clone https://github.com/arielhartal/The_Coalition_Race.git
cd The_Coalition_Race
```

2. Build the project:
```bash
make
```

This will create the executable `bin/cRace`.

3. Clean build files (optional):
```bash
make clean
```

### Running the Simulation

```bash
./bin/cRace <config_path>
```

Where `<config_path>` is the path to your JSON configuration file.

**Example:**
```bash
./bin/cRace config1.json
```

The simulation will:
- Read the configuration from the specified JSON file
- Run the coalition formation simulation
- Output the results to a `.out` file with the same name as the input file

## 📋 Configuration Format

The simulation expects a JSON configuration file with the following structure:
- Graph representation of party relationships
- Party definitions with mandates and policies
- Agent configurations with selection and join policies

## 🎮 Features

### Agent Types
- **Coalition Agent**: Forms coalitions based on specific strategies
- Different agent implementations with varying behaviors

### Selection Policies
- **Mandates Selection Policy**: Selects parties based on mandate count
- **Edge Weight Selection Policy**: Selects parties based on graph edge weights

### Join Policies
- **Mandates Join Policy**: Decides to join based on mandate considerations
- **Last Offer Join Policy**: Considers the most recent offer for joining

### Graph Structure
- Represents relationships between political parties
- Weighted edges indicate coalition compatibility or preference
- Supports various graph operations for coalition analysis

## 🔧 Technical Details

- **Language**: C++11
- **Build System**: Make
- **Data Format**: JSON for input/output
- **Architecture**: Object-oriented design with policy pattern implementation
- **Memory Management**: RAII principles and proper resource management

## 📊 Output

The simulation generates:
- Step-by-step coalition formation process
- Final coalition states
- JSON output files with complete simulation history

## 🏫 Academic Context

This project is part of SPL (Systems Programming Laboratory) coursework, focusing on:
- Object-oriented programming in C++
- Design patterns implementation
- Graph algorithms and data structures
- JSON parsing and data serialization
- Build systems and project organization

## 📝 License

This project is developed for academic purposes as part of university coursework.

## 👥 Contributing

This is an academic project. Please refer to your course guidelines regarding collaboration and contribution policies.

---

**Note**: This simulation is designed for educational purposes and demonstrates concepts in systems programming, object-oriented design, and political science modeling.
