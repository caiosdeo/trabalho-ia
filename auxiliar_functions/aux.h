#include "../classes/table.h"
#include <list> // ?TOASK: why this include must be here?

/**
 * Dictionary to get a matching char for a token's value
 * 0 to '-'; 1 to 'W' (White); and 2 to 'B' (Black)
 *
 * @author caiosdeo
 * @param unsigned token 
 * @return char that corresponds to its int
 */
char tokenChar(unsigned int token);

/**
 * Print the Table's tokens
 *
 * @author caiosdeo
 * @param unsigned int* tokens array
 * @param unsigned int size of tokens' array
 */
void printTable(unsigned int* tokens, unsigned int size);

void swap(unsigned int* tokens, int i, int j);

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
 * @return bool if the node n has an ancestor or not
 */
bool isAncestor(Table* n, unsigned int hashValue);

/**
 * Function that calculates a hash value to the table
 *
 * @author eliascassis
 * @param tokens pointer to the tokens of the table class
 * @param size size of the table
 * @return int the calculated hash
 */
unsigned int hashValue(unsigned int* tokens, unsigned int size);

/**
 * Function that search applicable rules by the left
 *
 * @author eliascassis
 * @param rules list that will be filled
 * @param n father pointer of father's Table
 * @param numberOfJumps the maximum size of search
 */
void searchByTheLeft(list<int>* rules, Table* n, unsigned int numberOfJumps);

/**
 * Function that search applicable rules by the right
 *
 * @author eliascassis
 * @param rules list that will be filled
 * @param n father pointer of father's Table
 * @param numberOfJumps the maximum size of search
 */
void searchByTheRight(list<int>* rules, Table* n, unsigned int numberOfJumps);

// TODO: verifies this documentation here
/**
 * Generates the hash value to compares to ancestors
 *
 * @author caiosdeo
 * @param unsigned int* tokens array
 * @param unsigned int size of tokens' array
 * @param int voidSpace index of void space
 * @param int rule 
 * @return unsigned int likely hash value
 */
unsigned int likelyHashValue(unsigned int* tokens, unsigned int size, int voidSpace, int rule);

// TODO: create a copyTokens method to allow every table to have its own tokens' array
/**
 * Copy an tokens' array
 *
 * @author caiosdeo
 * @param unsigned int* tokens array
 * @param unsigned int size of tokens' array
 * @return unsigned int* copied array
 */
unsigned int* copyTokens(unsigned int* tokens, unsigned int size);

bool checkSolution(unsigned int* tokens, unsigned int n);
