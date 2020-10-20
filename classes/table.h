#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

using namespace std;

class Table{

    private:
        unsigned int size;
        Table* father;
        //Table* son; maybe sons will be better
        unsigned int* tokens;
        unsigned int indexOfVoidSpace;
        //bool controlRoles[4];
        //bool avaliableRoles;
        //unsigned int cost;
        //unsigned int hashValue;

    public:
        // Constructor and destructor
        Table(unsigned int size, unsigned int indexOfVoidSpace);
        ~Table();
        // Getters
        Table* getFather();
        Table* getSon();
        unsigned int* getTokens(); 
        //unsigned getIndexOfVoidSpace();
        // Other methods goes here
        void setInitialState();
        //bool checkAvaliableRoles();
        //bool isAncestor();
        //Table* givesLight();
        //Table* givesLight(unsigned int controlRole);
        // I think these methods here can be written as auxiliary functions and not inner methods

};

#endif //TABLE_H_INCLUDED