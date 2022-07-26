#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 1000
typedef int SLDataType;

//��̬˳�����ص㣺������ݲ����ˣ��Ͳ��ò��롣ȱ�㣺�����Ŀռ�����أ��������ȷ��
//�ڴ�������˷ѣ���С�˲����á�
/*��̬����
typedef struct SeqList {
	SLDataType a[N];
	int size;//����Ĵ�С
}SL;*/

//��̬����
typedef struct SqlList {
	SLDataType* a;
	int size;
	int capacity;
}SL;

//�ӿں���----��������Ǹ���STL�ߣ��������ѧϰSTL;
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
