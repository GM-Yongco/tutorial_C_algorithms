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

void quick_sort_lomuto(int elements[NUMBER_OF_ELEMENTS], int size){
	int val_pivot = elements[size-1];
	int num_elements_less_than_pivot = 0;
	
	int i;

	section("start of sorting");
	for(i = 0; i<size; i++){
		if(elements[i] <= val_pivot){
			if(elements[i] < elements[num_elements_less_than_pivot]){
				swap(elements + i, elements + num_elements_less_than_pivot);
			}
			num_elements_less_than_pivot++;
			display_arr(elements, size);
		}
	}
	printf("\nindex mid: %d", num_elements_less_than_pivot - 1);

	//recursion portion
	if(num_elements_less_than_pivot - 1 > 1){
		quick_sort_lomuto(elements, num_elements_less_than_pivot - 1);
	}
	if(size - num_elements_less_than_pivot > 1){
		quick_sort_lomuto(elements + num_elements_less_than_pivot, size - num_elements_less_than_pivot );
	}
}

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	quick_sort_lomuto(elements, NUMBER_OF_ELEMENTS);
	
	return elements;
}

