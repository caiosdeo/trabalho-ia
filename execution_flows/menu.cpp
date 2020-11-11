#include <iostream>
#include <fstream>
#include "execution_flows.h"

using namespace std;

int menu(){

    int option;

    cout << "MENU" << endl;
    cout << "----" << endl;
    cout << "[1] Backtracking" << endl;
    cout << "[2] BFS" << endl;
    cout << "[3] DFS" << endl;
    cout << "[0] Sair" << endl;

    cin >> option;

    int clear = system("clear");

    return option;
}

void select(int option, int size){


    // Choose method
    switch (option){

        //BACKTRACKING
        case 1:{
                    
            // Executing backtracking flow
            backtrackingFlow(size); 

            // Wait screen
            cout << "Pressione ENTER....";
            cin.get();            
            break;

        }
        

        //BFS
        case 2:{

            // Executing backtracking flow
            bfsFlow(size);

            // Wait screen
            cout << "Pressione ENTER....";
            cin.get();            
            break;
        }
            

        //DFS
        case 3:{

            // Executing backtracking flow
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