// =======================================================================
// Author		: G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date			: ur my date uwu
// rules		:
//		use snake case
//		all user defined typedefs should be all caps
// Description	: Code that will impress u ;)
// =======================================================================
// DEFINE CLAUSE
// =======================================================================

#ifndef HELPER_H
#define HELPER_H

// =======================================================================
// DEFINE HEADERS
// =======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{False, True}BOOLEAN;

#define NUMBER_OF_ELEMENTS 200

int elements[NUMBER_OF_ELEMENTS] = {
	34, 7, 23, 32, 5, 62, 72, 9, 12, 87,
	14, 45, 68, 3, 99, 28, 19, 54, 76, 10,
	1, 57, 93, 16, 82, 21, 90, 6, 41, 35,
	63, 50, 73, 25, 89, 40, 55, 48, 31, 4,
	77, 85, 17, 26, 97, 22, 91, 11, 79, 8,
	13, 66, 52, 2, 84, 94, 60, 88, 39, 49,
	92, 24, 56, 81, 36, 46, 20, 98, 67, 38,
	64, 33, 44, 95, 27, 58, 29, 18, 47, 75,
	42, 78, 43, 86, 0, 69, 74, 53, 30, 83,
	70, 61, 71, 59, 15, 80, 65, 37, 51, 96,
	34, 7, 23, 32, 5, 62, 72, 9, 12, 87,
	14, 45, 68, 3, 99, 28, 19, 54, 76, 10,
	1, 57, 93, 16, 82, 21, 90, 6, 41, 35,
	63, 50, 73, 25, 89, 40, 55, 48, 31, 4,
	77, 85, 17, 26, 97, 22, 91, 11, 79, 8,
	13, 66, 52, 2, 84, 94, 60, 88, 39, 49,
	92, 24, 56, 81, 36, 46, 20, 98, 67, 38,
	64, 33, 44, 95, 27, 58, 29, 18, 47, 75,
	42, 78, 43, 86, 0, 69, 74, 53, 30, 83,
	70, 61, 71, 59, 15, 80, 65, 37, 51, 96
};

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

void display_arr(int arr[], int arr_size){
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
// END DEFINE CLAUSE
// =======================================================================
#endif
