#include <iostream>
#include "aux.h"

using namespace std;

void printTable(unsigned int* tokens, unsigned int size){

    cout << "Table:\n|";
    for( int i = 0; i < size; i++)
        cout << i << ": " << tokens[i] << "|";
    cout << endl; 

}