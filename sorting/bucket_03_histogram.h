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

typedef enum{False, True}BOOLEAN;

// =======================================================================
// MISC FUNCTIONS
// =======================================================================

void section(char* section_name){
	// additional 5 in count for the special charaters later such as '\n's and the '\0'
	int count = 55;
	char new_string[count];

	// ssets the entire string to dashes
	memset(new_string, '-', count);

	// double space before and after the seprator titile and termination character
	new_string[0] = '\n';
	new_string[1] = '\n';
	new_string[count-2] = '\n';
	new_string[count-3] = '\n';
	new_string[count-1] = '\0';

	// there is only space for 50 characters in the seprator title
	int message_len = strlen(section_name); 
	if(message_len > 49){
		message_len = 49;
	}

	memcpy(new_string + 2, section_name, strlen(section_name));
	
	// places a space between the section_name and the dashes
	new_string[strlen(section_name) + 2] = ' ';

	printf("%s", new_string);
}

// =======================================================================

#define NUMBER_OF_ELEMENTS 200

void dislpay_arr(int arr[], int arr_size){
	int i;
	printf("\n{");
	for(i = 0; i<arr_size; i++){
		printf("%d", arr[i]);
		if (i < arr_size - 1) {
			printf(", ");
		}
	}
	printf("}");
}

// =======================================================================
// BUCKET SORT
// =======================================================================

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	//getting the range of values
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

	//creating cumulative frequency
	int cumulative_frequency[range_size];
	memset(cumulative_frequency, 0, sizeof(cumulative_frequency));
	cumulative_frequency[0] = histogram[0];
	for (i = 1; i < range_size; i++){
		cumulative_frequency[i] = histogram[i] + cumulative_frequency[i-1];
	}
	section("cumulative frequency");
	dislpay_arr(histogram, range_size);

	//setting everything in place
	int index;
	int* elements_sorted = (int*)malloc(sizeof(int)*NUMBER_OF_ELEMENTS);
	for (i = 0; i < NUMBER_OF_ELEMENTS; i++){
		index = cumulative_frequency[elements[i]-minVal] - 1;
		printf("%d, ", index);

		*(elements_sorted + index) = elements[i];
		cumulative_frequency[elements[i]]--;
	}
	
	return elements_sorted;
}