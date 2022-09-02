#include"stack.h"

void test1() {
	BiTree T = NULL;
	CreateBTree(&T);
	printf("层序遍历：\n");
	FloorOrder(T);
	printf("\n前序递归遍历：\n");
	PreTraverseBTree(T);
	printf("\n中序递归遍历：\n");
	InTraverseBTree(T);
	printf("\n后序递归遍历：\n");
	PostTraverseBTree(T);
	printf("\n前序非递归遍历：\n");
	Preorder_unrec(T);
	printf("\n中序非递归遍历：\n");
	InOrder_unrec(T);
	printf("\n后序非递归遍历：\n");
	Postorder_unrec(T);
}

int main() {
	test1();
	return 0;
}