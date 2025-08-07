#include "../include/JoinPolicy.h"
#include "../include/Simulation.h"



MandatesJoinPolicy* MandatesJoinPolicy::clone()
{
    return new MandatesJoinPolicy(*this);
}

int MandatesJoinPolicy::join(Simulation &s, int &partyId)
{
    int maxMandates = 0;
    int cMax;
    vector<int>& numMandatesOfCoalitions = s.getNumMandatesOfCoalitions();
    for(int& offer : s.getParty(partyId).getOffers()) // Iterating thorugh the offers that were made to the party
    {
        int agent_offer_id = offer;
        int current_coalition_id = s.getAgents().at(agent_offer_id).getCoalitionId(); // Getting the coalition id of the coalition that made an offer
        int currentCoalitionMandates = numMandatesOfCoalitions.at(current_coalition_id); // Getting the number of mandates of that coalition
        if(currentCoalitionMandates > maxMandates){ // Checking if the current coalition has maximum number of mandates
            maxMandates = currentCoalitionMandates;
            cMax = current_coalition_id;
        }
    }

    return cMax; // Returning the coalition with the maximum number of mandates
}