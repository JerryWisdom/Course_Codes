#include <stdio.h>
#include "linear_list.h"

int main() {

	printf("Hello!!!Now start the test!\n\n");

	SqList ll;
	InitList_Sq(&ll);
	printf("Linear List has initialized!\n");
	printf("It's length is %d and it's size is %d\n\n", ll.length, ll.listsize);

	ListInsert_Sq(&ll, 1, 1);
	ListInsert_Sq(&ll, 2, 2);
	ListInsert_Sq(&ll, 3, 3);
	printf("1,2,3 have been inserted.\n");

	Print_Sq(ll);

	return 0;

}