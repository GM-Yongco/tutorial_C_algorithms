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

void quick_sort_hoare(int elements[NUMBER_OF_ELEMENTS], int size){
	int val_pivot = elements[size-1];
	
	int i, j;

	section("start of sorting");
	for(i = 0,
		j = size-2;
		i<j;){

		//find an element bigger than the pivot closests to left side
		for(;elements[i]<=val_pivot && i<j; i++);
		//find an element less than the pivot closests to right side
		for(;elements[j]>val_pivot && i<j; j--);
		swap(elements + i, elements + j);
		display_arr(elements, size);
	}

	//swap the pivot portion
	if(elements[i] < elements[size-1]){
		i++;
	}
	swap(elements + i, elements + size - 1);
	display_arr(elements, size);

	//recursion portion
	if(i - 1 > 1){
		quick_sort_hoare(elements, i);
	}
	if(size - i - 1 > 1){
		quick_sort_hoare(elements + i + 1, size - i - 1);
	}
}

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	quick_sort_hoare(elements, NUMBER_OF_ELEMENTS);
	
	return elements;
}
