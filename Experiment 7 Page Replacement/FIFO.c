#include <stdio.h>

#define FRAMESIZE 3

int main(){

	int frames[FRAMESIZE] = {0};

	int page_count;

	int page_fault_count = 0;
	
	printf("Enter number of pages : ");
	scanf(" %d", &page_count);

	for (int count = 0; count < page_count; count++)
    {
		int page_value;
		int found_flag = 0;
		printf("Enter page no : ");
		scanf(" %d", &page_value);

		for (int idx = 0; idx < FRAMESIZE; idx++){
			if (frames[idx] == page_value){
				printf("Page %d is already loaded.\n", page_value);
				found_flag = 1;
				break;
			} else {
				found_flag = 0;
			}
		}

		if (found_flag == 0){
			page_fault_count += 1;
			for (int idx = FRAMESIZE - 1; idx > 0; idx--){
				frames[idx] = frames[idx - 1];
			}
			frames[0] = page_value;
		}
		printf("Current page sequence is : ");
		for (int idx = 0; idx < FRAMESIZE; idx++){
			printf(" %d", frames[idx]);
		}
		printf("\n");
	}

	printf("Total page faults : %d\n", page_fault_count);

	return 0;
}