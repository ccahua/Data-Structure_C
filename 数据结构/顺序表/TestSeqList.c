#include"SeqList.h"

void TestSqlList() {
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 0);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListDestory(&sl);

}
void TestSqlList2() {
	SL sl;
	SeqListInit(&sl);
 	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);

	SeqListPrint(&sl);

	SeqListDestory(&sl);

}

TestSqlList3() {
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListErase(&sl, 4);
	SeqListPrint(&sl);

	//if (SeqListFind(&sl, 0) > 0) {
	//	printf("该元素在%d个位置\n", SeqListFind(&sl, 0));
	//}
	//else {
	//	printf("该顺序表没有该元素\n");
	//}

	//SeqListInsert(&sl, 3, 6);

	//SeqListPrint(&sl);

	SeqListDestory(&sl);
}
void Menu() {
	printf("*******************************\n");
	printf("请选择你的操作：>\n");
	printf("1、头插  2、尾插\n");
	printf("3、头删  4、尾删\n");
	printf("5、打印  -1、退出\n");
	printf("*******************************\n");
}
//建议不要一上来就写菜单，最好写单元测试
//等你把程序函数接口测试没问题，再写菜单，菜单不方便调试

void MenuTest() {
	int result = 0;
	int x;
	SL sl;
	SeqListInit(&sl);
	while (result != -1) {
		Menu();
		scanf("%d", &result);
		switch (result)
		{
		case 1:
			printf("请输入你要插入的数据，以-1结束:");
			scanf("%d", &x);
			while (x != -1) {
				SeqListPushFront(&sl, x);
				scanf("%d", &x);
			}
			break;
		case 2:
			printf("请输入你要插入的数据，以-1结束:");
			scanf("%d", &x);
			while (x != -1) {
				SeqListPushBack(&sl, x);
				scanf("%d", &x);
			}
			break;
		case 3:
			SeqListPopFront(&sl);
			break;
		case 4:
			SeqListPopBack(&sl);
			break;
		case 5:
			SeqListPrint(&sl);
			break;
		case -1:
			printf("欢迎下次再来！");
			break;
		default:
			printf("无此选项，请重新输入：");
			break;
		}
	}

}
int main() {
	//TestSqlList();
	//TestSqlList2();
	//TestSqlList3();
	MenuTest();
	return 0;
}