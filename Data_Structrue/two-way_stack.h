#pragma once
#include "stdhead.h"
#include "stdio.h"
#define MAXSIZE 100

// ˫��ջ�Ĵ���ṹ
typedef struct sqDoubleStack {
	ElemType data[MAXSIZE];		// ����һά����洢
	int top1;					// ջ1: ջ��ָ��
	int top2;					// ջ2: ջ��ָ��
} sqDoubleStack ;

// ��ʼ������
void inistack(sqDoubleStack *tws) {
	tws->top1 = -1;
	tws->top2 = MAXSIZE;
}

// �ж��Ƿ�ջ��
Bool full(sqDoubleStack tws) {
	if (tws.top1 + 1 == tws.top2) return True;
	else return False;
}

// ��ջ
Status push(sqDoubleStack *tws, int stackNumber, ElemType x) {
	if (full(*tws)) return ERROR;
	if (stackNumber == 0)
		tws->data[++tws->top1] = x;
	else if (stackNumber == 1)
		tws->data[--tws->top2] = x;
	return OK;
}

// �ж��Ƿ�ջ��
Bool empty(sqDoubleStack tws, int stackNumber) {
	if (stackNumber == 0 && tws.top1 == -1) return True;
	else if (stackNumber == 1 && tws.top2 == MAXSIZE) return True;
	return False;
}

// ��ջ
ElemType pop(sqDoubleStack *tws, int stackNumber) {
	if (empty(*tws, stackNumber)) return ERROR;
	if (stackNumber == 0) {
		ElemType e = tws->data[tws->top1];
		tws->top1--;
		return e;
	}
	else if (stackNumber == 1) {
		ElemType e = tws->data[tws->top2];
		tws->top2++;
		return e;
	}
	return OK;
}

/********************************************** ��������
#include "two-way_stack.h"

int main() {

	sqDoubleStack doge;
	inistack(&doge);
	if (empty(doge, 0) && empty(doge, 1))
		printf("Now the two-way stack is completely empty!\n\n");
	push(&doge, 0, 1);
	push(&doge, 0, 3);
	push(&doge, 0, 5);
	push(&doge, 1, 2);
	push(&doge, 1, 4);
	push(&doge, 1, 6);

	ElemType e;
	e = pop(&doge, 0);
	printf("%d\n\n", e);		// 5
	e = pop(&doge, 1);
	printf("%d\n\n", e);		// 6

	return 0;
}
**********************************************/