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
} // InitList_Sq

Status GetElem(SqList L, int i, ElemType *e) {
	if (L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.elem[i - 1];
	return OK;
} // GetElem

Status Print_Sq(SqList L) {
	int i;
	for (i = 0; i < L.length; i++)
		printf("%02d: %d\n", i, L.elem[i]);
	return OK;
}

Status ListInsert_Sq(SqList *L, int i, ElemType e) {
	// 在顺序表L中第i个位置之前插入新的元素e
	if (i < 1 || i >L->length + 1) return ERROR;
	
	int k;
	for (k = L->length - 1; k >= i; k--)
		L->elem[k + 1] = L->elem[k];
	L->elem[i - 1] = e;
	L->length++;
	return OK;
} // ListInsert.Sq

/* 例 2-1

void union(List *La, List Lb) {
	// 将所有在线性表Lb中但不在La中的数据元素插入到La中
	int La_len, Lb_len, i;
	ElemType e;						// 声明与La和Lb相同的数据元素e
	La_len = ListLength(La);		// 求线性表长度，下同
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++) {
		GetElem(Lb, i, e);			// 取Lb中第i个数据元素赋给e
		if (!LocateElem(La, e, equal))	// La中不存在和e相同的数据元素
			ListInsert(La, ++La_len, e);
	}
}
*/ 