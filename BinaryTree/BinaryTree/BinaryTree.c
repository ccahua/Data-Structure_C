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
		//先访问根节点
		printf("%c ", p->data);
		//再先序遍历左子树
		if (p->Lchild) {
			PreTraverseBTree(p->Lchild);
		}
		//再先序遍历右子树
		if (p->Rchild) {
			PreTraverseBTree(p->Rchild);
		}
	}

}

void InTraverseBTree(BiTree p) {
	if (p) {

		//先序遍历左子树
		if (p->Lchild) {
			InTraverseBTree(p->Lchild);
		}
		//再访问根节点
		printf("%c ", p->data);

		//再先序遍历右子树
		if (p->Rchild) {
			InTraverseBTree(p->Rchild);
		}
	}
}


void PostTraverseBTree(BiTree p) {
	if (p) {
		//先后序遍历左子树
		if (p->Lchild) {
			PostTraverseBTree(p->Lchild);
		}
		//再后序遍历右子树
		if (p->Rchild) {
			PostTraverseBTree(p->Rchild);
		}
		//最后访问根节点
		printf("%c ", p->data);
	}
}

//先序非递归遍历二叉树（栈实现）
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

//中序非递归遍历二叉树(栈实现）
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

//后序非递归遍历二叉树（栈实现）
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