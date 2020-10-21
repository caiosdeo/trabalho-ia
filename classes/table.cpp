#include "table.h"

Table::Table(unsigned int size){

    // Initializing the class
    this->father = nullptr;
    this->sons = nullptr;
    this->size = size;
    this->indexOfVoidSpace = indexOfVoidSpace;
    this->tokens = new unsigned int(size);
    this->cost = 0;

    // Initializing the table
    // *NOTE: this implementation uses 0 to void spaces, 1 to white tokens and 2 to black tokens
    this->tokens[this->indexOfVoidSpace] = 0;

    // Inserting the tokens in the list
    for (int i = 0; i < this->size / 2; i++){

        this->tokens[i] = 1;
        this->tokens[size-1-i] = 2;

    }

    // Setting the hashValue
    this->setHashValue();

}

void Table::setHashValue(){

    unsigned int sum = 0;

    for(int i = 0; i < this->size; i++)
        sum += this->tokens[i]*(i+1);

    this->hashValue = sum;

}