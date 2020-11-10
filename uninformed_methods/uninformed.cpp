#include "uninformed.h"
#include "../auxiliar_functions/aux.h"

using namespace std;

Table* backtracking(Table* root){

    // Initializing N with root's pointer
    Table* N = root;
    bool sucess = false, failure = false; 

    // While not sucess or failure
    while(!(sucess || failure)){

        // List of possibles operators to N
        list<int>* rules = findApplicableRules(N);
        
        if(!rules->empty()) {

            // Picking first operator
            int rule = rules->front();
            rules->pop_front();
            N = givesLight(N, rule);

            if(checkSolution(N->getTokens(), N->getSize()))
                sucess = true;

        }else{

			if (N == root)
				failure = true;
			else 
				N = N->getFather();

		}

    }

	return N;

}