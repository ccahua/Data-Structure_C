#include"Stack.h"

void TestStack() {
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	StackDestroy(&st);
}

void TestStack1() {
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	while (!StackEmpty(&st)) {
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	StackDestroy(&st);
}

int main() {
	//TestStack();
	TestStack1();
	return 0;
}