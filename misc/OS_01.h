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
// CORE FUNCTIONS 1
// =======================================================================
void swap(int* swap_1, int* swap_2){
	int temp = *swap_1;
	*swap_1 = *swap_2;
	*swap_2 = temp;
}

// dummy program that sorts an array
void bubble_sort(int* arr, int arr_size){
	int temp, i , j;
	
	// arranged descending
	for(i = 1; i < arr_size; i++){
		for(j = 0; j < arr_size - i; j++){
			if(arr[j] < arr[j+1]){
				swap(arr + j, arr + j + 1);
			}
		}
	}
	
	// arrange ascending
	for(i = 1; i < arr_size; i++){
		for(j = 0; j < arr_size - i; j++){
			if(arr[j] > arr[j+1]){	
				swap(arr + j, arr + j + 1);
			}
		}
	}
	// end
}

# include <time.h>
float dummy_task(int task_size){
	time_t time_start, time_cease;
	time(&time_start);
	
	// ===================================================================
	
	int i;
	int* arr = malloc(sizeof(int) * task_size);
	for(i = 0; i<task_size; i++){
		arr[i] = i+1; 
	}
	
	for(i = 0; i<task_size - 100; i++){
		bubble_sort(arr, task_size);
	}
	
	// ===================================================================
	
	time(&time_cease); 
    return difftime(time_cease, time_start); 
}
// =======================================================================
// CORE FUNCTIONS 2 - QUEUE FUNCTIONALITY
// =======================================================================
typedef struct node{
	int element;
	struct node* next;
}*LINK, NODE;

typedef struct queue{
	LINK start;
	LINK cease;
}QUEUE;

void enqueue(int new_element, QUEUE* Q){
	LINK new_link = NULL;
	new_link = (LINK)malloc(sizeof(NODE));
	
	if(new_link != NULL){
		new_link->element = new_element;
		new_link->next = NULL;

		if(Q->start == NULL){
			Q->start = new_link;
		}else{
			Q->cease->next = new_link;
		}
		Q->cease = new_link;
	}else{
		section("memory allocation failed");
	}
}

int dequeue(QUEUE* Q){
	int ret_val = -1;
	LINK to_remove = Q->start;
	
	if(to_remove != NULL) {
		ret_val = Q->start->element;
		Q->start = Q->start->next;
		free(to_remove);
	}else{
		printf("queue is empty");
	}
	return ret_val;
}

void queue_test(){
	QUEUE Q;
	Q.start = NULL;
	Q.cease = NULL;
	
	int examples[] = {1, 2, 3, 4, 5, 0, 9, 8, 7, 6};
	int i;
	for(i = 0; i< 10; i++){
		enqueue(examples[i], &Q);
	}
	for(i = 0; i< 10; i++){
		printf("%d ->", dequeue(&Q));
	}
}

// =======================================================================
