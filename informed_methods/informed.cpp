#include "informed.h"
#include "../auxiliar_functions/aux.h"
#include <iostream>
#include <iterator>

using namespace std;

Table* greedySearch(Table* root){

    // Defining open list and pushing root node to it
    vector<Table*> open;
    Table* N, *U;
    open.push_back(root);
    // Defining closed list
    list<Table*> closed;
    bool sucess = false, failure = false; 

    // While not sucess or failure
    while(!(sucess || failure)){

        if(open.empty())
            failure = true;

        else{

            N = getsTableWithMinorHeuristic(&open);

            if(checkSolution(N->getTokens(),N->getSize()))
                sucess = true;

            else{

                // List of possibles operators to N
                list<int>* rules = N->getApplicableRules();

                while(!rules->empty()){

                    // Picking first operator
                    int rule = rules->back();
                    rules->pop_back();
                    // Generating new node and inserting it in the open list
                    U = givesLight(N, rule);
                    open.push_back(U);

                }
                // Inserting N in the closed list
                closed.push_front(N);

            }

        }

    }

    return N;

}