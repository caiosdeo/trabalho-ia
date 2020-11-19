#include "../classes/table.h"
#include <stack>
#include <list>
#include <queue>

Table* backtracking(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs);
Table* bfs(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs);
Table* dfs(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs);
Table* orderedSearch(Table* root, int* expandedNodes, int* visitedNodes, int* numberOfLeafs);