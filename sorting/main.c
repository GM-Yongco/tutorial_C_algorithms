/* =======================================================================
author		: G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
date		: ur my date uwu
format		:
	used snake case
	all user defined types are all caps
description	: the file that tests and executes the sorting algorithms
// ======================================================================= */
// HEADERS
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

// #include "bucket_01.h"
// #include "bucket_02.h"
// #include "bucket_03_histogram.h"
// #include "tournament_01.h"
#include "comb.h"

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
