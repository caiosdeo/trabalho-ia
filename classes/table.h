#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
#include <queue>

using namespace std;

class Table{

    private:
        unsigned int size;
        Table* father;
        Table* sons;  //TODO: remove sons attribute 
        unsigned int* tokens;
        unsigned int indexOfVoidSpace;
        queue<int> rules; //TODO: remove rules attribute
        int rule; // Rule that generates the atual state
        unsigned int cost; // ?TOTHINK: the cost is the number of tokens hopped plus one
        unsigned int hashValue; //TODO: the hashValue is defined by a sum of the color value times its index

    public:
        // Constructor and destructor
        Table(unsigned int size);
        ~Table();
        // Getters
        Table* getFather();
        // Setters
        void setHashValue();
        // Other methods goes here
        void givesLight(Table* father, unsigned int rule);

};

#endif //TABLE_H_INCLUDED