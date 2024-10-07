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

// =======================================================================

#define REMOVED -1;
//we assumed the givenn array is normalized to be in a range between 0 and some number n

typedef struct NODE{
	int element;
	struct NODE* next;
}*LINK, NODE;

void insert_last(LINK* L, int element_new){
	while(*L != NULL){L = &((*L)->next);}
	*L = (LINK)calloc(1, sizeof(NODE));
	(*L)->element = element_new;
	(*L)->next = NULL;
}

void display_LL(LINK L){
	printf("\n");
	while(L != NULL){
		printf("%d", L->element);
		L = L->next;
		printf(" -> ");
	}
}


int* sort(int elements[NUMBER_OF_ELEMENTS]){
	
	int* elements_sorted = (int*)calloc(NUMBER_OF_ELEMENTS, sizeof(int));
	LINK given = NULL;

	int i;
	for(i=0; i<NUMBER_OF_ELEMENTS; i++){
		insert_last(&given, elements[i]);
	}
	display_LL(given);


	// STACK* elements_sorted_1 = stack_init();
	// STACK* elements_sorted_2 = stack_init();
	// STACK* sub_stack = stack_init();

	
	return elements_sorted;
}
