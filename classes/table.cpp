#include <iostream>
#include "table.h"
#include <cmath>

using namespace std;

// Constructor
Table::Table(int size){

    // Initializing the class
    this->size = size; 
    this->tokens = (int*)malloc(size*sizeof(int));
    this->visited = false;
    
}

// Destructor
Table::~Table(){
    delete[] this->tokens;
    delete[] this->applicableRules;
    delete this;
}

// Setters
void Table::setHashValue(int value){
    this->hashValue = value;
}

void Table::setFather(Table* father){
    this->father = father;
}

void Table::setTokens(int* tokens){
    this->tokens = tokens;
}

void Table::setIndexOfVoidSpace(int indexOfVoidSpace){
    this->indexOfVoidSpace = indexOfVoidSpace;
}

void Table::setRule(int rule){
    this->rule = rule;
}

void Table::setApplicableRules(list<int>* rules){
    this->applicableRules = rules;
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

void Table::setVisited(bool v){
    this->visited = v;
}

// Getters
int* Table::getTokens(){
    return this->tokens;
}

int Table::getSize(){
    return this->size;
}

int Table::getIndexOfVoidSpace(){
    return this->indexOfVoidSpace;
}

int Table::getHashValue(){
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

bool Table::getVisited(){
    return this->visited;
}