#include <iostream>
#include "execution_flows/menu.h"

using namespace std;

int main(int argc, char const *argv[]) {

    //Verificação se todos os parâmetros do programa foram entrados
    if (argc != 2) {

        cout << "ERROR: Expecting: ./<program_name> <table_size>" << endl;

        return 0;

    }

    int size = atoi(argv[1]);

    int option = 1;

    while (option != 0){

        unsigned clear = system("clear");
        option = menu();

        select(option, size);

        cin.get();

    }

    return 0;
    
}