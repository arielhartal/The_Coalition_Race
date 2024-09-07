#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *jp); 
    Party(int id, string name, int mandates, JoinPolicy *jp, int coalitionId, vector<int> offers, int time);
    Party();
    Party(const Party& other);
    Party& operator=(const Party &other);
    Party(Party&& other);
    const Party& operator=(Party&& other);
    ~Party();
    State getState() const;
    int getId() const;
    int getCoalitionId() const;
    void setCoalitionId(int coalitionId);
    void setState(State state);
    int getMandates() const;
    vector<int> &getOffers();
    void cloneAgent(int joinedCoalition, Simulation &s);
    void step(Simulation &s);
    const string &getName() const;
    void setTimer(int time);
    void addOffer(int agentId, Simulation &s);
    

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mCoalitionId;
    vector<int> mOffers;
    int Mtime;
};
