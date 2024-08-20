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

	memcpy(new_string + 2, section_name, );
	
	// places a space between the section_name and the dashes
	new_string[strlen(section_name) + 2] = ' ';

	printf("%s", new_string);
}

// =======================================================================
// CORE FUNCTIONS 1
// =======================================================================

