#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "stdhead.h"

#define MAXSIZE 1000	// ��̬�������󳤶�

// ���Ա�ľ�̬����Ĵ洢�ṹ
typedef struct {
	ElemType data;		// ������
	int cur;			// �α꣬�൱��*next������
} Component, SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S, ElemType e) {
	// �ھ�̬�������Ա�L�в��ҵ�1��ֵΪe��Ԫ��
	// ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0

	int i = S[0].cur;		// S[0]Ϊ���е�һ�����
	while (i && S[i].data != e) i = S[i].cur;
	return i;
}

void InitSpace_SL(SLinkList space) {
	// ��һά����space�и���������һ����������space[0].curΪͷָ��
	// ��0����ʾΪ��ָ��

	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
}

int Malloc_SL(SLinkList space) {
	// �����ÿռ��б�ǿգ��򷵻ط���Ľ���±꣬���򷵻�0

	int	i = space[0].cur;		// ���ص�һ�����ÿռ���±�
	if (space[0].cur)
		space[0].cur = space[i].cur;

	return i;
}

void Free_SL(SLinkList space, int k) {
	// ���±�Ϊk�Ŀ��н����յ���������

	space[k].cur = space[0].cur;
	space[0].cur = k;
}

Status ListInsert_SL(SLinkList L, int i, ElemType e) {
	// ��L�е�i��Ԫ��֮ǰ�����µ�Ԫ��e

	int j, k, l;
	k = MAXSIZE - 1;
	// if (i < 1 || i > ListLength(L))	return ERROR;
	j = Malloc_SL(L);		// ��ÿ��з������±�
	if (j) {
		L[j].data = e;		// �����ݸ�ֵ���˷�����data
		for (l = 1; l <= i - 1; l++) {
			// �ҵ���i��Ԫ��֮ǰ��λ��
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;	// �ѵ�i��Ԫ��֮ǰ��cur��ֵ����Ԫ�ص�cur
		L[k].cur = j;			// ����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰԪ�ص�cur
		return OK;
	}
	return ERROR;
}

Status ListDelete_SL(SLinkList L, int i) {
	// ɾ����L�е�i��Ԫ��e

	int j, k;
	// if (i < 1 || i > ListLength(L))	return ERROR;
	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; j++)
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SL(L, j);
	return OK;
}

