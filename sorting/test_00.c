// =======================================================================
// Author		: G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date			: ur my date uwu
// rules		:
//		use snake case
//		all user defined typedefs should be all caps
// Description	: bucket sorting elements with no repetitions
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

// #include "bucket_01.h"
// #include "bucket_02.h"
// #include "bucket_03_histogram.h"
#include "tournament_01.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){
	section("START");

	section("UNSORTED");
	display_arr(elements, NUMBER_OF_ELEMENTS);
	int* elements_sorted = sort(elements);
	section("SORTED");
	display_arr(elements_sorted, NUMBER_OF_ELEMENTS);

	section("END");
	return 0;
}
