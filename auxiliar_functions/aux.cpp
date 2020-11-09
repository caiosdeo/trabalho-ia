#include <iostream>
#include <list>
#include "aux.h"

using namespace std;

char tokenChar(unsigned int token){
    
    if(token == 3)
        return '#';
    else if(token == 1)
        return 'W';
    else if(token == 2)
        return 'B';

    return '#';

}

void printTable(unsigned int* tokens, unsigned int size){

    cout << "Table: |";
    for( int i = 0; i < size; i++)
        cout << i << ": " << tokenChar(tokens[i]) << "|";
    cout << endl; 

}

void swap(unsigned int* tokens, int i, int j){

    tokens[i] = tokens[j]; // Inserts the token calculated by the rule in the void space
    tokens[j] = 3; // The void space is now the space where the token was located

}

Table* givesLight(Table* father, int rule){

    // Aux variables
    unsigned int fathersVoidSpace = father->getIndexOfVoidSpace();
    unsigned int* fathersTokens = copyTokens(father->getTokens(), father->getSize());
    // New Table
    Table* t = new Table(father->getSize());
    // Setting attributes
    t->setFather(father);
    // This is to apply the rule to its tokens array
    swap(fathersTokens,fathersVoidSpace,fathersVoidSpace-rule);
    t->setTokens(fathersTokens);
    t->setHashValue();
    t->setIndexOfVoidSpace(fathersVoidSpace-rule);
    
    return t;

}

list<int>* findApplicableRules(Table* n){


    list<int>* rules = new list<int>;
    unsigned int numberOfJumps = (n->getSize() / 2) - 1;
    unsigned int voidSpaceIndex = n->getIndexOfVoidSpace();

    // ?TOTHINK: using the x-axis as a guider to the order of the rules
    // Verifying if are space to search by the left
    if(voidSpaceIndex == 0)
        // By the right
        searchByTheRight(rules,n,numberOfJumps);
    else if(voidSpaceIndex == n->getSize()-1)
        // By the left
        searchByTheLeft(rules,n,numberOfJumps);
    else{
        searchByTheRight(rules,n,numberOfJumps);
        searchByTheLeft(rules,n,numberOfJumps);
    }

    return rules;

}

void searchByTheLeft(list<int>* rules, Table* n, unsigned int numberOfJumps){

    // This loop searches the rules by the left
    for(int counter = 0, i = n->getIndexOfVoidSpace()-1; counter <= numberOfJumps && i >= 0; i--, counter++){
        
        if(!isAncestor(n,likelyHashValue(n->getTokens(),n->getSize(),n->getIndexOfVoidSpace(),counter+1)))
            rules->push_back(counter+1);
        
    }

}

void searchByTheRight(list<int>* rules, Table* n, unsigned int numberOfJumps){


    // This loop searches the rules by the right
    for(int counter = 0, i = n->getIndexOfVoidSpace()+1; counter <= numberOfJumps && i < n->getSize(); i++, counter++){

        if(!isAncestor(n,likelyHashValue(n->getTokens(),n->getSize(),n->getIndexOfVoidSpace(),-(counter+1))))
            rules->push_back(-(counter+1));
        
    }

}

bool isAncestor(Table* n, unsigned int hashValue){

    while(n != nullptr){
        
        if(n->getHashValue() == hashValue)
            return true;

        n = n->getFather();

    }

    return false;

}

unsigned int hashValue(unsigned int* tokens, unsigned int size){

    unsigned int sum = 0;

    for(int i = 0; i < size; i++)
        sum += tokens[i]*(i+1);

    return sum;
}

unsigned int likelyHashValue(unsigned int* tokens, unsigned int size, int voidSpace, int rule){

    unsigned int* auxTokens;

    auxTokens = copyTokens(tokens, size);


    swap(auxTokens, voidSpace, voidSpace - rule);

    return hashValue(auxTokens, size);

}

unsigned int* copyTokens(unsigned int* tokens, unsigned int size){

    unsigned int* auxTokens = new unsigned int(size);

    for(int i = 0; i < size; i++)
        auxTokens[i] = tokens[i];

    return auxTokens;

}

bool checkSolution(unsigned int* tokens, unsigned int n){

    int token = tokens[0];

    if(token == 2 || tokens[n-1] == 2)
        return false; 

    for(int i = 1, flag = 0; i < n; i++){

        if(tokens[i] == 0)
            continue;

        if(tokens[i] != token && token != 0)
            flag++;

        token = tokens[i];

        if(flag > 2)
            return false;

    }

    return true;

}