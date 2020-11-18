#include <iostream>
#include <fstream>
#include <chrono>
#include "classes/table.h"
#include "auxiliar_functions/aux.h"
#include "uninformed_methods/uninformed.h"

using namespace std;

void select(int option, int size){

    cout << "TAMANHO: " << size << endl;

    // Creating root
    Table* root = new Table(size);
    // Pointer for solution Table
    Table* final;

    // Printing Table tokens
    cout << "RAIZ: ";
    printTable(root->getTokens(), root->getSize());
    cout << endl;

    //Start point to measure runtime
    auto start = chrono::high_resolution_clock::now();

    // Choose method
    switch (option){

        //BACKTRACKING
        case 1:{

            cout << "BACKTRACKING" << endl;
            final = backtracking(root); 
            break;

        }
        

        //BFS
        case 2:{

            cout << "BFS" << endl;

            // Executing bfs
            final = bfs(root);            
            break;
        }
            

        //DFS
        case 3:{

            cout << "DFS" << endl;

            // Executing DFS 
            final = dfs(root);          
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
    stack<int>* solution = getSolution(final);

    // Printing solution table
    cout << "FINAL: ";
    printTable(final->getTokens(), final->getSize());
    cout << endl;

    cout << "ESTATÍSTICAS: " << endl;
    cout << "Caminho: ";
    printStack(solution);
    cout << "Profundidade da solução: " << endl;
    cout << "Custo da solução: " << endl;
    cout << "Total de nós expandidos: " << endl;
    cout << "Total de nós visitados: " << endl;
    cout << "Valor médio de ramificação: " << endl;
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