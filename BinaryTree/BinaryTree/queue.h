#pragma once
#include"BinaryTree.h"

typedef BiTree QDataType;

typedef struct QueueNode {
    QDataType data;
    struct QueueNode* next;
}QueueNode;

typedef struct Queue {
    QueueNode* head;
    QueueNode* tail;
    //size_t S_size;
}Queue;

void QueueInit(Queue* pq);

void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq, QDataType x);

void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);

QDataType QueueBack(Queue* pq);

int QueueSize(Queue* pq);

bool QueueEmpty(Queue* pq);