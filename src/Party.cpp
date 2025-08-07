#include "../include/Party.h"
#include "../include/Simulation.h"
#include "../include/JoinPolicy.h"
#include "../include/Agent.h"
#include "../include/SelectionPolicy.h"

/*Constructors*/

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mCoalitionId(), mOffers(), Mtime()
{
    mCoalitionId = -1;
}

Party::Party(int id, string name, int mandates, JoinPolicy *jp, int coalitionId, vector<int> offers, int time) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mCoalitionId(coalitionId),
mOffers(offers), Mtime(time)
{
    
}

/*Rule Of Five*/

// copy constructor
Party::Party(const Party& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()),
mState(other.mState), mCoalitionId(other.mCoalitionId), mOffers(other.mOffers), Mtime(other.Mtime)
{

}

// copy assignment
Party& Party::operator=(const Party &other)
{
    if(this != &other)
    {
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        delete mJoinPolicy;
        mJoinPolicy = other.mJoinPolicy->clone();
        mCoalitionId = other.mCoalitionId;
        mState = other.mState;
        mOffers = other.mOffers;
        
    }
    return *this;
}

// move constructor
Party::Party(Party&& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy),
mState(other.mState), mCoalitionId(other.mCoalitionId), mOffers(other.mOffers), Mtime(other.Mtime)
{
    other.mJoinPolicy = nullptr;
}

// move assignment
const Party& Party::operator=(Party&& other)
{
    other.mJoinPolicy = nullptr;
    return *this;
}

// destructor
Party::~Party()
{
    if(mJoinPolicy)
        delete mJoinPolicy;

    mJoinPolicy = nullptr;
}



State Party::getState() const
{
    return mState;
}

int Party::getId() const
{
    return mId;
}

int Party::getCoalitionId() const
{
    return mCoalitionId;
}

void Party::setCoalitionId(int coalitionId){
    mCoalitionId = coalitionId;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}
vector<int> &Party::getOffers()
{
    return mOffers;
}

void Party::cloneAgent(int joinedCoalition, Simulation &s)
{
    /* Cloning Agent */
    int cloneAgentId = s.getAgents().size();
    Agent cloneAgent(cloneAgentId, mId, s.getAgents().at(joinedCoalition).getSelectionPolicy()->clone(), 0); // Constructing the cloned agent and cloning the selection policy
    cloneAgent.setCoalitionId(s.getAgents().at(joinedCoalition).getCoalitionId());
    s.getAgents().push_back(cloneAgent); 
}


void Party::step(Simulation &s)
{
    
    if(this->mState == CollectingOffers){ 
        if(s.getTimer() - Mtime == 3){ //Checks if time is up
            int joinedCoalition = mJoinPolicy->join(s, mId); // Selects a coalition by policy
            setState(Joined); // Setting the party state to joined
            cloneAgent(joinedCoalition, s); // Cloning agent
            this->setCoalitionId(joinedCoalition); // update the coaltion id
            s.addPartyToCoalitions(joinedCoalition, mId);
        }
    }
}
void Party::setTimer(int time)
{
    Mtime = time;
}


// Function that is adding an offer to the vector<int> of offers in each Party
void Party::addOffer(int agentId, Simulation &s){
    if (Waiting == mState)
    {   setState(CollectingOffers); 
        setTimer(s.getTimer()); // Starting the cooldown 
        mOffers.push_back(agentId); // Adding an offer
    }
    else if (mState == CollectingOffers)   
        mOffers.push_back(agentId);
}
