#include "table.h"

Table::Table(unsigned int size, unsigned int indexOfVoidSpace){

    // Initializing the class
    this->father = nullptr;
    //this->son = nullptr;
    this->size = size;
    this->indexOfVoidSpace = indexOfVoidSpace;
    this->tokens = new unsigned int(size);

}

void Table::setInitialState(){

    // NOTE: this implementation uses 0 to void spaces, 1 to white tokens and 2 to black tokens
    this->tokens[this->indexOfVoidSpace] = 0;
    // Inserting the tokens in the list
    for (int i = 0; i < size / 2; i++){

        tokens[i] = 1;
        tokens[size-1-i] = 2;

    }

}