#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "stdhead.h"

#define MAXSIZE 1000	// 静态链表的最大长度

// 线性表的静态链表的存储结构
typedef struct {
	ElemType data;		// 数据域
	int cur;			// 游标，相当于*next的作用
} Component, SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S, ElemType e) {
	// 在静态单链线性表L中查找第1个值为e的元素
	// 若找到，则返回它在L中的位序，否则返回0

	int i = S[0].cur;		// S[0]为表中第一个结点
	while (i && S[i].data != e) i = S[i].cur;
	return i;
}

void InitSpace_SL(SLinkList space) {
	// 将一维数组space中各分量链成一个备用链表，space[0].cur为头指针
	// “0”表示为空指针

	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
}

int Malloc_SL(SLinkList space) {
	// 若备用空间列表非空，则返回分配的结点下标，否则返回0

	int	i = space[0].cur;		// 返回第一个备用空间的下标
	if (space[0].cur)
		space[0].cur = space[i].cur;

	return i;
}

void Free_SL(SLinkList space, int k) {
	// 将下标为k的空闲结点回收到备用链表

	space[k].cur = space[0].cur;
	space[0].cur = k;
}

Status ListInsert_SL(SLinkList L, int i, ElemType e) {
	// 在L中第i个元素之前插入新的元素e

	int j, k, l;
	k = MAXSIZE - 1;
	// if (i < 1 || i > ListLength(L))	return ERROR;
	j = Malloc_SL(L);		// 获得空闲分量的下标
	if (j) {
		L[j].data = e;		// 将数据赋值给此分量的data
		for (l = 1; l <= i - 1; l++) {
			// 找到第i个元素之前的位置
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;	// 把第i个元素之前的cur赋值给新元素的cur
		L[k].cur = j;			// 把新元素的下标赋值给第i个元素之前元素的cur
		return OK;
	}
	return ERROR;
}

Status ListDelete_SL(SLinkList L, int i) {
	// 删除在L中第i个元素e

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

