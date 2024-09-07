#Coalition Race Simulation
This project is a C++ simulation of a political crisis in the fictional democracy of SPL, where politicians need help forming a coalition. The aim is to create a program that simulates the coalition-building process.

#Assignment Breakdown
The task involves designing and implementing several key classes to model the interactions and decision-making in the simulation. The main classes and their roles are as follows:

Parser: Reads and processes data from the JSON configuration file.
Simulation: Coordinates the overall simulation flow and manages its resources.
Graph: Models the structure where parties are represented as vertices, and connections between them are the edges.
Party: Represents a political entity in the graph with attributes such as id, name, mandates, join policies, and current state.
Agent: Represents an agent affiliated with a specific party, with properties like agentId, partyId, and selection policy.
SelectionPolicy: An abstract class that defines how an agent selects which party to approach.
JoinPolicy: An abstract class that outlines the logic for deciding which coalition offers to accept.
The simulation starts by initializing the setup, goes through each iteration step by step, and terminates when the conditions for coalition formation are met.
