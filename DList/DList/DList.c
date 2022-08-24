#include"DList.h"

LTNode* ListInit() {
	//哨兵位头节点
	LTNode* phead;
	phead = (LTNode*)malloc(sizeof(LTNode));
	phead->prev = phead;
	phead->next = phead;
	return phead;
}

LTNode* BuyListNode(LDataType x) {
	LTNode* NewNode = (LTNode*)malloc(sizeof(LTNode));
	NewNode->data = x;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
}

void ListDestroy(LTNode* phead) {

	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead) {
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
	cur = NULL;
}

void ListPushBack(LTNode* phead, LDataType x) {

	assert(phead);

	ListInsert(phead, x);
	/*LTNode* NewNode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = NewNode;
	NewNode->prev = tail;
	phead->prev = NewNode;
	NewNode->next = phead;*/
}

void ListPopBack(LTNode* phead) {

	assert(phead);

	LTNode* tail = phead->prev;
	if (tail == phead) {
		printf("该链表为空！");

		//或者assert(tail == phead);
	}
	else {
		ListErase(phead->prev);
		/*tail = tail->prev;
		free(tail->next);
		tail->next = phead;
		phead->prev = tail;*/
	}
}

void ListPushFront(LTNode* phead, LDataType x) {

	assert(phead);

	ListInsert(phead->next, x);

	LTNode* NewNode = BuyListNode(x);
	//这下面是老师写的，确实很简洁，我想清晰的代码是我的目标。
	//LTNode* next = phead->next;
	//phead->next = NewNode;
	//NewNode->prev = phead;

	//NewNode->next = next;
	//next->prev = NewNode;
	/*
	* 这是我自己先写的
	if (phead->prev == phead) {
		//如果链表为空
		NewNode->prev = phead;
		phead->next = NewNode;
		NewNode->next = phead;
		phead->prev = NewNode;
	}
	else {
		//链表不为空
		NewNode->prev = phead;
		phead->next->prev = NewNode;
		NewNode->next = phead->next;
		phead->next = NewNode;
	}*/

}

void ListPopFront(LTNode* phead) {

	assert(phead);

	if (phead->prev == phead) {
		printf("该链表为空！");
	}
	else {
		ListErase(phead->next);
		/*LTNode* head = phead->next;
		phead->next = head->next;
		head->next->prev = phead;
		free(head);
		head = NULL;*/
	}
}

void ListPrint(LTNode* phead) {

	assert(phead);

	LTNode* tmp = phead->next; 
	while (tmp != phead) {
		printf("->%d", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

LTNode* ListFind(LTNode* phead, LDataType x) {
	LTNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//pos位置之前插入节点
void ListInsert(LTNode* pos, LDataType x) {
	LTNode* posPrev = pos->prev;
	LTNode* NewNode = BuyListNode(x);
	posPrev->next = NewNode;
	NewNode->prev = posPrev;

	NewNode->next = pos;
	pos->prev = NewNode;
}

//删除pos位置的节点
void ListErase(LTNode* pos) {

	assert(pos);

	LTNode* posPrev = pos->prev,*next = pos->next;
	posPrev->next = next;
	next->prev = posPrev;
	free(pos);
	pos = NULL;//没必要
}