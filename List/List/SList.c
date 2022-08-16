#include"SList.h"

SLTNode* BuySLTNode(SLTDataType x) {
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL) {//���һ�������Ƿ�ɹ���
		printf("malloc fail!\n");
		exit(-1);//��������
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void SListPrint(SLTNode* phead) {
	if (phead == NULL) {
		printf("������Ϊ�գ�");
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
	//���ǿ��Լ�⵽��������ʱ��ʹ���˴���Ĳ������������ʱ���������plist�ͻ���ֹ��
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
	//����ʹ�ö���ָ�����Ϊ�˽��ͷ���Ϊ�յ����⡣
	SLTNode* newNode = BuySLTNode(x);
	//�ж�phead�Ƿ�Ϊ��
	if (*pphead == NULL) {
		*pphead = newNode;
	}
	else {
		//Ѱ��β�ڵ�
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//�������
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
	//�ֱ�һ��ķ�ʽ
	//assert(*phead);
	//����һ��ķ�ʽ
	if (*pphead == NULL) {
		return;
	}
	SLTNode* tail = *pphead;
	if (tail->next == NULL) {
		free(tail);
		*pphead = NULL;
	}
	else {
		//������д��
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
		
		/*������ʦд�ĵ�һ�ַ���(������������ʱ�������ˣ�
		SLTNode* prev = NULL;
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
		tail = NULL;
		*/
		/*������ʦд�ĵڶ��ַ���
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
	//����������֮�󣬸Ĺ�֮���
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
	/*	��������Լ���ǰд�ģ������Ե��߼����������һ���ڵ���ǲ��ҵĶ�����ô�ʹ��ˡ�
	SLTNode* tmp = phead;
	while (tmp->data != x && tmp->next != NULL) {
		tmp = tmp->next;
		if (tmp->data == x) {
			return tmp;
		}
	}
	return NULL;
	*/
	//������ʦд�ģ���࣬��ȷ����������޸ĵ����ã����Һ�ֱ��ʹ��ָ��Ȼ��ֱ���޸�data��
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

//��posλ��֮��������ݡ�
void SListInsertAfter(SLTNode* pos, SLTDataType x) {
	//�����ʾ���posָ��Ϊ�գ�Ҳ��Υ���ġ�
	assert(pos);
	SLTNode* NewNode = BuySLTNode(x);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

//��posλ��֮ǰ����һ���ڵ�
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
