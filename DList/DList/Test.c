#include"DList.h"


void ListTest1() {
	LTNode* plist = ListInit();

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);


	ListPrint(plist);
}

void ListTest2() {
	LTNode* plist = ListInit();

	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);

	LTNode* Node = ListFind(plist, 2);
	if (Node) {
		ListErase(Node);
	}
	ListPrint(plist);
}

void ListTest3() {
	LTNode* plist = ListInit();

	ListDestroy(plist);
	plist = NULL;

	ListPrint(plist);
}
int main() {
	//ListTest1();
	//ListTest2();
	ListTest3();
	return 0;
}