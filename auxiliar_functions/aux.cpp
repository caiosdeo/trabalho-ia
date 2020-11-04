#include <iostream>
#include "aux.h"

using namespace std;

void printTable(unsigned int* tokens, unsigned int size){

    cout << "Table:\n|";
    for( int i = 0; i < size; i++)
        cout << i << ": " << tokens[i] << "|";
    cout << endl; 

}

void swap(unsigned int* tokens, int i, int j){

    tokens[i] = tokens[j]; // Inserts the token calculated by the rule in the void space
    tokens[j] = 0; // The void space is now the space where the token was located

}

Table* givesLight(Table* father, int rule){

    unsigned int fathersVoidSpace = father->getIndexOfVoidSpace();
    unsigned int* fathersTokens = father->getTokens();
    Table* t = new Table(father->getSize());
    t->setFather(father);
    swap(fathersTokens,fathersVoidSpace,fathersVoidSpace-rule);
    t->setTokens(fathersTokens);
    t->setHashValue();
    t->setIndexOfVoidSpace(fathersVoidSpace-rule);
    return t;

}