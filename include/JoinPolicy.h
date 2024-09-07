#pragma once


class Simulation;

class JoinPolicy {
    public:
        JoinPolicy(){}
        virtual JoinPolicy* clone() = 0;
        virtual int join(Simulation &s, int &partyId){return 0;}
        virtual ~JoinPolicy(){}
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        MandatesJoinPolicy(){}
        MandatesJoinPolicy* clone();
        virtual ~MandatesJoinPolicy(){}
        virtual int join(Simulation &s, int &partyId);
        

};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        LastOfferJoinPolicy(){}
        LastOfferJoinPolicy* clone();
        virtual ~LastOfferJoinPolicy(){}
        virtual int join(Simulation &s, int &partyId);
               
};
