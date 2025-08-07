#pragma once



class Simulation;

class SelectionPolicy {
    public:
        SelectionPolicy(){}
        virtual SelectionPolicy* clone() = 0;
        virtual int select(Simulation &s, int &partyId){return 0;}
        virtual ~SelectionPolicy(){}
};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy(){}
        MandatesSelectionPolicy* clone();
        virtual ~MandatesSelectionPolicy(){}
        virtual int select(Simulation &s, int &partyId);

 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
        EdgeWeightSelectionPolicy(){}
        EdgeWeightSelectionPolicy* clone();
        virtual ~EdgeWeightSelectionPolicy(){}
        virtual int select(Simulation &s, int &partyId);
};
