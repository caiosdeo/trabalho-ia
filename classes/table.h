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
        Table(int size);
        ~Table();
        // Getters
        Table* getFather();
        Table* getSon();
        unsigned int* getTokens(); 
        unsigned getIndexOfVoidSpace();

};

#endif //TABLE_H_INCLUDED