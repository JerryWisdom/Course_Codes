#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "stdhead.h"

// 线性链表的单链表存储结构
typedef struct LinkNode {		
	ElemType	data;		// 数据域
	struct LinkNode *next;		// 指针域
} LinkNode ;

// 带头、尾结点指针及表长的单链表结构
typedef struct LinkList {
	struct LinkNode *head;
	struct LinkNode *tail;
	int len;
} LinkList ;

// 单链表初始化
void InitList_L(LinkList *L) {
	L->len = 0;
	L->head = L->tail = (LinkNode*)malloc(sizeof(LinkNode));
	L->head->next = NULL;
}

// 释放单链表中所有数据结点
Status ClearList_L(LinkList *L) {

	LinkNode *p = L->head->next, *q;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->tail = L->head;
	L->head->next = NULL;
	L->len = 0;
	return OK;
}

// 销毁单链表
void DestroyList_L(LinkList *L) {
	ClearList_L(L);
	free(L->head);
	L->head = L->tail = NULL;
}

// 判断单链表是否为空表
Bool ListEmpty_L(LinkList L) {
	if (L.len == 0) return True;
	else return False;
}

// 求单链表长度
int ListLength_L(LinkList L) {
	return L.len;
}

// 取单链表中第i个结点的数据信息
Status GetElem_L(LinkList L, int i, ElemType *e) {

	if (i < 1 || i > L.len) return ERROR;
	LinkNode *p = L.head->next;	
	int j = 1;			
	while (p && j < i) {	
		p = p->next;		
		j++;
	}
	*e = p->data;			
	return OK;
}

// 从第一个位置起查找与e匹配的数据元素，若存在则返回该元素的数据位置
int LocateElem_L(LinkList *L, ElemType *e,
	Bool(*compare)(ElemType *a, ElemType *b)) {
	int i = 1;
	LinkNode *p = L->head->next;
	while (p && !compare(&(p->data), e)) {
		i++;
		p = p->next;
	}
	if (p)
		return i;
	return 0;
}

// 在单链表中第i个数据元素之前插入新的数据元素e（i的合法值为1<=i<=len+1）
Status ListInsert_L(LinkList *L, int i, ElemType e) {

	if (i < 1 || i > L->len + 1) return ERROR;
	LinkNode *p, *q;
	int j = 1;

	q = (LinkNode*)malloc(sizeof(LinkNode));
	q->data = e;
	p = L->head;

	while (j < i ) {
		p = p->next;
		j++;
	}

	q->next = p->next;
	p->next = q;
	L->len++;
	return OK;
}

// 在单链表中删除第i个数据元素并用数据变量e返回其值（i的合法值为1<=i<=len）
Status ListDelete_L(LinkList *L, int i, ElemType *e) {

	if (i < 1 || i > L->len) return ERROR;
	LinkNode *p, *q;
	int j = 1;
	p = L->head;

	while (j < i) {
		p = p->next;
		j++;
	}

	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	L->len--;

	return OK;
}

// 归并La和Lb得到新的单链线性表Lc，不删除原有的两个链表
void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc) {
	
	int len = La->len + Lb->len;
	LinkNode *pa = La->head->next;
	LinkNode *pb = Lb->head->next;
	InitList_L(Lc);
	LinkNode *p = Lc->head;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			p->next = pa;
			p = pa;
			pa = pa->next;
		}
		else {
			p->next = pb;
			p = pb;
			pb = pb->next;
		}
	}
	p->next = pa ? pa : pb;
	Lc->len = len;
}

Status PrintList_L(LinkList L) {
	LinkNode *p = L.head->next;
	int j = 1;
	while (p) {
		printf("%02d: %d\n", j++, p->data);
		p = p->next;
	}
	return OK;
}


/********************************************** 测试用例
#include "link_list.h"

int main() {
	LinkList La;
	InitList_L(&La);
	ListInsert_L(&La, 1, 1);
	ListInsert_L(&La, 2, 3);
	ListInsert_L(&La, 3, 5);
	printf("List a:\n");
	PrintList_L(La);
	printf("\n");

	LinkList Lb;
	InitList_L(&Lb);
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
**********************************************/