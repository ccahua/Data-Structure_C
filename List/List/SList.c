#include"SList.h"

SLTNode* BuySLTNode(SLTDataType x) {
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL) {//检查一下申请是否成功。
		printf("malloc fail!\n");
		exit(-1);//结束程序
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void SListPrint(SLTNode* phead) {
	if (phead == NULL) {
		printf("该链表为空！");
	}
	else {
		SLTNode* cur = phead;
		while (cur->next != NULL) {
			printf("%d->", cur->data);
			cur = (*cur).next;
		}
		printf("%d", cur->data);
		printf("\n");
	}
}

void SListDestory(SLTNode** pphead) {
	//这是可以检测到函数调用时，使用了错误的参数，如果调用时，传入的是plist就会终止。
	assert(pphead);
	SLTNode* tmp = *pphead;
	while ((*pphead)->next != NULL) {
		*pphead = (*pphead)->next;
		free(tmp);
		tmp = *pphead;
	}
	free(*pphead);
	*pphead = NULL;
}

void SListPushBack(SLTNode** pphead, SLTDataType x) {
	//这里使用二级指针就是为了解决头结点为空的问题。
	SLTNode* newNode = BuySLTNode(x);
	//判断phead是否为空
	if (*pphead == NULL) {
		*pphead = newNode;
	}
	else {
		//寻找尾节点
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//添加数据
		tail->next = newNode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newNode = BuySLTNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

void SListPopBack(SLTNode** pphead) {
	assert(pphead);
	//粗暴一点的方式
	//assert(*phead);
	//温柔一点的方式
	if (*pphead == NULL) {
		return;
	}
	SLTNode* tail = *pphead;
	if (tail->next == NULL) {
		free(tail);
		*pphead = NULL;
	}
	else {
		//这是我写的
		while (tail->next != NULL) {
			tail = tail->next;
		}
		SLTNode* tmp = *pphead;
		while (tmp->next != tail) {
			tmp = tmp->next;
		}
		tmp->next = NULL;
		free(tail);
		tail = NULL;
		
		/*这是老师写的第一种方法(这个方法做题的时候遇到了）
		SLTNode* prev = NULL;
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
		tail = NULL;
		*/
		/*这是老师写的第二种方法
		while (tail->next->next) {
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
		tail = NULL;
		*/
	}
}

void SListPopFront(SLTNode** pphead) {
	//这是我先完之后，改过之后的
	if (*pphead == NULL) {
		return;
	}
	else {
		SLTNode* tmp = *pphead;
		*pphead = (*pphead)->next;
		free(tmp);
		tmp = NULL;
	}
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x) {
	/*	这个是我自己提前写的，有明显的逻辑错误，如果第一个节点就是查找的对象，那么就错了。
	SLTNode* tmp = phead;
	while (tmp->data != x && tmp->next != NULL) {
		tmp = tmp->next;
		if (tmp->data == x) {
			return tmp;
		}
	}
	return NULL;
	*/
	//这是老师写的，简洁，正确。这个还有修改的作用，查找后直接使用指针然后直接修改data，
	SLTNode* cur = phead;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		else {
			cur = cur->next;
		}
	}
	return NULL;
}

//在pos位置之后插入数据。
void SListInsertAfter(SLTNode* pos, SLTDataType x) {
	//这里表示如果pos指针为空，也是违法的。
	assert(pos);
	SLTNode* NewNode = BuySLTNode(x);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

//在pos位置之前插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pos);
	assert(pphead);
	SLTNode* NewNode = BuySLTNode(x);
	SLTNode* tmp = *pphead;

	if (tmp == pos) {
		*pphead = NewNode;
		(*pphead)->next = tmp;
	}
	else {
		while (tmp->next != pos) {
			tmp = tmp->next;
			if (tmp->next == pos) {
				tmp->next = NewNode;
				NewNode->next = pos;
			}
		}
	}
}

void SListErase(SLTNode** pphead, SLTNode* pos) {
	assert(pos);
	assert(pphead);
	SLTNode* tmp = *pphead;
	if (tmp == pos) {
		*pphead = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	else {
		while (tmp->next != pos) {
			tmp = tmp->next;
		}
		tmp->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListEraseAfter(SLTNode* pos) {
	assert(pos);
	if (pos->next == NULL) {
		return;
	}
	else {
		SLTNode* tmp = pos->next;
		pos->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}
