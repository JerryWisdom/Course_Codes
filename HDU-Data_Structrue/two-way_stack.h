#pragma once
#include "stdhead.h"
#include "stdio.h"
#define MAXSIZE 100

// À´œÚ’ªµƒ¥¢¥ÊΩ·ππ
typedef struct sqDoubleStack {
	ElemType data[MAXSIZE];		// ¿˚”√“ªŒ¨ ˝◊È¥Ê¥¢
	int top1;					// ’ª1: ’ª∂•÷∏’Î
	int top2;					// ’ª2: ’ª∂•÷∏’Î
} sqDoubleStack ;

// ≥ı ºªØ≤Ÿ◊˜
void inistack(sqDoubleStack *tws) {
	tws->top1 = -1;
	tws->top2 = MAXSIZE;
}

// ≈–∂œ «∑Ò’ª¬˙
Bool full(sqDoubleStack tws) {
	if (tws.top1 + 1 == tws.top2) return True;
	else return False;
}

// »Î’ª
Status push(sqDoubleStack *tws, int stackNumber, ElemType x) {
	if (full(*tws)) return ERROR;
	if (stackNumber == 0)
		tws->data[++tws->top1] = x;
	else if (stackNumber == 1)
		tws->data[--tws->top2] = x;
	return OK;
}

// ≈–∂œ «∑Ò’ªø’
Bool empty(sqDoubleStack tws, int stackNumber) {
	if (stackNumber == 0 && tws.top1 == -1) return True;
	else if (stackNumber == 1 && tws.top2 == MAXSIZE) return True;
	return False;
}

// ≥ˆ’ª
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

/********************************************** ≤‚ ‘”√¿˝
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