#include "linear_list.h"

int main() {

	SqList La, Lb, Lc;
	InitList_Sq(&La);
	InitList_Sq(&Lb);

	ListInsert_Sq(&La, 1, 1);
	ListInsert_Sq(&La, 2, 3);
	ListInsert_Sq(&La, 3, 5);
	printf("List a:\n");
	ListPrint_Sq(La);

	ListInsert_Sq(&Lb, 1, 2);
	ListInsert_Sq(&Lb, 2, 4);
	ListInsert_Sq(&Lb, 3, 6);
	printf("List b:\n");
	ListPrint_Sq(Lb);

	MergeList_Sq(La, Lb, &Lc);
	printf("List c:\n");
	ListPrint_Sq(Lc);

	printf("Delete 6th number.\n");
	ElemType delElem;
	ListDelete_Sq(&Lc, 6, &delElem);
	ListPrint_Sq(Lc);
	printf("The delElem is %d.\n", delElem);
	return 0;
}