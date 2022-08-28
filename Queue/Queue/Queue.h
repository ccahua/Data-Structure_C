#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

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
//void QueueInit(QueueNode** pphead,QueueNode** pptail);//这是不用结构体封装队列函数参数。

void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq, QDataType x);

void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);

QDataType QueueBack(Queue* pq);

int QueueSize(Queue* pq);

bool QueueEmpty(Queue* pq);