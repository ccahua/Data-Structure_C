#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);

void SListPushBack(SLTNode** pphead, SLTDataType x);

void SListPushFront(SLTNode** pphead, SLTDataType x);

void SListPopBack(SLTNode** phead);

void SListPopFront(SLTNode** pphead);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);

void SListInsertAfter(SLTNode* pos, SLTDataType x);

void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);

//void SListInsert(SLTNode** phead, int pos, SLTDataType x);//这个是通过第几个位置来插入数据

void SListErase(SLTNode** phead, SLTNode* pos);

void SListEraseAfter(SLTNode* pos);

//void SListEase(SLTNode** phead, SLTNode* pos);这是通过第几个位置来删除数据。

void SListDestory(SLTNode** phead);


