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
	int gap, i, j;
	for(gap = NUMBER_OF_ELEMENTS/2;
		gap > 0;
		gap = gap/2
	){
		for(i = gap;
			i < NUMBER_OF_ELEMENTS;
			i++){	
			for(j = i;
				elements[j] > elements[j - gap] && j >= gap;
				j -= gap){		
				swap(elements + j, elements + j - gap);
			}
		}
	}
	return elements;
}
