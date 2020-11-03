#include <iostream>
#include "table.h"

using namespace std;

Table::Table(unsigned int size){

    // Initializing the class
    this->father = nullptr;
    this->size = size;
    this->indexOfVoidSpace = size / 2;
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

    for(int i = 0; i < this->size; i++)
        sum += this->tokens[i]*(i+1);

    this->hashValue = sum;
}

// Getters
unsigned int* Table::getTokens(){
    return this->tokens;
}