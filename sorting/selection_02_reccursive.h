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

void reccursive_sort(int* elements, int size){
	int i, biggests_index = 0;
	for(i = 1; i<size; i++){
		if(elements[i] > elements[biggests_index]){
			biggests_index = i;
		}
	}
	swap(elements + biggests_index, elements + i - 1);

	if(size>2){
		reccursive_sort(elements, size - 1);
	}
}

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	reccursive_sort(elements, NUMBER_OF_ELEMENTS);
	return elements;
}

