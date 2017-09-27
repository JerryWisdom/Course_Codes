#pragma once
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE	100	// 线性表储存空间的初始分配量
#define LISTINCREMENT	10	// 线性表储存空间的分配增量
#define OK 1
#define ERROR 0
#define True 1
#define False 0
typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType *elem;			// 存储空间基址
	int		length;			// 当前长度
	int		listsize;		// 当前分配的存储容量（以sizeof(ElemType)为单位）
}SqList;

Status InitList_Sq(SqList *L) {
	// 构造一个空的线性表
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	// if (!L.elem) return ERROR;
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
} 

Status ClearList(SqList *L) {
	// if (!L->elem) return ERROR;
	L->length = 0;
	return OK;
}

Status ListEmpty(SqList L) {
	// if (!L.elem) return ERROR;
	if (L.length == 0) return True;
	else return False;
}

Status ListLength(SqList L) {
	// if (!L.elem) return ERROR;
	return L.length;
}

Status GetElem(SqList L, int i, ElemType *e) {
	// if (!L.elem) return ERROR;
	if (L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.elem[i - 1];
	return OK;
} 

Status ListPrint_Sq(SqList L) {
	// if (!L.elem) return ERROR;
	int i;
	for (i = 0; i < L.length; i++)
		printf("%02d: %d\n", i+1, L.elem[i]);
	printf("\n");
	return OK;
}

Status ListInsert_Sq(SqList *L, int i, ElemType e) {
	// 在顺序表L中第i个位置之前插入新的元素e
	// if (!L->elem) return ERROR;
	if (i < 1 || i >L->length + 1) return ERROR;
	
	int k;
	for (k = L->length - 1; k >= i-1; k--)
		L->elem[k + 1] = L->elem[k];
	L->elem[i - 1] = e;
	L->length++;
	return OK;
}

Status ListDelete_Sq(SqList *L, int i, ElemType *e) {
	// 在顺序表L中删除第i个位置的元素，并且返回e值
	// if (!L->elem) return ERROR;
	if (i < 1 || i>L->length || L->length == 0) return ERROR;
	*e = L->elem[i - 1];
	
	int k;
	for (k = i; k < L->length; k++)
		L->elem[k - 1] = L->elem[k];
	L->length--;
	return OK;
} 

void MergeList_Sq(SqList La, SqList Lb, SqList *Lc) {
	// if (!La.elem) return ERROR;
	// if (!Lb.elem) return ERROR;

	ElemType *pa = La.elem; ElemType *pb = Lb.elem;
	Lc->listsize = Lc->length = La.length + Lb.length;
	ElemType *pc = Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType));
	// if (!Lc.elem) return ERROR;
	ElemType *pa_last = La.elem + La.length - 1;
	ElemType *pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++;
	while (pb <= pb_last) *pc++ = *pb++;
}


/********************************************** 测试用例

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
**********************************************/