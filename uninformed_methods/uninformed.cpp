#include "uninformed.h"
#include "../auxiliar_functions/aux.h"
#include <iostream>
#include <iterator>

using namespace std;

Table* backtracking(Table* root){

    Table* N = root; // Initializing N with root's pointer
    bool sucess = false, failure = false; 
    list<int>* rules;
    int rule;

    // While not sucess or failure
    while(!(sucess || failure)){

        // List of possibles operators to N
        rules = N->getApplicableRules();

        if(!rules->empty()){

            // Picking first operator
            rule = rules->front();
            rules->pop_front();
            N = givesLight(N,rule);

            if(checkSolution(N->getTokens(), N->getSize())){

                sucess = true;
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

Table* bfs(Table* root){

    // Defining open list and pushing root node to it
    queue<Table*> open;
    Table* N, *U;
    open.push(root);
    bool sucess = false, failure = false;
    list<int>* rules; 
    int rule;

    // While not sucess or failure
    while(!(sucess || failure)){

        if(open.empty())
            failure = true;

        else{

            N = open.front(); // Gets the first element in the queue
            open.pop(); // Removes the first element of the open list

            if(checkSolution(N->getTokens(), N->getSize())){

                sucess = true;
                break;

            }

            else{

                // List of possibles operators to N
                rules = N->getApplicableRules();

                while(!rules->empty()){

                    // Picking first operator
                    rule = rules->front();
                    rules->pop_front();
                    // Generating new node and inserting it in the open list
                    U = givesLight(N, rule);
                    open.push(U);

                }
                // Free Table's tokens
                //N->freeTable();

            }

        }

    }

    return N;

}

Table* dfs(Table* root){

    // Defining open list and pushing root node to it
    stack<Table*> open;
    Table* N, *U;
    open.push(root);
    bool sucess = false, failure = false; 
    list<int>* rules;
    int rule;

    // While not sucess or failure
    while(!(sucess || failure)){

        if(open.empty())
            failure = true;

        else{

            N = open.top(); // Gets the element at the top of the stack
            open.pop(); // Removes the top element of the open list

            if(checkSolution(N->getTokens(), N->getSize())){

                sucess = true;
                break;

            }

            else{

                // List of possibles operators to N
                rules = N->getApplicableRules();

                while(!rules->empty()){

                    // Picking first operator
                    rule = rules->back();
                    rules->pop_back();
                    // Generating new node and inserting it in the open list
                    U = givesLight(N, rule);
                    open.push(U);

                }
                // Free Table's tokens
                //N->freeTable();

            }

        }

    }

    return N;

}

Table* orderedSearch(Table* root){

    // Defining open list and pushing root node to it
    vector<Table*> open;
    Table* N, *U;
    open.push_back(root);
    bool sucess = false, failure = false; 
    list<int>* rules;
    int rule;

    // While not sucess or failure
    while(!(sucess || failure)){

        if(open.empty())
            failure = true;

        else{

            N = getsTableWithMinorCost(&open);

            if(checkSolution(N->getTokens(), N->getSize())){

                sucess = true;
                break;

            }

            else{

                // List of possibles operators to N
                rules = N->getApplicableRules();

                while(!rules->empty()){

                    // Picking first operator
                    rule = rules->back();
                    rules->pop_back();
                    // Generating new node and inserting it in the open list
                    U = givesLight(N, rule);
                    open.push_back(U);

                }
                // Free Table's tokens
                //N->freeTable();

            }

        }

    }

    return N;

}