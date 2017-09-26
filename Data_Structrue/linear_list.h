#pragma once
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
	L->length = 0;
	return OK;
}

Status ListEmpty(SqList L) {
	if (L.length == 0) return True;
	else return False;
}

Status ListLength(SqList L) {
	return L.length;
}

Status GetElem(SqList L, int i, ElemType *e) {
	if (L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.elem[i - 1];
	return OK;
} 

Status ListPrint_Sq(SqList L) {
	int i;
	for (i = 0; i < L.length; i++)
		printf("%02d: %d\n", i+1, L.elem[i]);
	printf("\n");
	return OK;
}

Status ListInsert_Sq(SqList *L, int i, ElemType e) {
	// 在顺序表L中第i个位置之前插入新的元素e
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
	if (i < 1 || i>L->length || L->length == 0) return ERROR;
	*e = L->elem[i - 1];
	
	int k;
	for (k = i; k < L->length; k++)
		L->elem[k - 1] = L->elem[k];
	L->length--;
	return OK;
} 


/* The part is for test.

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
*/