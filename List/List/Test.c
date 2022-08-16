#include"SList.h"

void Test1() {
	SLTNode* pList = NULL;
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 1);
	SListPrint(pList);
}

void Test2() {
	SLTNode* pList = NULL;
	SListPushFront(&pList, 5);
	SListPushFront(&pList, 4);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 1);
	SListPrint(pList);
}

void Test3() {
	SLTNode* pList = NULL;
	SListPushFront(&pList, 5);
	SListPushFront(&pList, 4);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 1);
	SListPrint(pList);

	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);
}

void Test4() {
	SLTNode* pList = NULL;
	SListPushFront(&pList, 5);
	SListPushFront(&pList, 4);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 1);
	SListPrint(pList);

	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(pList);
}

void Test5() {
	SLTNode* pList = NULL;
	SListPushFront(&pList, 5);
	SListPushFront(&pList, 4);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 1);
	SListPrint(pList);

	SLTNode* pos = SListFind(pList, 1);
	/*if (pos) {
		SListInsert(&pList, pos, 6);
	}
	SListPrint(pList);

	pos = SListFind(pList, 6);
	if (pos) {
		SListErase(&pList, pos);
	}
	SListPrint(pList);

	pos = SListFind(pList, 1);
	if (pos) {
		SListInsertAfter(pos,10);
	}
	SListPrint(pList);*/

	pos = SListFind(pList, 1);
	if (pos) {
		SListEraseAfter(pos);
	}
	SListPrint(pList);
}

int main() {
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5(); 
	return 0;
}