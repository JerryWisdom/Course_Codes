#include "link_list.h"

int main() {
	LinkList La;
	CreateList_L(&La, 0);
	ListInsert_L(&La, 1, 1);
	ListInsert_L(&La, 2, 3);
	ListInsert_L(&La, 3, 5);
	printf("List a:\n");
	PrintList_L(La);
	printf("\n");

	LinkList Lb;
	CreateList_L(&Lb, 0);
	ListInsert_L(&Lb, 1, 2);
	ListInsert_L(&Lb, 2, 4);
	ListInsert_L(&Lb, 3, 6);
	printf("List b:\n");
	PrintList_L(Lb);
	printf("\n");

	printf("Merge a and b:\n");
	LinkList Lc;
	MergeList_L(&La, &Lb, &Lc);
	PrintList_L(Lc);
	printf("\n");

	ElemType item;
	GetElem_L(Lc, 3, &item);
	printf("Get 3rd item: %d\n", item);
	ListDelete_L(&Lc, 4, &item);
	printf("Delete 4rd item: %d\n", item);
	printf("Now Lc is:\n");
	PrintList_L(Lc);

	return 0;
}