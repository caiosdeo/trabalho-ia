#include <iostream>
#include "execution_flows/menu.h"

using namespace std;

int main(int argc, char const *argv[]) {

    //Verificação se todos os parâmetros do programa foram entrados
    if (argc != 3) {

        cout << "ERROR: Expecting: ./<program_name> <table_size> <search_method>" << endl;
        cout << "<search_method> options: " << endl;
        cout << "1 to backtracking" << endl;
        cout << "2 to bfs" << endl;
        cout << "3 to dfs" << endl;
        return 0;

    }

    int size = atoi(argv[1]);
    int option = atoi(argv[2]);

    // while (option != 0){

    unsigned clear = system("clear");

    select(option, size);

    // }

    return 0;
    
}