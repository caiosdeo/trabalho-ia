#include "../classes/table.h"

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

list<int> findApplicableRules(Table* n);

bool isAncestor(Table* n, unsigned int hashValue);

unsigned int hashValue(unsigned int* tokens, unsigned int size);

/**
 * Print the Table's tokens
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