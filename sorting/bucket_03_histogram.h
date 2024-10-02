// =======================================================================
// Author		: G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date			: ur my date uwu
// rules		:
//		use snake case
//		all user defined typedefs should be all caps
// Description	: Code that will impress u ;)
// =======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper.h"

// =======================================================================
// BUCKET SORT
// =======================================================================

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	
	// ======================
	//getting the normalized range of values
	int i;
	int maxVal = elements[0], minVal = elements[0];
	for (i = 1; i < NUMBER_OF_ELEMENTS; i++){
		if (elements[i] > maxVal) maxVal = elements[i];
		if (elements[i] < minVal) minVal = elements[i];
	}

	//creatin the histogram
	int range_size = maxVal - minVal + 1;
	int histogram[range_size];
	memset(histogram, 0, sizeof(histogram));
	for (i = 0; i < NUMBER_OF_ELEMENTS; i++){
		histogram[elements[i]-minVal]++;
	}
	section("histogrm");
	dislpay_arr(histogram, range_size);

	// ======================
	//creating cumulative frequency
	int cumulative_frequency[range_size];
	memset(cumulative_frequency, 0, sizeof(cumulative_frequency));
	cumulative_frequency[0] = histogram[0];
	for (i = 1; i < range_size; i++){
		cumulative_frequency[i] = histogram[i] + cumulative_frequency[i-1];
	}
	
	section("cumulative frequency");
	dislpay_arr(histogram, range_size);

	// ======================
	//setting everything in place
	int index;
	int* elements_sorted = (int*)malloc(sizeof(int)*NUMBER_OF_ELEMENTS);
	for (i = 0; i < NUMBER_OF_ELEMENTS; i++){
		index = cumulative_frequency[elements[i]-minVal] - 1;
		printf("%d, ", index);

		*(elements_sorted + index) = elements[i];
		cumulative_frequency[elements[i]]--;
	}
	
	// ======================
	section("sorted list");
	dislpay_arr(elements_sorted, NUMBER_OF_ELEMENTS);
	
	return elements_sorted;
}
