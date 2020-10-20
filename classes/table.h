#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

using namespace std;

class Table{

    private:
        unsigned int size;
        Table* father;
        Table* son;
        unsigned int* tokens;
        unsigned int indexOfVoidSpace;

    public:
        // Constructor and destructor
        Table(unsigned int size);
        ~Table();
        // Getters
        Table* getFather();
        Table* getSon();
        unsigned int* getTokens(); 
        unsigned getIndexOfVoidSpace();
        // Other methods goes here
        void printTable();
        void setInitialState();
        void givesLight();
        // I think these methods here can be written as auxiliary functions and not inner methods

};

#endif // TABLE_H_INCLUDED