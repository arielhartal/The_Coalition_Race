#include "../include/JoinPolicy.h"
#include "../include/Simulation.h"




LastOfferJoinPolicy* LastOfferJoinPolicy::clone()
{
    return new LastOfferJoinPolicy(*this);
}

int LastOfferJoinPolicy::join(Simulation &s, int &partyId)
{
    int last_offered_agent_id = (s.getParty(partyId)).getOffers().back(); // Getting the id of the agent that made the last offer
    int last_offered_coalition_id = s.getAgents().at(last_offered_agent_id).getCoalitionId(); // Getting the coaltion id that the agent is a memmber of
    return last_offered_coalition_id; // Returning the id of the coalition that made the last offer

}


