#include <iostream>
#include "aux.h"

using namespace std;

char tokenChar(int token){
    
    if(token == 3)
        return '#';
    else if(token == 1)
        return 'W';
    else if(token == 2)
        return 'B';

    return '@';

}

void printTable(int* tokens, int size){

    cout << "|";
    for( int i = 0; i < size; i++)
        cout << tokenChar(tokens[i]) << "|";
    cout << endl; 

}

void swap(int* tokens, int i, int j){

    tokens[i] = tokens[j]; // Inserts the token calculated by the rule in the void space
    tokens[j] = 3; // The void space is now the space where the token was located

}

Table* givesLight(Table* father, int rule){

    // New Table
    Table* t = new Table(father->getSize());

    // Aux variables
    int* sonsTokens = t->getTokens();
    int fathersVoidSpace = father->getIndexOfVoidSpace();
    copyTokens(father->getTokens(), sonsTokens, father->getSize());

    // Setting attributes
    t->setFather(father);

    // Apply the rule to sons' tokens array
    swap(sonsTokens, fathersVoidSpace, fathersVoidSpace-rule);

    // Initializing attributes
    t->setTokens(sonsTokens);
    t->setHashValue(hashValue(sonsTokens,t->getSize()));
    t->setIndexOfVoidSpace(fathersVoidSpace-rule);
    t->setRule(rule);
    t->setApplicableRules(findApplicableRules(t));
    t->setCost(father->getCost()+rule);
    t->setFunctionValue(t->getCost()+t->getHeuristic());
    
    return t;

}

// ! Maybe this function change the parameters
list<int>* findApplicableRules(Table* n){

    // Auxiliar variables
    int auxTokens[n->getSize()];
    list<int>* rules = new list<int>;
    int numberOfJumps = (n->getSize() / 2) - 1;
    int voidSpaceIndex = n->getIndexOfVoidSpace();

    // We use the x-axis as a guider to the order of the rules
    // Verifying if there are space to search 
    if(voidSpaceIndex == 0)
        // By the right
        searchByTheRight(rules, n, numberOfJumps, auxTokens);
    else if(voidSpaceIndex == n->getSize()-1)
        // By the left
        searchByTheLeft(rules, n, numberOfJumps, auxTokens);
    else{
        searchByTheRight(rules, n, numberOfJumps, auxTokens);
        searchByTheLeft(rules, n, numberOfJumps, auxTokens);
    }

    return rules;

}

void searchByTheLeft(list<int>* rules, Table* n, int numberOfJumps, int* auxTokens){

    // This loop searches the rules by the left
    for(int counter = 0, i = n->getIndexOfVoidSpace()-1; counter <= numberOfJumps && i >= 0; i--, counter++){
        
        // It's necessary to get the possible hash value and void index
        tuple<int, int> likely = likelyHashValue(n->getTokens(), auxTokens, n->getSize(), n->getIndexOfVoidSpace(), counter+1);

        // Checking if there's not a previous node with the same tokens, if not we consider as a possible rule
        if(!isAncestor(n, get<0>(likely), auxTokens, get<1>(likely)))
            rules->push_back(counter+1);
        
    }

}

void searchByTheRight(list<int>* rules, Table* n, int numberOfJumps, int* auxTokens){


    // This loop searches the rules by the right
    for(int counter = 0, i = n->getIndexOfVoidSpace()+1; counter <= numberOfJumps && i < n->getSize(); i++, counter++){

        // It's necessary to get the possible hash value and void index
        tuple<int, int> likely = likelyHashValue(n->getTokens(), auxTokens, n->getSize(), n->getIndexOfVoidSpace(), -(counter+1));

        // Checking if there's not a previous node with the same tokens, if not we consider as a possible rule
        if(!isAncestor(n, get<0>(likely), auxTokens, get<1>(likely)))
            rules->push_back(-(counter+1));
        
    }

}

bool isAncestor(Table* n, int hashValue, int* tokens, int newIndexOfVoidSpace){

    int size;
    int* auxTokens;

    // We go from the node until the root of the tree
    while(n != nullptr){
        
        // With equal hash values, a collision is possible
        if(n->getHashValue() == hashValue){

            // Same index of the void means that this is likely to be a collision
            // but it is not deterministic
            if(newIndexOfVoidSpace == n->getIndexOfVoidSpace()){

                size = n->getSize();
                auxTokens = n->getTokens();

                // To truly check if is a collision we compare the tokens' array
                if(tokensEquality(tokens, auxTokens, size))
                    return true;
                
            }
            
        }
        
        n = n->getFather();

    }

    return false;

}

int hashValue(int* tokens, int size){

    int sum = 0;

    // Adding 1 to index we multiply it to tokens value
    for(int i = 0; i < size; i++)
        sum += tokens[i]*(i+1);

    return sum;
}

tuple<int, int> likelyHashValue(int* tokens, int* likelyTokens, int size, int voidSpace, int rule){

    // copying the array so that we do not interfere with its integrity
    copyTokens(tokens, likelyTokens, size);

    // apply the possible rule
    swap(likelyTokens, voidSpace, voidSpace - rule);

    return make_tuple(hashValue(likelyTokens, size), voidSpace - rule);

}

void copyTokens(int* tokens, int* copiedTokens, int size){

    for(int i = 0; i < size; i++)
        copiedTokens[i] = tokens[i];

}

bool checkSolution(int* tokens, int n){

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

stack<int>* getSolution(Table* n, Table* root){

    stack<int>* s = new stack<int>;

    // going from the solution node to the root
    while(n != root){

        // the rule applied to the node is pushed to a stack
        s->push(n->getRule());
        n = n->getFather();

    }

    return s;

}

tuple<string,int> printStack(stack<int>* s){

    int cost = 0;
    int n;
    string path = "";
    // going through the stack of solution rules
    while(!s->empty()){

        // print the top of the stack
        n = s->top();
        path += ruleChar(n) + " ";
        
        // add to the cost of the solution 
        cost += abs(n);
        
        s->pop();
        
    }

    cout << endl;

    return make_tuple(path, cost);
}

// ! Rules are based on void movement
string ruleChar(int rule){

    // Hence positive values moves the tokens to the right and negative to the left
    // we indicate in this string how many you need to move the token
    if(rule > 0)
        return 'D' + to_string(rule - 1);
    else 
        return 'E' + to_string(abs(rule) - 1);

}

bool tokensEquality(int* tokens, int* auxTokens, int n){

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

Table* getsTableWithMinorFunctionValue(vector<Table*> *vec){

    int minor = 0;

    for(int i = 1; i < vec->size(); i++){

        if(vec->at(minor)->getFunctionValue() > vec->at(i)->getFunctionValue())
            minor = i;

    }
    
    Table* aux = vec->at(minor);
    vec->erase(vec->begin() + minor);
    return aux;

}

int getBiggestGroupHeuristic(int* tokens, int size){

    int biggestGroupSize = 0;
    int auxGroupSize = 0;
    int auxTokens[size-1];

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

void setInitialState(Table* root){

    // auxliar variables
    int size =  root->getSize();
    int* auxTokens = root->getTokens();

    // initial void position is in the middle of the table
    auxTokens[root->getIndexOfVoidSpace()] = 3;

    // Inserting the tokens in the table
    for (int i = 0; i < size / 2; i++){

        auxTokens[i] = 1;
        auxTokens[size-1-i] = 2;

    }

}