#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
#include <queue>

using namespace std;

class Table{

    private:
        unsigned int size;
        Table* father;
        unsigned int* tokens;
        unsigned int indexOfVoidSpace;
        int rule; // Rule that generates the atual state
        unsigned int cost; // ?TOTHINK: the cost is the number of tokens hopped plus one || the rule plus one
        unsigned int hashValue;

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
        // Setters
        void setHashValue();       
        void setFather(Table* father);
        void setTokens(unsigned int* tokens);
        void setIndexOfVoidSpace(unsigned int indexOfVoidSpace);

};

#endif // TABLE_H_INCLUDED