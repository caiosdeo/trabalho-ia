#include "../classes/table.h"
#include <list> 
#include <stack>
#include <string>
#include <tuple>
#include <vector>

/**
 * Dictionary to get a matching char for a token's value
 * 0 to '-'; 1 to 'W' (White); and 2 to 'B' (Black)
 *
 * @author caiosdeo
 * @param int token 
 * @return char that corresponds to its int
 */
char tokenChar(int token);

/**
 * Print the Table's tokens
 *
 * @author caiosdeo
 * @param int* tokens array
 * @param int size of tokens' array
 */
void printTable(int* tokens, int size);

/**
 * Function that swaps applicable rules by the right
 *
 * @author eliascassis
 * @param rules list that will be filled
 * @param n father pointer of father's Table
 * @param numberOfJumps the maximum size of search
 */
void swap(int* tokens, int i, int j);

/**
 * Function to generate a new table gives its father and the rule applied
 *
 * @author eliascassis
 * @param Table* father pointer of father's Table
 * @param int rule represents rule / operator
 * @return Table* pointer to the new Table 
 */
Table* givesLight(Table* father, int rule);

/**
 * Function to generate a list with all apllicable operators
 *
 * @author eliascassis
 * @param n father pointer of father's Table
 * @return list<int> the list of all appicable rules
 */
list<int>* findApplicableRules(Table* n);

/**
 * Function to verifies if a node n has an ancestor
 *
 * @author eliascassis
 * @param n father pointer of father's Table
 * @param hashValue table's hash value
 * @param tokens Table's tokens 
 * @param newIndexOfVoidSpace new index calculated for the potential Table
 * @return bool if the node n has an ancestor or not
 */
bool isAncestor(Table* n, int hashValue, int* tokens, int newIndexOfVoidSpace);

/**
 * Function that calculates a hash value to the table
 *
 * @author eliascassis
 * @param tokens pointer to the tokens of the table class
 * @param size size of the table
 * @return int the calculated hash
 */
int hashValue(int* tokens, int size);

/**
 * Function that search applicable rules by the left
 *
 * @author eliascassis
 * @param rules list that will be filled
 * @param n father pointer of father's Table
 * @param numberOfJumps the maximum size of search
 * @param auxTokens probably state of tokens
 */
void searchByTheLeft(list<int>* rules, Table* n, int numberOfJumps, int* auxTokens);

/**
 * Function that search applicable rules by the right
 *
 * @author eliascassis
 * @param rules list that will be filled
 * @param n father pointer of father's Table
 * @param numberOfJumps the maximum size of search
 * @param auxTokens probably state of tokens
 */
void searchByTheRight(list<int>* rules, Table* n, int numberOfJumps, int* auxTokens);

/**
 * Generates the hash value to compares to ancestors
 *
 * @author caiosdeo
 * @param int* tokens array
 * @param int* likelyTokens probably state of tokens
 * @param int size of tokens' array
 * @param int voidSpace index of void space
 * @param int rule 
 * @return tuple<int, int> 0 - likely hash value; 1 - likely voidspace
 */
tuple<int, int> likelyHashValue(int* tokens, int* likelyTokens, int size, int voidSpace, int rule);

/**
 * Copy an tokens' array
 *
 * @author caiosdeo
 * @param int* tokens array
 * @param int* auxTokens pointer to be copied
 * @param int size of tokens' array
 */
void copyTokens(int* tokens, int* copiedTokens, int size);

/**
 * Function that checks if the tokens represent a solution
 *
 * @author eliascassis
 * @param tokens Table's tokens
 * @param n Table's size
 */
bool checkSolution(int* tokens, int n);
/**
 * Function that finds the solution
 *
 * @author eliascassis
 * @param n the Table
 */
stack<int>* getSolution(Table* n);

/**
 * Print the stack
 *
 * @author caiosdeo
 * @param int stack<int>* stack with int
 */
void printStack(stack<int>* s);

/**
 * Dictionary to get a matching char for a rule's value
 *
 * @author caiosdeo
 * @param int token 
 * @return char that corresponds to its int
 */
string ruleChar(int rule);

/**
 * Function to verifies if a node n has an ancestor
 *
 * @author eliascassis
 * @param tokens Table's tokens 
 * @param auxTokens Auxiliar Table's tokens
 * @param n size of the Tables
 * @return bool if the tables are equal or not
 */
bool tokensEquality(int* tokens, int* auxTokens, int n);

/**
 * Function to verifies if a node n has an ancestor
 *
 * @author eliascassis
 * @param vec list of open Tables
 * @return Table* to the Table with minor cost
 */
Table* getsTableWithMinorCost(vector<Table*> *vec);

// TODO: documents here
// ? solution black group minus biggest black group between whites 
// ? number of whites between black
int getBiggestGroupHeuristic(int* tokens, int size);

// TODO: documents here
Table* getsTableWithMinorHeuristic(vector<Table*> *vec);

// TODO: documents here
Table* getsTableWithMinorFunctionValue(vector<Table*> *vec);

// TODO: documents here
void setInitialState(Table* root);