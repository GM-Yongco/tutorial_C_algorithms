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

	free(a);
	free(b);

	return merged;
}

int* copy_arr(int* a, int size){
	int* new_arr = (int*)calloc(size, sizeof(int));
	memcpy(new_arr, a, size * sizeof(int));
	return new_arr;
}

int merge_sort(int* original, int size){
	if(size <= 1){
		return 0;
	}

	// THE SPLITTING
	int size_left = size/2;
	int size_right = size-size_left;

	int* arr_left = copy_arr(original, size_left);
	int* arr_right = copy_arr(original + size_left, size_right);
	
	section("display left and right arrs");
	display_arr(arr_left, size_left);
	display_arr(arr_right, size_right);

	// RECCURSIVE PORTION
	merge_sort(arr_left, size_left);
	merge_sort(arr_right, size_right);

	// MERGE AND OVERWRITE
	int* arr_sorted = merge(arr_left, size_left, arr_right, size_right);
	int i;
	for(i = 0; i<size; i++){
		original[i] = arr_sorted[i];
	}
	free(arr_sorted);

	return 0;
}

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	merge_sort(elements, NUMBER_OF_ELEMENTS);
	return elements;
}
