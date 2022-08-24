#include"DList.h"

LTNode* ListInit() {
	//�ڱ�λͷ�ڵ�
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
		printf("������Ϊ�գ�");

		//����assert(tail == phead);
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
	//����������ʦд�ģ�ȷʵ�ܼ�࣬���������Ĵ������ҵ�Ŀ�ꡣ
	//LTNode* next = phead->next;
	//phead->next = NewNode;
	//NewNode->prev = phead;

	//NewNode->next = next;
	//next->prev = NewNode;
	/*
	* �������Լ���д��
	if (phead->prev == phead) {
		//�������Ϊ��
		NewNode->prev = phead;
		phead->next = NewNode;
		NewNode->next = phead;
		phead->prev = NewNode;
	}
	else {
		//����Ϊ��
		NewNode->prev = phead;
		phead->next->prev = NewNode;
		NewNode->next = phead->next;
		phead->next = NewNode;
	}*/

}

void ListPopFront(LTNode* phead) {

	assert(phead);

	if (phead->prev == phead) {
		printf("������Ϊ�գ�");
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

//posλ��֮ǰ����ڵ�
void ListInsert(LTNode* pos, LDataType x) {
	LTNode* posPrev = pos->prev;
	LTNode* NewNode = BuyListNode(x);
	posPrev->next = NewNode;
	NewNode->prev = posPrev;

	NewNode->next = pos;
	pos->prev = NewNode;
}

//ɾ��posλ�õĽڵ�
void ListErase(LTNode* pos) {

	assert(pos);

	LTNode* posPrev = pos->prev,*next = pos->next;
	posPrev->next = next;
	next->prev = posPrev;
	free(pos);
	pos = NULL;//û��Ҫ
}