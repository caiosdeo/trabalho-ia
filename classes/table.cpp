#include <iostream>
#include "table.h"
#include "../auxiliar_functions/aux.h"
#include <cmath>

using namespace std;

// TODO: destructor of the table
// Constructor
Table::Table(unsigned int size){

    // Initializing the class
    this->father = nullptr;
    this->size = size;
    this->indexOfVoidSpace = size / 2;
    this->rule = 0;
    this->tokens = (unsigned*)malloc(size*sizeof(unsigned));
    this->cost = 0;
    this->functionValue = 0;

    // Initializing the table
    // *NOTE: this implementation uses 0 to void spaces, 1 to white tokens and 2 to black tokens
    this->tokens[this->indexOfVoidSpace] = 3;

    // Inserting the tokens in the list
    for (int i = 0; i < this->size / 2; i++){

        this->tokens[i] = 1;
        this->tokens[this->size-1-i] = 2;

    }

    // Setting the hashValue
    this->setHashValue();
    // Setting applicable rules
    this->setApplicableRules();
    // Setting the heuristic value
    this->setHeuristic(getBiggestGroupHeuristic(this->getTokens(),this->getSize()));

}
// ! This is causing a big problem and do not solved the other one 
// ?TOTHINK: how to do this?
// Destructor
Table::~Table(){

}

void Table::freeTable(){
    delete this->tokens;
}

// Setters
// TODO: rethink hash value
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

void Table::setRule(int rule){
    this->rule = rule;
}

void Table::setApplicableRules(){
    this->applicableRules = findApplicableRules(this);
}

void Table::setCost(int rule){
    this->cost = abs(rule);
}

void Table::setHeuristic(int h){
    this->heuristicValue = h;
}

void Table::setFunctionValue(int value){
    this->functionValue = value;
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

Table* Table::getFather(){
    return this->father;
}

int Table::getRule(){
    return this->rule;
}

list<int>* Table::getApplicableRules(){
    return this->applicableRules;
}

int Table::getCost(){
    return this->cost;
}

int Table::getHeuristic(){
    return this->heuristicValue;
}

int Table::getFunctionValue(){
    return this->functionValue;
}