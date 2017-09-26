#pragma once
#include <stdlib.h>
#define LIST_INIT_SIZE	100	// ���Ա���ռ�ĳ�ʼ������
#define LISTINCREMENT	10	// ���Ա���ռ�ķ�������
#define OK 1
#define ERROR 0
#define True 1
#define False 0
typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType *elem;			// �洢�ռ��ַ
	int		length;			// ��ǰ����
	int		listsize;		// ��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
}SqList;

Status InitList_Sq(SqList *L) {
	// ����һ���յ����Ա�
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
	// ��˳���L�е�i��λ��֮ǰ�����µ�Ԫ��e
	if (i < 1 || i >L->length + 1) return ERROR;
	
	int k;
	for (k = L->length - 1; k >= i; k--)
		L->elem[k + 1] = L->elem[k];
	L->elem[i - 1] = e;
	L->length++;
	return OK;
} // ListInsert.Sq

/* �� 2-1

void union(List *La, List Lb) {
	// �����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
	int La_len, Lb_len, i;
	ElemType e;						// ������La��Lb��ͬ������Ԫ��e
	La_len = ListLength(La);		// �����Ա��ȣ���ͬ
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++) {
		GetElem(Lb, i, e);			// ȡLb�е�i������Ԫ�ظ���e
		if (!LocateElem(La, e, equal))	// La�в����ں�e��ͬ������Ԫ��
			ListInsert(La, ++La_len, e);
	}
}
*/ 