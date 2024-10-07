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

int* merge(int* a, int size_a, int* b, int size_b){
	int* merged = (int*)calloc(size_a + size_b, sizeof(int));

	int i = 0, counter_a = 0, counter_b = 0;

	while(counter_a < size_a && counter_b < size_b){
		if(a[counter_a] < b[counter_b]){
			merged[i] = a[counter_a];
			counter_a++;
		}else{
			merged[i] = b[counter_b];
			counter_b++;
		}
		i++;
	}
	while(counter_a < size_a){
		merged[i] = a[counter_a];
		counter_a++;
		i++;
	}
	while(counter_b < size_b){
		merged[i] = b[counter_b];
		counter_b++;
		i++;
	}

	return merged;
}

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	
	return elements;
}
