/* =======================================================================
author		: G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
date		: ur my date uwu
format		:
	used snake case
	all user defined types are all caps
description	: Code that will impress u ;)
	actual description
// ======================================================================= */
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
