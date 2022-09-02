#include"Stack.h"

void StackInit(ST* ps) {
	assert(ps);

	ps->a = NULL;
	ps->top = 0;//ps->top = -1;如果等于-1，top最后指向最上面的数。
	ps->capacity = 0;
}

void StackDestroy(ST* ps) {
	assert(ps);
	free(ps->a);
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x) {
	assert(ps);

	if (ps->top == ps->capacity) {
		//增容
		int NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * NewCapacity);
		if (tmp == NULL) {
			printf("remalloc fail！\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = NewCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps) {
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}

STDataType StackTop(ST* ps) {
	assert(ps);

	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

int StackSize(ST* ps) {
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST* ps) {
	assert(ps);

	return ps->top == 0;
}
