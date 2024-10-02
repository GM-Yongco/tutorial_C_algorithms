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
// CORE FUNCTIONS COMB
// =======================================================================

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	int gap, i, temp_max;

	for(gap = NUMBER_OF_ELEMENTS/1.3;
		gap > 0;
		gap = gap/1.3
	){
		printf("\ngap: %d", gap);
		for(i = 0, temp_max = NUMBER_OF_ELEMENTS-gap;
		i<temp_max;
		i++){
			if(elements[i] > elements[i+gap]){
				swap(elements + i, elements + i + gap);
			}
		}
	}

	return elements;
}
