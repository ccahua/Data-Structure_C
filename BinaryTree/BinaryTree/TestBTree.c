#include"stack.h"

void test1() {
	BiTree T = NULL;
	CreateBTree(&T);
	printf("���������\n");
	FloorOrder(T);
	printf("\nǰ��ݹ������\n");
	PreTraverseBTree(T);
	printf("\n����ݹ������\n");
	InTraverseBTree(T);
	printf("\n����ݹ������\n");
	PostTraverseBTree(T);
	printf("\nǰ��ǵݹ������\n");
	Preorder_unrec(T);
	printf("\n����ǵݹ������\n");
	InOrder_unrec(T);
	printf("\n����ǵݹ������\n");
	Postorder_unrec(T);
}

int main() {
	test1();
	return 0;
}