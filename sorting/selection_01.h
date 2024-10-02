/* ========================================================================== 
Author		: G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date			: ur my date uwu
rules		:
	used snake case
	all user defined types are all caps
Description	: Code that will impress u ;)
	actual description
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

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	
	int i, j, biggests_index;
	for(i = 0; i<NUMBER_OF_ELEMENTS; i++){
		biggests_index = 0;
		for(j = 1; j<NUMBER_OF_ELEMENTS - i; j++){
			if(elements[j] > elements[biggests_index]){
				biggests_index = j;
			}
		}
		swap(elements + biggests_index, elements + NUMBER_OF_ELEMENTS - i - 1);
	} 

	return elements;
}
