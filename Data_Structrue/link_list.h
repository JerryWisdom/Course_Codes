#pragma once
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define True 1
#define False 0
typedef int ElemType;
typedef int Status;

// 线性链表的单链表存储结构
typedef struct LNode {		
	ElemType	data;		// 数据域
	struct LNode *next;		// 指针域
} LNode ;

typedef struct LNode *LinkList;

Status GetElem_L(LinkList L, int i, ElemType *e) {
	// L为带头结点的单链表的头指针
	// 当第i个元素存在时，其值赋值给e并返回OK，否则返回ERROR

	LinkList p = L->next;	// 声明一个结点p并且指向L的第一个结点
	int j = 1;				// j为计数器
	while (p && j < i) {	// 寻找第i个结点
		p = p->next;		// 让p指向下一个结点
		j++;
	}
	if (!p || j > i) return ERROR;
	*e = p->data;			// 取第i个元素赋值给e
	return OK;
}

Status ListInsert_L(LinkList *L, int i, ElemType e) {
	// 在带头结点的单链线性表L中第i个位置之前插入元素e

	LinkList p = *L;
	int j = 0;
	while (p && j < i - 1) { // 寻找第i-1个结点
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete_L(LinkList *L, int i, ElemType *e) {
	// 在带头结点的单链线性链表L中，删除第i个元素，并由e返回其值

	LinkList p = *L;
	int j = 0;
	while (p->next && j < i-1) {
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) return ERROR;
	LinkList q = p->next;	// 先后顺序不能搞错
	p->next = q->next;
	*e = q->data;
	free(q);				// 让系统回收此结点，释放内存
	return OK;
}

void CreateList_L(LinkList *L, int n) {
	// 逆位序输入n个元素的值，建立带表头结点的单线性链表L

	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;		// 先建立一个带头结点的单链表

	LinkList p;
	int i;
	for (i = n; i > 0; i--) {
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d",p->data);
		p->next = (*L)->next;
		(*L)->next = p;		// 插入到表头
	}
}

Status ClearList_L(LinkList *L) {
	// 将L重置为空表

	LinkList p, q;
	p = (*L)->next;		// p指向第一个结点
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc) {
	// 已知单链线性链表La和Lb的元素按值非递减排列
	// 归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列

	LinkList pa = (*La)->next;
	LinkList pb = (*Lb)->next;
	*Lc = *La;
	LinkList pc = *La;		// 用La的头结点作为Lc的头结点
							// 注意链表合并改变的是指针指向，无需申请新内存
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;	// 插入剩余段
	free(*Lb);		// 释放Lb的头结点
}

Status PrintList_L(LinkList L) {
	LinkList p = L->next;
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
**********************************************/