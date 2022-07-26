#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 1000
typedef int SLDataType;

//静态顺序表的特点：如果数据插满了，就不让插入。缺点：给多大的空间合适呢？这个很难确定
//内存给多了浪费，给小了不够用。
/*静态链表
typedef struct SeqList {
	SLDataType a[N];
	int size;//数组的大小
}SL;*/

//动态链表
typedef struct SqlList {
	SLDataType* a;
	int size;
	int capacity;
}SL;

//接口函数----命名风格是跟着STL走，方便后面学习STL;
void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);
void SeqListMoreCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
int SeqListFind(SL* ps, SLDataType x);
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);
//...
