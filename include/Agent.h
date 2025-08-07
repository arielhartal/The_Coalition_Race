#pragma once

#include <vector>
#include "Graph.h"
#include "SelectionPolicy.h"

//class Party;
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int coalitionId);
    Agent(const Agent& other);
    Agent& operator=(const Agent &other);
    Agent(Agent&& other);
    const Agent& operator=(Agent&& other);
    ~Agent();
    const int getPartyId() const;
    const int getId() const;
    SelectionPolicy* getSelectionPolicy();
    void setSelectionPolicy(SelectionPolicy* selectionPolicy);
    const int getCoalitionId() const;
    void setCoalitionId(int coalitionId);
    void step(Simulation &);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
};
