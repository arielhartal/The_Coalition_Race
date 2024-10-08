# Coalition Race Simulation
This project is a C++ simulation of a political crisis in the fictional democracy of SPL, where politicians need help forming a coalition. The aim is to create a program that simulates the coalition-building process.

# Assignment Breakdown
The task involves designing and implementing several key classes to model the interactions and decision-making in the simulation. The main classes and their roles are as follows:

1. Parser: Reads and processes data from the JSON configuration file.  
2. Simulation: Coordinates the overall simulation flow and manages its resources.  
3. Graph: Models the structure where parties are represented as vertices, and connections between them are the edges.  
4. Party: Represents a political entity in the graph with attributes such as id, name, mandates, join policies, and current state.  
5. Agent: Represents an agent affiliated with a specific party, with properties like agentId, partyId, and selection policy.  
6. SelectionPolicy: An abstract class that defines how an agent selects which party to approach.  
7. JoinPolicy: An abstract class that outlines the logic for deciding which coalition offers to accept.

The simulation starts by initializing the setup, goes through each iteration step by step, and terminates when the conditions for coalition formation are met.  


# Configuration File Format

The program takes a configuration file in JSON format as input. The file contains information about parties, the graph, and agents. The structure of the configuration file is as follows:  
```cpp
{  
  "parties": [  
    {  
      "name": "Party1",  
      "mandates": 30,  
      "join_policy": "MandatesJoinPolicy"  
    },  
    {  
      "name": "Party2",  
      "mandates": 40,  
      "join_policy": "LastOfferJoinPolicy"  
    },  
    ...  
  ],  
  "graph": [  
    [0, 1, 0, 1],  
    [1, 0, 1, 0],  
    [0, 1, 0, 1],  
    [1, 0, 1, 0]  
  ],  
  "agents": [  
    {  
      "party_id": 0,  
      "selection_policy": "EdgeWeightSelectionPolicy"  
    },  
    {  
      "party_id": 1,  
      "selection_policy": "MandatesSelectionPolicy"  
    },  
    ...  
  ]  
}
```
# Termination Conditions

The program terminates when one of the coalitions reaches at least 61 mandates or when all parties have joined a coalition.

# Output

The program generates an output file in JSON format, representing the state of the simulation. The output file contains information about the parties, agents, coalitions, and the steps taken during the simulation.

# Testing

Three JSON files are provided for testing different scenarios of the program. You can compare the expected output with your actual output using the diff command in Linux.  
```cpp
diff expected_output.json actual_output.json
```


