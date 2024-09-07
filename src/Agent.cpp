#include "../include/Agent.h"
#include "../include/Simulation.h"
#include "../include/SelectionPolicy.h"


/*Constructors*/

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(-1)
{
    
}

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int coalitionId) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalitionId(coalitionId)
{
    
}

/*Rule Of Five*/

// copy constructor
Agent::Agent(const Agent& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy->clone()), mCoalitionId(other.mCoalitionId)
{

}

// copy assignment
Agent& Agent::operator=(const Agent &other)
{
    if(this != &other)
    {
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        delete mSelectionPolicy;
        mSelectionPolicy = other.mSelectionPolicy->clone();
        mCoalitionId = other.mCoalitionId;
    }
    return *this;
}

// move constructor
Agent::Agent(Agent&& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), mCoalitionId(other.mCoalitionId)
{
    other.mSelectionPolicy = nullptr;
}

// move assignment
const Agent& Agent::operator=(Agent&& other)
{
    other.mSelectionPolicy = nullptr;
    return *this;
}

// destructor
Agent::~Agent()
{
    if(mSelectionPolicy)
        delete mSelectionPolicy;

    mSelectionPolicy = nullptr;
}

const int Agent::getId() const
{
    return mAgentId;
}

const int Agent::getPartyId() const
{
    return mPartyId;
}

SelectionPolicy* Agent::getSelectionPolicy()
{
    return mSelectionPolicy;
}

void Agent::setSelectionPolicy(SelectionPolicy* selectionPolicy)
{
    mSelectionPolicy = selectionPolicy;
}

const int Agent::getCoalitionId() const
{
    return mCoalitionId;
}

void Agent::setCoalitionId(int coalitionId)
{
    mCoalitionId = coalitionId;
}

void Agent::step(Simulation &sim)
{
        int offeredParty = mSelectionPolicy->select(sim, mPartyId); // Selecting a party to offer by policy
        if (offeredParty != -1) // if If there is an offer
        {
            sim.getParty(offeredParty).addOffer(mAgentId, sim); 
            // Adding an offer to the  party
        }
}