#include"Queue.h"

void QueueInit(Queue* pq) {

	assert(pq);

	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq) {

	assert(pq);

	QueueNode* cur;
	cur = pq->head;
	while (cur) {
		QueueNode* Next = cur->next;
		free(cur);
		cur = Next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x) {

	assert(pq);

	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	NewNode->data = x;
	NewNode->next = NULL;//这个自己写忘了。
	if (pq->head == NULL) {
		pq->head = pq->tail = NewNode;
	}
	else {
		pq->tail->next = NewNode;
		pq->tail = NewNode;
	}
}

void QueuePop(Queue* pq) {

	assert(pq);
	assert(pq->head);

	QueueNode* next = pq->head->next;
	free(pq->head);

	pq->head = next;

	if (pq->head == NULL) {
		pq->tail = NULL;
	}
}

QDataType QueueFront(Queue* pq) {
	assert(pq);

	assert(pq->head);

	return pq->head->data;
}

QDataType QueueBack(Queue* pq) {
	assert(pq);

	assert(pq->head);

	return pq->tail->data;
}

int QueueSize(Queue* pq) {
	int size = 0;
	QueueNode* cur = pq->head;
	while (cur) {
		size++;
		cur = cur->next;
	}
	return size;
}

bool QueueEmpty(Queue* pq) {

	assert(pq);

	return pq->head == NULL;
}
