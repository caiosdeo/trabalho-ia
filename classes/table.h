#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
#include <list>

using namespace std;

class Table{

    private:
        unsigned int size;
        Table* father;
        unsigned int* tokens;
        unsigned int indexOfVoidSpace;
        int rule; // Rule that generates the atual state
        list<int>* applicableRules;
        unsigned int cost; // ?TOTHINK: the cost is the number of tokens hopped plus one || the rule plus one
        unsigned int hashValue;
        int heuristicValue;

    public:
        // Constructor and destructor
        Table(unsigned int size);
        ~Table();
        // Getters
        Table* getFather();
        unsigned int* getTokens();
        unsigned int getSize();
        unsigned int getIndexOfVoidSpace();
        unsigned int getHashValue();
        int getRule();
        int getCost();
        int getHeuristic();
        list<int>* getApplicableRules();
        // Setters
        void setHashValue();       
        void setFather(Table* father);
        void setTokens(unsigned int* tokens);
        void setIndexOfVoidSpace(unsigned int indexOfVoidSpace);
        void setRule(int rule);
        void setApplicableRules(); //? Can generate errors
        void setCost(int rule);
        void setHeuristic(int h);
        // Other methods
        char tokenChar(unsigned int token);
        void freeTable();

};

#endif // TABLE_H_INCLUDED