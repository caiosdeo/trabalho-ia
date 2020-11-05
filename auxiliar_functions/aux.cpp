#include <iostream>
#include <list>
#include "aux.h"

using namespace std;

char tokenChar(unsigned int token){
    
    switch(token){
        case 0:
            return '-';
        case 1:
            return 'W';
        case 2:
            return 'B';
        default:
            break;
    }
}

void printTable(unsigned int* tokens, unsigned int size){

    cout << "Table:\n|";
    for( int i = 0; i < size; i++)
        cout << i << ": " << tokenChar(tokens[i]) << "|";
    cout << endl; 

}

void swap(unsigned int* tokens, int i, int j){

    tokens[i] = tokens[j]; // Inserts the token calculated by the rule in the void space
    tokens[j] = 0; // The void space is now the space where the token was located

}

Table* givesLight(Table* father, int rule){

    // Aux variables
    unsigned int fathersVoidSpace = father->getIndexOfVoidSpace();
    unsigned int* fathersTokens = father->getTokens();
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

list<int> findApplicableRules(Table* n){

    list<int> rules;
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

void searchByTheLeft(list<int> rules, Table* n, unsigned int numberOfJumps){

    // This loop searches the rules by the left
    for(int counter = 0, i = n->getIndexOfVoidSpace(); counter < numberOfJumps && i > 0; i--, counter++){

        if(!isAncestor(n,hashValue(n->getTokens(),n->getSize())))
            rules.push_front(counter);

    }

}

void searchByTheRight(list<int> rules, Table* n, unsigned int numberOfJumps){

    // This loop searches the rules by the right
    for(int counter = 0, i = n->getIndexOfVoidSpace(); counter < numberOfJumps && i < n->getSize(); i++, counter--){

        if(!isAncestor(n,hashValue(n->getTokens(),n->getSize())))
            rules.push_front(counter);

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

    for(int i = 0; i < size; i++)
        auxTokens[i] = tokens[i];

    swap(auxTokens, voidSpace, voidSpace-rule);

    return hashValue(auxTokens, size);

}