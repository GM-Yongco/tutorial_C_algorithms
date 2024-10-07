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

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	int i=0;
	while(i < NUMBER_OF_ELEMENTS - 1){
		if(elements[i] <= elements[i+1]){
			i++;
		}else{
			swap(elements + i, elements + i + 1);
			if(i > 0){i--;}
		}
	}	
	return elements;
}
