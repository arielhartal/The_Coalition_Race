#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"


MandatesSelectionPolicy* MandatesSelectionPolicy::clone()
{
    return new MandatesSelectionPolicy(*this);
}

int MandatesSelectionPolicy::select(Simulation &s, int &partyId)
{
    int maxMandates = 0;
    int pMaxID = -1;
    // Iterating thorught each party in the graph
    for(int i = 0; i < s.getGraph().getNumVertices() ; i++)
    {
        int currentPartyMandates = s.getGraph().getParty(i).getMandates();
        if(s.getGraph().getEdgeWeight(partyId, i) != 0 && currentPartyMandates > maxMandates&& s.getGraph().getParty(i).getState() != Joined){
            
            //Checks if the party can get an offer from this agent

            bool sameCoalition = false;
            for(int offer: s.getParty(i).getOffers())
            {
                int agent_offer_id = offer;
                int coalition_agent_offer_id = s.getAgents().at(agent_offer_id).getCoalitionId();
                if(s.getGraph().getParty(partyId).getCoalitionId() == coalition_agent_offer_id)
                { // Checking if there was an offered that was made by an agent from the same coalition
                    sameCoalition = true;
                }
            }
            
            if(!sameCoalition) // If all conditions meet then current party has maximum number of mandates and we save the id
            { // of the neighboring party with the highest edge weight
                maxMandates = currentPartyMandates;
                pMaxID = s.getGraph().getParty(i).getId();
            }
        }

    }
    return pMaxID;
}