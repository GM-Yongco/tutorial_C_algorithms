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
// HEAP FUNCTIONS
// =======================================================================

int get_index_child_left(int index_parent){
	return (index_parent*2) + 1;
	//add an additional 1 for the right child
}

int get_index_parent(int index_child){
	return (index_child - 1)/2;
}

// =======================================================================
// TOURNAMENT FUNCTIONS 1
// =======================================================================
#define SENTINEL -1

int* sort(int elements[NUMBER_OF_ELEMENTS]){
	section("HEAP INITIALIZTION");
	
	// number of non-leaf nodes
	// also the start index of the leaf nodes
	int heap_size_difference = NUMBER_OF_ELEMENTS -1;
	// number of heap nodes
	int heap_size = heap_size_difference + NUMBER_OF_ELEMENTS;
	
	// initializing memory
	int heap[heap_size];
	memset(heap, SENTINEL, sizeof(heap));
	int* elements_sorted = (int*)malloc(sizeof(int)*NUMBER_OF_ELEMENTS);
	memset(elements_sorted, SENTINEL, sizeof(int)*NUMBER_OF_ELEMENTS);
	
	// forda loops
	int i,j;
	
	// for the heap-ing
	int heap_index_child_left, heap_index_child_right, heap_index_child_bigger, heap_index_parent;
	
	// insertion of the indexes of the unsorted_array into the heap
	for(i = heap_size_difference, j = 0;
		i < heap_size;
		i++, j++){
		heap[i] = j;
	}
	display_arr(heap, heap_size);
	printf("heap_size: %d", heap_size);
	printf("heap_size_difference: %d", heap_size_difference);
	
	// ======================
	// start of the sorting
	// ======================
	
	section("START OF THE SORTING");
	
	// initial population of the heap
	for(i = heap_size_difference - 1;
		i >= 0;
		i--){
		heap_index_child_left = get_index_child_left(i);
		heap_index_child_right = heap_index_child_left + 1;
		
		//gets the bigger child
		heap[i] = heap[heap_index_child_left];
		if(elements[heap[heap_index_child_left]] < elements[heap[heap_index_child_right]]){
			heap[i] = heap[heap_index_child_right];
		}
	}
	
	for(j = 0, heap_index_parent = heap_size_difference; 
		j<NUMBER_OF_ELEMENTS; 
		j++){
		
		section("new loop");
		while(heap_index_parent != 0){
			heap_index_parent = get_index_parent(heap_index_parent);
			heap_index_child_left = get_index_child_left(heap_index_parent);
			heap_index_child_right = heap_index_child_left + 1;
			
			printf("\n\n parent\t:[%d]", heap_index_parent);
			printf("\n [%d] = %d vs [%d] = %d", heap_index_child_left, elements[heap[heap_index_child_left]], heap_index_child_right, elements[heap[heap_index_child_right]]);
			
			if(heap_index_child_left == SENTINEL){
				heap[heap_index_parent] = heap[heap_index_child_right];
			}else if(heap_index_child_right == SENTINEL){
				heap[heap_index_parent] = heap[heap_index_child_left];
			}else if(elements[heap[heap_index_child_left]] < elements[heap[heap_index_child_right]]){
				heap[heap_index_parent] = heap[heap_index_child_right];
			}else{
				heap[heap_index_parent] = heap[heap_index_child_left];
			}
			printf("\n winner: %d ", elements[heap[heap_index_parent]]);
		}
		
		// REMOVING THE MAX/MIN AND REPLACING WITH SENTINEL VALUE
		elements_sorted[j] = elements[heap[0]];
		elements[heap[0]] = SENTINEL;
		
		// CHANGING AFFECTED LINES IN THE HEAP
		heap_index_parent = heap[0] + heap_size_difference;
	}
	
	
	return elements_sorted;
}
