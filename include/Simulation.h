#pragma once

#include <vector>


#include "Agent.h"



using std::string;
using std::vector;


class Graph;
class Agent;
class Party;
class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    Simulation(Graph g, vector<Agent> agents, int timer, vector<vector<int>> coalition, vector<int> numMandatesOfCoalitions);
    Simulation(const Simulation& other);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    vector<Agent> &getAgents();
    const Party &getParty(int partyId) const;
    Party &getParty(int partyId);
    const int &getTimer() const;
    void updateTimer();
    vector<vector<int>> getCoalitions();
    vector<int>& getNumMandatesOfCoalitions();
    const vector<vector<int>> getPartiesByCoalitions() const;
    void addPartyToCoalitions(int joinedCoalitionId, int partyId);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    int timer;
    vector<vector<int>> mCoalitions;
    vector<int> mNumMandatesOfCoalitions;
};
