#include "informed.h"
#include "../auxiliar_functions/aux.h"
#include <iostream>
#include <iterator>

using namespace std;

Table* greedySearch(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs){

    // Defining open list and pushing root node to it
    vector<Table*> open;
    Table* N, *U;
    open.push_back(root);
    bool success = false, failure = false;
    list<int>* rules;
    int rule; 

    // While not success or failure
    while(!(success || failure)){

        if(open.empty())
            failure = true;

        else{

            N = getsTableWithMinorHeuristic(&open);
            (*visitedNodes)++;
            N->setVisited(true);

            if(checkSolution(N->getTokens(), N->getSize())){

                success = true;
                (*numberOfLeafs) += open.size();
                break;

            }

            else{

                // List of possibles operators to N
                rules = N->getApplicableRules();

                if(rules->empty())
                    (*numberOfLeafs)++;

                while(!rules->empty()){

                    // Picking first operator
                    rule = rules->back();
                    rules->pop_back();
                    // Generating new node and inserting it in the open list
                    U = givesLight(N, rule);
                    open.push_back(U);
                    (*expandedNodes)++;

                }

            }

        }

    }

    return N;

}

Table* AStarSearch(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs){

    // Defining open list and pushing root node to it
    vector<Table*> open;
    Table* N, *U;
    open.push_back(root);
    bool success = false, failure = false;
    list<int>* rules;
    int rule;  

    // While not success or failure
    while(!(success || failure)){

        if(open.empty())
            failure = true;

        else{

            N = getsTableWithMinorFunctionValue(&open);
            (*visitedNodes)++;
            N->setVisited(true);

            if(checkSolution(N->getTokens(), N->getSize())){

                success = true;
                (*numberOfLeafs) += open.size();
                break;

            }

            else{

                // List of possibles operators to N
                rules = N->getApplicableRules();

                if(rules->empty())
                    (*numberOfLeafs)++;

                while(!rules->empty()){

                    // Picking first operator
                    int rule = rules->back();
                    rules->pop_back();
                    // Generating new node and inserting it in the open list
                    U = givesLight(N, rule);
                    open.push_back(U);
                    (*expandedNodes)++;

                }

            }

        }

    }

    return N;   

}

Table* IDAStarSearch(Table* root){

    Table* N = root;
    Table* aux;
    list<Table*> discarded;
    bool success = false, failure = false, isFirst = true; 
    int level = root->getHeuristic(), oldLevel = -1, minorDiscardedLevel;

    // While not success or failure
    while(!(success || failure)){

        if(oldLevel == level)
            failure = true;

        else{

            if(checkSolution(N->getTokens(), N->getSize()) && N->getFunctionValue() <= level){
                success = true;
                break;

            }
            else{

                if(N->getFunctionValue() > level){

                    aux = N;
                    N = N->getFather();
                    discarded.push_back(aux);
                }

                // List of possibles operators to N
                list<int>* rules = N->getApplicableRules();

                if(!rules->empty()) {

                    // Picking first operator
                    int rule = rules->front();
                    rules->pop_front();
                    N = givesLight(N, rule);
                    rules = nullptr;

                }
                else{

                    if(N == root){

                        oldLevel = level;

                        list<Table*>::iterator it = discarded.begin();
                        minorDiscardedLevel = (*it)->getFunctionValue();
                        ++it;
                        for(; it != discarded.end(); ++it)
                            if((*it)->getFunctionValue() < minorDiscardedLevel)
                                minorDiscardedLevel = (*it)->getFunctionValue();
                        
                        level = minorDiscardedLevel;
                    }
                    else
                        N = N->getFather();

                }

            }

        }

    }

    return N;   
    
}