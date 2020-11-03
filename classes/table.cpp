#include <iostream>
#include "table.h"

using namespace std;

Table::Table(unsigned int size){

    // Initializing the class
    this->father = nullptr;
    this->sons = nullptr;
    this->size = size;
    this->indexOfVoidSpace = indexOfVoidSpace;
    this->tokens = new unsigned int(size);
    // Initializing the table
    // *NOTE: this implementation uses 0 to void spaces, 1 to white tokens and 2 to black tokens
    this->tokens[this->indexOfVoidSpace] = 0;
    // Inserting the tokens in the list
    for (int i = 0; i < this->size / 2; i++){

        this->tokens[i] = 1;
        this->tokens[this->size-1-i] = 2;

    }

}

void Table::printTable(){

    cout << "Table:\n|";
    for( int i = 0; i < this->size; i++)
        cout << i << ": " << this->tokens[i] << "|";
    cout << endl; 

}