#include <iostream>
#include <fstream>
#include <chrono>
#include "classes/table.h"
#include "auxiliar_functions/aux.h"
#include "uninformed_methods/uninformed.h"
#include "informed_methods/informed.h"
#include <list>
#include <iterator>
#include <stack>
#include <iomanip>

using namespace std;

void select(int option, int size){

    // Printing table size
    cout << "TAMANHO: " << size << endl;

    // Creating root
    Table* root = new Table(size);
    // Pointer for solution Table
    Table* final;

    // setting root info
    root->setFather(nullptr);
    root->setIndexOfVoidSpace(root->getSize()/2);
    setInitialState(root);
    root->setRule(0);
    root->setApplicableRules(findApplicableRules(root));
    root->setHashValue(hashValue(root->getTokens(),root->getSize()));
    root->setCost(0);
    root->setHeuristic(getBiggestGroupHeuristic(root->getTokens(),root->getSize()));
    root->setFunctionValue(root->getCost()+root->getHeuristic());
    // Statistics Variables
    int numberOfExpandedNodes = 0;
    int numberOfVisitedNodes = 0;
    int numberOfLeafs = 0;
    int totalOfNodes;

    // Printing Table tokens    
    cout << "RAIZ: ";
    printTable(root->getTokens(), root->getSize());
    cout << endl;

    //Start point to measure runtime
    auto start = chrono::high_resolution_clock::now();

    // Choose Search Algorithm
    switch (option){

        //BACKTRACKING
        case 1:{

            cout << "BACKTRACKING" << endl;
            final = backtracking(root, &numberOfExpandedNodes, &numberOfVisitedNodes, &numberOfLeafs); 
            break;

        }
        

        //BFS
        case 2:{

            cout << "BFS" << endl;
            // Executing bfs
            final = bfs(root, &numberOfExpandedNodes, &numberOfVisitedNodes, &numberOfLeafs);            
            break;
        }
            

        //DFS
        case 3:{

            cout << "DFS" << endl;
            // Executing DFS 
            final = dfs(root, &numberOfExpandedNodes, &numberOfVisitedNodes, &numberOfLeafs);          
            break;
        }

        // Ordered Search
        case 4:{

            cout << "BUSCA ORDENADA" << endl;
            final = orderedSearch(root, &numberOfExpandedNodes, &numberOfVisitedNodes, &numberOfLeafs);          
            break;
        }

        case 5:{

            cout << "BUSCA GULOSA" << endl;
            final = greedySearch(root, &numberOfExpandedNodes, &numberOfVisitedNodes, &numberOfLeafs);          
            break;
        }

        case 6:{

            cout << "A*" << endl;
            final = AStarSearch(root, &numberOfExpandedNodes, &numberOfVisitedNodes, &numberOfLeafs);          
            break;
        }

        case 7:{

            cout << "IDA*" << endl;
            final = IDAStarSearch(root);          
            break;
        }

        default:
            break;
                
    }

    //Stop point to measure runtime
    auto stop = chrono::high_resolution_clock::now();

    //Duration of runtime
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    // Printing solution
    stack<int>* solution = getSolution(final, root);

    // Printing solution table
    cout << "FINAL: ";
    printTable(final->getTokens(), final->getSize());
    cout << endl;

    // Statistics Variables
    int solutionSize = solution->size();
    totalOfNodes = numberOfExpandedNodes + 1;
    
    cout << "ESTATÍSTICAS: " << endl;
    cout << "Caminho: ";
    int solutionCost = printStack(solution);
    cout << "Profundidade da solução: " << solutionSize << endl;
    cout << "Custo da solução: " << solutionCost << endl; 
    cout << "Total de nós expandidos: " << numberOfExpandedNodes << endl;
    cout << "Total de nós visitados: " << numberOfVisitedNodes << endl;
    cout << "Valor médio de ramificação: " <<  setprecision(3) << float(totalOfNodes)/(totalOfNodes - numberOfLeafs) << endl;
    cout << "Tempo de execução: " << duration.count() << " ms" << endl;

    // Wait screen
    cout << endl << "Pressione ENTER....";
    cin.get();  

}

int main(int argc, char const *argv[]) {

    //Verificação se todos os parâmetros do programa foram entrados
    if (argc != 3) {

        cout << "ERROR: Expecting: ./<program_name> <table_size> <search_method>" << endl;
        cout << "<search_method> options: " << endl;
        cout << "1 to backtracking" << endl;
        cout << "2 to bfs" << endl;
        cout << "3 to dfs" << endl;
        cout << "4 to ordered search" << endl;
        cout << "5 to greedy search" << endl;
        cout << "6 to A star" << endl;
        cout << "7 to IDA star" << endl;
        return 0;

    }

    int size = atoi(argv[1]);
    int option = atoi(argv[2]);

    unsigned clear = system("clear");

    select(option, size);
    
    return 0;
    
}