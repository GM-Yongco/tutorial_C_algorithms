/* ========================================================================== 
Author		: G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date			: ur my date uwu
rules		:
	used snake case
	all user defined types are all caps
Description	: Code that will impress u ;)
	tournament sort that uses index references
// ========================================================================== */
// HEADERS
// =======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper.h"

// =======================================================================
// CORE FUNCTIONS 1
// =======================================================================

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	int* elements_sorted = (int*)malloc(sizeof(int)*NUMBER_OF_ELEMENTS);
	memset(elements_sorted, 0, sizeof(int)*NUMBER_OF_ELEMENTS);
	
	return elements_sorted;
}
