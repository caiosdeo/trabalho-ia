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
    bool success = false, failure = false, isFirst = true; 
    int level = root->getHeuristic(), oldLevel = -1;
    int auxLevel = level;
    int auxFunctionValue;
    cout << "lvl inicial: " << level << endl;
    // While not success or failure
    while(!(success || failure)){

        if(oldLevel == level)
            failure = true;

        else{

            if(checkSolution(N->getTokens(), N->getSize()) && N->getFunctionValue() <= level){
                cout << "E SOLUCAO!" << endl;
                success = true;
                break;

            }
            else{

                auxFunctionValue = N->getFunctionValue();
                if(auxFunctionValue > level){

                    if(isFirst){
                        cout << "É PRIMEIRA!" << endl;
                        isFirst = false;
                        auxLevel =  auxFunctionValue;
                    }else
                        auxLevel = auxFunctionValue < auxLevel ? auxFunctionValue : auxLevel;
                    cout << "auxFValue: " << auxFunctionValue << " auxLvl: " << auxLevel << endl;
                    aux = N;
                    N = N->getFather();
                    delete aux;

                }

                // List of possibles operators to N
                list<int>* rules = N->getApplicableRules();

                if(!rules->empty()) {

                    // Picking first operator
                    int rule = rules->front();
                    rules->pop_front();
                    N = givesLight(N, rule);
                    printTable(N->getTokens(), N->getSize());
                    cout << "rules size: " << rules->size() << endl;
                    rules = nullptr;

                }
                else{

                    if(N == root){

                        oldLevel = level;
                        level = auxLevel; // TODO: gets minor value here
                        isFirst = true;

                    }
                    else
                        N = N->getFather();

                }

            }

        }

    }

    return N;   
    
}