#include <iostream>
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
        cout << tokenChar(tokens[i]) << "|";
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
    t->setRule(rule);
    t->setApplicableRules();
    
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
        searchByTheRight(rules, n, numberOfJumps);
    else if(voidSpaceIndex == n->getSize()-1)
        // By the left
        searchByTheLeft(rules, n, numberOfJumps);
    else{
        searchByTheRight(rules, n, numberOfJumps);
        searchByTheLeft(rules, n, numberOfJumps);
    }

    return rules;

}

void searchByTheLeft(list<int>* rules, Table* n, unsigned int numberOfJumps){

    // This loop searches the rules by the left
    for(int counter = 0, i = n->getIndexOfVoidSpace()-1; counter <= numberOfJumps && i >= 0; i--, counter++){
        

        // 0 - likelyHashValue
        // 1 - likelyTokens
        // 2 - likelyVoidSpace
        tuple<unsigned, unsigned*, unsigned> likely = likelyHashValue(n->getTokens(), n->getSize(), n->getIndexOfVoidSpace(), counter+1);

        if(!isAncestor(n, get<0>(likely), get<1>(likely), get<2>(likely)))
            rules->push_back(counter+1);
        
    }

}

void searchByTheRight(list<int>* rules, Table* n, unsigned int numberOfJumps){


    // This loop searches the rules by the right
    for(int counter = 0, i = n->getIndexOfVoidSpace()+1; counter <= numberOfJumps && i < n->getSize(); i++, counter++){

        tuple<unsigned, unsigned*, unsigned> likely = likelyHashValue(n->getTokens(),n->getSize(),n->getIndexOfVoidSpace(),-(counter+1));

        if(!isAncestor(n, get<0>(likely), get<1>(likely), get<2>(likely)))
            rules->push_back(-(counter+1));
        
    }

}

bool isAncestor(Table* n, unsigned int hashValue, unsigned int* tokens, unsigned int newIndexOfVoidSpace){

    while(n != nullptr){
        
        if(n->getHashValue() == hashValue){

            if(newIndexOfVoidSpace == n->getIndexOfVoidSpace()){

                int size = n->getSize();
                unsigned int* auxTokens = n->getTokens();

                if(tokensEquality(tokens,auxTokens,size))
                    return true;

            }
            
        }
        
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

tuple<unsigned, unsigned*, unsigned> likelyHashValue(unsigned int* tokens, unsigned int size, int voidSpace, int rule){

    unsigned int* auxTokens;

    auxTokens = copyTokens(tokens, size);

    swap(auxTokens, voidSpace, voidSpace - rule);

    return make_tuple(hashValue(auxTokens, size), auxTokens, voidSpace - rule);

}

unsigned int* copyTokens(unsigned int* tokens, unsigned int size){

    unsigned int* auxTokens = (unsigned*)calloc(size, sizeof(unsigned));

    for(int i = 0; i < size; i++)
        auxTokens[i] = tokens[i];

    return auxTokens;

}

bool checkSolution(unsigned int* tokens, unsigned int n){

    // aux token for comparison
    int token = tokens[0];

    // if start or end of tokens is black
    // it cant be a solution
    if(token == 2 || tokens[n-1] == 2)
        return false; 

    int flag = 0;

    // searching on the array
    for(int i = 1; i < n; i++){

        // if token equals to 3 we skip one iteraction
        if(tokens[i] == 3)
            continue;

        // if the color changes we count it
        if(tokens[i] != token && token != 3)
            flag++;

        token = tokens[i];

        // the solution can only changes color
        // on the array twice
        if(flag > 2)
            return false;

    }
    
    // if it changed color once it means that its not a solution
    if(flag == 1)
        return false;

    return true;

}

stack<int>* getSolution(Table* n){

    stack<int>* s = new stack<int>;

    while(n != nullptr){

        s->push(n->getRule());
        n = n->getFather();

    }

    return s;

}

void printStack(stack<int>* s){

    while(!s->empty()){

        int n = s->top();
        cout << ruleChar(n) << " ";
        s->pop();
        
    }

    cout << endl;

}

// ! Rules are based on void movement
string ruleChar(int rule){

    if(rule > 0)
        return 'E' + to_string(abs((rule - 1)));
    else 
        return 'D' + to_string(abs(-rule - 1));

}

bool tokensEquality(unsigned int* tokens, unsigned int* auxTokens, unsigned int n){

    for(int i = 0; i < n/2; i++)            
        if(auxTokens[i] != tokens[i] || auxTokens[n-1-i] != tokens[n-1-i])
            return false;   

    return true;

}

Table* getsTableWithMinorCost(vector<Table*> *vec){

    int minor = 0;

    for(int i = 1; i < vec->size(); i++){

        if(vec->at(minor)->getCost() > vec->at(i)->getCost())
            minor = i;

    }
    
    Table* aux = vec->at(minor);
    vec->erase(vec->begin() + minor);
    return aux;

}

Table* getsTableWithMinorHeuristic(vector<Table*> *vec){

    int minor = 0;

    for(int i = 1; i < vec->size(); i++){

        if(vec->at(minor)->getHeuristic() > vec->at(i)->getHeuristic())
            minor = i;

    }
    
    Table* aux = vec->at(minor);
    vec->erase(vec->begin() + minor);
    return aux;

}

// ?TOTHINK: the heuristic will be the biggest group of black tokens in the table
// ?TOTHINK: modifies this function to keep the start and end ids of the group.
int getBiggestGroupHeuristic(unsigned int* tokens, unsigned size){

    int biggestGroupSize = 0;
    int auxGroupSize = 0;
    unsigned int auxTokens[size-1];

    for(int i = 0, j = 0; i < size; i++)
        if(tokens[i] != 3){
            auxTokens[j] = tokens[i];
            j++;
        }

    for(int i = 0; i < size - 1; i++){


        bool whiteFollowedByBlack = auxTokens[i] == 1 && auxTokens[i+1] == 2;
        
        if(whiteFollowedByBlack){

            i++;

            while(auxTokens[i] == 2){
                    auxGroupSize++;
                i++;
            }

            if(auxTokens[i] == 1){
                biggestGroupSize = (biggestGroupSize < auxGroupSize) ? auxGroupSize : biggestGroupSize;
                auxGroupSize = 0;   
            }
            
        }

    }

    return size/2 - biggestGroupSize;

}

// ?TOTHINK: the heuristic will be the number of color changes in the table
int getColorChangeHeuristic(unsigned int* tokens, unsigned size){

    int flag  = 0;

    for(int i = 1; i < size; i++){

        if(tokens[i] == 3 || tokens[i-1] == 3)
            continue;

        if(tokens[i] != tokens[i-1])
            flag++;

    }

    return flag;

}