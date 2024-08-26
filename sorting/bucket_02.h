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
// LINK LIST FUNCTIONS 1
// =======================================================================

typedef struct node{
	int element;
	struct node* next;
}*LINK, NODE;

void insert_first(int new_element, LINK* old_link){
	LINK new_link = NULL;
	new_link = (LINK)malloc(sizeof(NODE));
	
	if(new_link != NULL){
		new_link->element = new_element;
		new_link->next = *old_link;
		*old_link = new_link;
	}else{
		section("memory allocation failed");
	}
}

void display_LL(LINK L){
	printf("\n");
	while(L != NULL){
		printf(" -> %d", L->element);
		L = L->next;
	}
}

void bubble_sort_LL(LINK L){
	int num_elements_in_bucket = 0;

	LINK trav = L;
	while(trav != NULL){
		trav = trav->next;
		num_elements_in_bucket++;
	}

	int i, j;
	int temp;
	for(i = 1; i < num_elements_in_bucket; i++){
		trav = L;
		for(j = 0; j < num_elements_in_bucket - i; j++){
			if(trav->element > trav->next->element){
				temp = trav->element;
				trav->element = trav->next->element;
				trav->next->element = temp;
			}
			trav = trav->next;
		}
	}
}

// =======================================================================
// BUCKET SORT
// =======================================================================

#define NUMBER_OF_BUCKETS 10
typedef LINK BUCKET_TYPE;

// hash / which bucket to put the element in
int bucket_index(int element){
	return element / NUMBER_OF_BUCKETS;
}

int* sort(int elements[NUMBER_OF_ELEMENTS]){

	// initialize the buckets
	BUCKET_TYPE buckets[NUMBER_OF_BUCKETS];
	memset(buckets, 0, sizeof(buckets));

	// insert elements into their buckets
	int i;
	for(i = 0; i < NUMBER_OF_ELEMENTS; i++){
		insert_first(elements[i], &(buckets[bucket_index(elements[i])]));
	}

	section("display bucketing");
	for(i = 0; i < NUMBER_OF_BUCKETS; i++){
		display_LL(buckets[i]);
	}

	for(i = 0; i < NUMBER_OF_BUCKETS; i++){
		bubble_sort_LL(buckets[i]);
	}

	section("display after sorted in bucket");
	for(i = 0; i < NUMBER_OF_BUCKETS; i++){
		display_LL(buckets[i]);
	}

	section("concatenating after sorting");
	int j = 0;
	for(i = 0; i < NUMBER_OF_BUCKETS; i++){
		LINK trav = buckets[i];
		while(trav != NULL){
			elements[j] = trav->element;
			j++;
			trav = trav->next;
		}
	}
	return elements;
}