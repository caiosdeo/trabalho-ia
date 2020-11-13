#include <iostream>
#include <fstream>
#include "execution_flows.h"

using namespace std;

void select(int option, int size){


    // Choose method
    switch (option){

        //BACKTRACKING
        case 1:{

            cout << "BACKTRACKING" << endl;
                    
            // Executing backtracking flow
            backtrackingFlow(size); 

            // Wait screen
            cout << "Pressione ENTER....";
            cin.get();            
            break;

        }
        

        //BFS
        case 2:{

            cout << "BFS" << endl;

            // Executing bfs flow
            bfsFlow(size);

            // Wait screen
            cout << "Pressione ENTER....";
            cin.get();            
            break;
        }
            

        //DFS
        case 3:{

            cout << "DFS" << endl;

            // Executing DFS flow
            dfsFlow(size);

            // Wait screen
            cout << "Pressione ENTER....";
            cin.get();            
            break;
        }

        default:
            break;
                
    }

}