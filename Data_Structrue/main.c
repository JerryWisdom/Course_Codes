#include <stdio.h>
#include "linear_list.h"

int main() {

	printf("Hello!!!Now start the test!\n\n");

	SqList ll;
	InitList_Sq(&ll);
	printf("Linear List has initialized!\n");
	printf("It's length is %d and it's size is %d.\n\n", ll.length, ll.listsize);

	ListInsert_Sq(&ll, 1, 1);
	ListInsert_Sq(&ll, 2, 2);
	ListInsert_Sq(&ll, 3, 3);
	printf("1,2,3 have been inserted.\n\n");

	ListPrint_Sq(ll);

	ElemType delElem;
	ListDelete_Sq(&ll, 2, &delElem);
	printf("Ord2. has been deleted.\n");
	printf("The delElem is %d\n", delElem);
	ListPrint_Sq(ll);

	ClearList(&ll);
	printf("The list has been cleared.\n\n");

	if (ListEmpty(ll)) printf("The list is empty now!\n\n");

	return 0;

}