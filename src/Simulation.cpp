#include "../include/Simulation.h"


/*Constructors*/

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), timer(0), mCoalitions(), mNumMandatesOfCoalitions() 
{
    int numOfCoalition = 0;
    //default
    // Constructing the coalitions vector
    for(Agent& agent : mAgents){
            mCoalitions.push_back({agent.getPartyId()});
            agent.setCoalitionId(numOfCoalition);
            mNumMandatesOfCoalitions.push_back(getParty(agent.getPartyId()).getMandates()); // Updating number of mandates of coalition
            mGraph.getParty(agent.getPartyId()).setCoalitionId(numOfCoalition); // Setting the coalition id
            numOfCoalition++;
    }
}

Simulation::Simulation(Graph graph, vector<Agent> agents, int timer, vector<vector<int>> coalitions, vector<int> numMandatesOfCoalitions) : mGraph(graph), mAgents(agents),
timer(0), mCoalitions(coalitions), mNumMandatesOfCoalitions(numMandatesOfCoalitions) 
{

}



void Simulation::step()
{

    // Applying step for each party and each agent
    for (Party& party : mGraph.getParties())
        party.step(*this);
    for(Agent& agent : mAgents)
        agent.step(*this);
    updateTimer(); // Updating the timer

}

bool Simulation::shouldTerminate() const
{
    bool atLeast61Mandates = false;

    // Checking if there's a coaltion with at least 61 mandates
    for(int i = 0; i < (int)mNumMandatesOfCoalitions.size(); i++)
    {
        if(mNumMandatesOfCoalitions.at(i) >= 61)
            atLeast61Mandates = true;
    }

    bool allJoined = true;
    vector<Party> parties = mGraph.getParties();

    // Checking if all parties are in joined state (if we find one that is not than the boolean variable is false)
    for(int i = 0; i < (int)parties.size(); i++)
    {
        if(parties.at(i).getState() != Joined)
            allJoined = false;
    }

    // If one of the conditions meet we terminate the program
    return atLeast61Mandates || allJoined;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

vector<Agent> &Simulation::getAgents()
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party &Simulation::getParty(int partyId)
{
    return mGraph.getParty(partyId);
}

const int &Simulation::getTimer() const
{
    return timer;
}

void Simulation::updateTimer()
{
    timer++;
}

vector<vector<int>> Simulation::getCoalitions()
{
    return mCoalitions;
}

vector<int>& Simulation::getNumMandatesOfCoalitions()
{
    return mNumMandatesOfCoalitions;
}

void Simulation::addPartyToCoalitions(int joinedCoalitionId, int partyId){

    mCoalitions.at(joinedCoalitionId).push_back(partyId); //add party
    mNumMandatesOfCoalitions[joinedCoalitionId] += getParty(partyId).getMandates();// Updating the number of mandates
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    return vector<vector<int>> (mCoalitions);
}
