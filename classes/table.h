#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
#include <list>

using namespace std;

class Table{
    // ! Pay attention on this attributes and methods
    private:
        int size;
        Table* father;
        int* tokens;
        int indexOfVoidSpace;
        int rule; // Rule that generates the atual state
        list<int>* applicableRules;
        int cost; // ?TOTHINK: the cost is the number of tokens hopped plus one || the rule plus one
        int hashValue;
        int heuristicValue;
        int functionValue;

    public:
        // Constructor 
        Table(int size);
        // Destructor
        ~Table();
        // Getters
        Table* getFather();
        int* getTokens();
        int getSize();
        int getIndexOfVoidSpace();
        int getHashValue();
        int getRule();
        int getCost();
        int getHeuristic();
        int getFunctionValue();
        list<int>* getApplicableRules();
        // Setters
        void setHashValue(int value);       
        void setFather(Table* father);
        void setTokens(int* tokens);
        void setIndexOfVoidSpace(int indexOfVoidSpace);
        void setRule(int rule);
        void setApplicableRules(list<int>* rules); //? Can generate errors
        void setCost(int rule);
        void setHeuristic(int h);
        void setFunctionValue(int value);

};

#endif // TABLE_H_INCLUDED