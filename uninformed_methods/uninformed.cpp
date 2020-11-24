#include "uninformed.h"
#include "../auxiliar_functions/aux.h"
#include <iostream>
#include <iterator>

using namespace std;

Table* backtracking(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs){

    Table* N = root; // Initializing N with root's pointer
    bool success = false, failure = false; 
    list<int>* rules;
    int rule;

    // While not success or failure
    while(!(success || failure)){

        // List of possibles operators to N
        rules = N->getApplicableRules();

        if(!N->getVisited()){

            (*visitedNodes)++;
            N->setVisited(true);

            if(rules->empty())
                (*numberOfLeafs)++;

        }
        
        if(!rules->empty()){

            // Picking first operator
            rule = rules->front();
            rules->pop_front();
            N = givesLight(N,rule);
            (*expandedNodes)++;

            if(checkSolution(N->getTokens(), N->getSize())){

                success = true;
                break;

            }

        }
        else{

			if(N == root)
				failure = true;
			else 
				N = N->getFather();

		}

    }

	return N;

}

Table* bfs(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs){

    // Defining open list and pushing root node to it
    list<Table*> open;
    Table* N, *U;
    open.push_front(root);
    bool success = false, failure = false;
    list<int>* rules; 
    int rule;

    // While not success or failure
    while(!(success || failure)){

        if(open.empty())
            failure = true;

        else{

            N = open.back(); // Gets the first element in the queue
            open.pop_back(); // Removes the first element of the open list
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
                    rule = rules->front();
                    rules->pop_front();
                    // Generating new node and inserting it in the open list
                    U = givesLight(N, rule);
                    open.push_front(U);
                    (*expandedNodes)++;
                    
                }

            }

        }

    }

    return N;

}

Table* dfs(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs){

    // Defining open list and pushing root node to it
    stack<Table*> open;
    Table* N, *U;
    open.push(root);
    bool success = false, failure = false; 
    list<int>* rules;
    int rule;

    // While not success or failure
    while(!(success || failure)){

        if(open.empty())
            failure = true;

        else{

            N = open.top(); // Gets the element at the top of the stack
            open.pop(); // Removes the top element of the open list
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
                    open.push(U);
                    (*expandedNodes)++;

                }

            }

        }

    }

    return N;

}

Table* orderedSearch(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs){

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

            N = getsTableWithMinorCost(&open);
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