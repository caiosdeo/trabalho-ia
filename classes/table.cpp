#include <iostream>
#include "table.h"
#include "../auxiliar_functions/aux.h"

using namespace std;

Table::Table(unsigned int size){

    // Initializing the class
    this->father = nullptr;
    this->size = size;
    this->indexOfVoidSpace = size / 2;
    this->rule = 0;
    this->tokens = new unsigned int(size);
    this->cost = 0;

    // Initializing the table
    // *NOTE: this implementation uses 0 to void spaces, 1 to white tokens and 2 to black tokens
    this->tokens[this->indexOfVoidSpace] = 0;

    // Inserting the tokens in the list
    for (int i = 0; i < this->size / 2; i++){

        this->tokens[i] = 1;
        this->tokens[this->size-1-i] = 2;

    }

    // Setting the hashValue
    this->setHashValue();

}

// Setters
void Table::setHashValue(){
    
    unsigned int sum = 0;

    for(int i = 0; i < size; i++)
        sum += tokens[i]*(i+1);

    this->hashValue = sum;
}

void Table::setFather(Table* father){
    this->father = father;
}

void Table::setTokens(unsigned int* tokens){
    this->tokens = tokens;
}

void Table::setIndexOfVoidSpace(unsigned int indexOfVoidSpace){
    this->indexOfVoidSpace = indexOfVoidSpace;
}

// Getters
unsigned int* Table::getTokens(){
    return this->tokens;
}

unsigned int Table::getSize(){
    return this->size;
}

unsigned int Table::getIndexOfVoidSpace(){
    return this->indexOfVoidSpace;
}

unsigned int Table::getHashValue(){
    return this->hashValue;
}