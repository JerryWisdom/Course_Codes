#pragma once
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define True 1
#define False 0
typedef int ElemType;
typedef int Status;

// ��������ĵ�����洢�ṹ
typedef struct LNode {		
	ElemType	data;		// ������
	struct LNode *next;		// ָ����
} LNode ;

typedef struct LNode *LinkList;

Status GetElem_L(LinkList L, int i, ElemType *e) {
	// LΪ��ͷ���ĵ������ͷָ��
	// ����i��Ԫ�ش���ʱ����ֵ��ֵ��e������OK�����򷵻�ERROR

	LinkList p = L->next;	// ����һ�����p����ָ��L�ĵ�һ�����
	int j = 1;				// jΪ������
	while (p && j < i) {	// Ѱ�ҵ�i�����
		p = p->next;		// ��pָ����һ�����
		j++;
	}
	if (!p || j > i) return ERROR;
	*e = p->data;			// ȡ��i��Ԫ�ظ�ֵ��e
	return OK;
}

Status ListInsert_L(LinkList *L, int i, ElemType e) {
	// �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e

	LinkList p = *L;
	int j = 0;
	while (p && j < i - 1) { // Ѱ�ҵ�i-1�����
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
	// �ڴ�ͷ���ĵ�����������L�У�ɾ����i��Ԫ�أ�����e������ֵ

	LinkList p = *L;
	int j = 0;
	while (p->next && j < i-1) {
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) return ERROR;
	LinkList q = p->next;	// �Ⱥ�˳���ܸ��
	p->next = q->next;
	*e = q->data;
	free(q);				// ��ϵͳ���մ˽�㣬�ͷ��ڴ�
	return OK;
}

void CreateList_L(LinkList *L, int n) {
	// ��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ���������L

	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;		// �Ƚ���һ����ͷ���ĵ�����

	LinkList p;
	int i;
	for (i = n; i > 0; i--) {
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d",p->data);
		p->next = (*L)->next;
		(*L)->next = p;		// ���뵽��ͷ
	}
}

Status ClearList_L(LinkList *L) {
	// ��L����Ϊ�ձ�

	LinkList p, q;
	p = (*L)->next;		// pָ���һ�����
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc) {
	// ��֪������������La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
	// �鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ�����

	LinkList pa = (*La)->next;
	LinkList pb = (*Lb)->next;
	*Lc = *La;
	LinkList pc = *La;		// ��La��ͷ�����ΪLc��ͷ���
							// ע������ϲ��ı����ָ��ָ�������������ڴ�
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
	pc->next = pa ? pa : pb;	// ����ʣ���
	free(*Lb);		// �ͷ�Lb��ͷ���
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


/********************************************** ��������

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