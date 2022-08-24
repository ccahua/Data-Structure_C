#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LDataType;

typedef struct ListNode {
	LDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* ListInit();
LTNode* BuyListNode(LDataType x);
void ListPrint(LTNode* phead);
void ListDestroy(LTNode* phead);

void ListPushBack(LTNode* phead, LDataType x);
void ListPopBack(LTNode* phead);

void ListPushFront(LTNode* phead,LDataType x);
void ListPopFront(LTNode* phead);

LTNode* ListFind(LTNode* phead, LDataType x);

void ListInsert(LTNode* pos, LDataType x);
void ListErase(LTNode* pos);