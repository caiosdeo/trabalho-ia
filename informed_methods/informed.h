#include "../classes/table.h"
#include <stack>
#include <list>
#include <queue>

Table* greedySearch(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs);
Table* AStarSearch(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs);
Table* IDAStarSearch(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs);