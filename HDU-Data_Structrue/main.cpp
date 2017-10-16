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