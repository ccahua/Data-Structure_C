#include"BinaryTree.h"
#include"stack.h"
#include"queue.h"
# define _CRT_SECURE_NO_WARNINGS

void CreateBTree(BiTree* T) {
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#') {
		*T = NULL;
	}
	else {
		*T = (BTNode*)malloc(sizeof(BTNode));
		(*T)->data = ch;
		CreateBTree(&(*T)->Lchild);
		CreateBTree(&(*T)->Rchild);
	}
}

void FloorOrder(BiTree T) {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, T);
	while (!QueueEmpty(&q)) {
		BTNode* p = QueueFront(&q);
		printf("%c ", p->data);
		QueuePop(&q);
		if (p->Lchild) {
			QueuePush(&q, p->Lchild);
		}
		if (p->Rchild) {
			QueuePush(&q, p->Rchild);
		}
	}
}

void PreTraverseBTree(BiTree p) {
	if (p) {
		//�ȷ��ʸ��ڵ�
		printf("%c ", p->data);
		//���������������
		if (p->Lchild) {
			PreTraverseBTree(p->Lchild);
		}
		//���������������
		if (p->Rchild) {
			PreTraverseBTree(p->Rchild);
		}
	}

}

void InTraverseBTree(BiTree p) {
	if (p) {

		//�������������
		if (p->Lchild) {
			InTraverseBTree(p->Lchild);
		}
		//�ٷ��ʸ��ڵ�
		printf("%c ", p->data);

		//���������������
		if (p->Rchild) {
			InTraverseBTree(p->Rchild);
		}
	}
}


void PostTraverseBTree(BiTree p) {
	if (p) {
		//�Ⱥ������������
		if (p->Lchild) {
			PostTraverseBTree(p->Lchild);
		}
		//�ٺ������������
		if (p->Rchild) {
			PostTraverseBTree(p->Rchild);
		}
		//�����ʸ��ڵ�
		printf("%c ", p->data);
	}
}

//����ǵݹ������������ջʵ�֣�
void Preorder_unrec(BiTree T) {
	ST s;
	StackInit(&s);
	BTNode* p = T;
	BTNode* q = (BTNode*)malloc(sizeof(BTNode));
	while (p || !StackEmpty(&s)) {
		if (p) {
			StackPush(&s, p);
			printf("%c ", p->data);
			p = p->Lchild;
		}
		else {
			q = StackTop(&s);
			StackPop(&s);
			p = q->Rchild;
		}
	}
}

//����ǵݹ����������(ջʵ�֣�
void InOrder_unrec(BiTree T) {
	ST s;
	StackInit(&s);
	BTNode* p = T;
	BTNode* q = (BTNode*)malloc(sizeof(BTNode));
	while (p || !StackEmpty(&s)) {
		if (p) {
			StackPush(&s, p);
			p = p->Lchild;
		}
		else {
			q = StackTop(&s);
			StackPop(&s);
			printf("%c ", q->data);
			p = q->Rchild;
		}
	}
}

//����ǵݹ������������ջʵ�֣�
void Postorder_unrec(BiTree T) {
	ST s;
	StackInit(&s);
	BTNode* p = T,*pre = NULL;
	while (p || !StackEmpty(&s)) {
		if (p) {
			StackPush(&s, p);
			p = p->Lchild;
		}
		else {
			p = StackTop(&s);
			if (p->Rchild && p->Rchild != pre) {
				p = p->Rchild;
			}
			else {
				pre = p;
				printf("%c ", p->data);
				StackPop(&s);
				p = NULL;
			}
		}
	}
}