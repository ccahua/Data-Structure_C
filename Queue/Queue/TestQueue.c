#include"Queue.h"
#include"Mystack.h"

void TestQueue() {
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	//QueuePop(&q);
}

void TestQueue1() {
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QDataType x = QueueFront(&q);
	printf("%d\n", x);

	QDataType y = QueueBack(&q);
	printf("%d\n", y);

	int size = QueueSize(&q);
	printf("QueueSize = %d\n", size);

	if (QueueEmpty(&q)) {
		printf("Queue is Empty!");
	}
	else {
		printf("Queue is not Empty");
	}
}

void TestStack() {
	MyStack* mystack = myStackCreate();
	myStackPush(mystack, 1);
	myStackPush(mystack, 2);
	myStackPush(mystack, 3);
	myStackPush(mystack, 4);
	int top = myStackPop(mystack);
	int NUm = top;
	printf("%d", NUm);
	myStackPop(mystack);
	printf("%d\n",myStackTop(mystack));
	myStackEmpty(mystack);
}

int main() {

	//TestQueue();
	//TestQueue1();
	TestStack();
	return 0;
}