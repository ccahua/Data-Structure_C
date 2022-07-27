#include"SeqList.h"
#define BLOCK_SIZE 20


void SeqListInit(SL* ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SL* ps) {
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListMoreCapacity(SL* ps) {
	//realloc函数的说明
//1.如果p指向的空间之后有足够的空间可以追加，则直接追加，返回的是p原来的起始地址。
//2.如果p指向的空间之后没有足够的空间可以追加，则realloc函数会重新找一个新的内存区域，
// 重新开辟一块40个字节的动态内存空间，并且把原来内存空间的数据拷贝回来，
// 释放旧的内存空间还给操作系统，最后返回新开辟的内存空间的起始地址。
//3.我们需要用一个新的指针变量来接收realloc的返回值。
//4.同时我们要考虑调整内存大小失败的情况，如果开辟失败，我们至少不能让原内存数据失效，
// 我们也要释放原内存数据，并把指针置为空。
//5.开辟成功，也不用担心原来的内存有没有浪费，
// 因为realloc函数会把原来的内存空间拷贝回来，再将其内存释放。
// 注意如果ptr != NULL p = ptr; 这个p指针已经被赋为ptr了
// （就不用考虑原内存空间的指针有没有被置为空指针），所以新空间不再使用时，
// 也要释放内存，并把指针置为空。
	int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
	SLDataType* p = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
	if (p == NULL) {
		printf("realloc fail\n");
		exit(-1);
		//这里不能写return-1,首先return-1在这里是有问题的，因为函数返回值为void
		//如果返回值为int,则还是不对，return-1只是把该函数结束掉了，但是程序还在运行
		//exit(-1)是直接把程序给结束掉。
	}
	ps->a = p;
	ps->capacity = newcapacity;
}


void SeqListPushBack(SL* ps, SLDataType x) {
	////空间不够，扩容
	//if (ps->size == ps->capacity) {
	//	SeqListMoreCapacity(ps);
	//}
	////空间足够
	//ps->a[ps->size] = x;
	//ps->size++;
	SeqListInsert(ps, ps->size, x);
}
void SeqListPopBack(SL* ps) {
	////ps->a[ps->size - 1] = 0;
	///*第一种方法
	//if (ps->size > 0) {
	//	ps->size--;
	//}*/
	////第二种方法
	//assert(ps->size > 0);//如果size<0，程序直接终止。
	//ps->size--;

	SeqListErase(ps, ps->size - 1);
}

void SeqListPushFront(SL* ps, SLDataType x) {
	////空间不够，扩容
	//if (ps->size == ps->capacity) {
	//	SeqListMoreCapacity(ps);
	//}

	//int end = ps->size - 1;
	//while (end >= 0) {
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;

	SeqListInsert(ps, 0, x);

}
//从第一个位置删除
void SeqListPopFront(SL* ps) {
	////暴力方式
	//assert(ps->size > 0);
	//int begin = 1;
	//while (begin < ps->size) {
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}
	//if (ps->size > 0) {
	//	ps->size--;
	//}
	SeqListErase(ps, 0);
}
//查找数据
int SeqListFind(SL* ps, SLDataType x) {
	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) {
			//printf("%d在顺序表的第%d位置\n", x, i);
			return i+1;
		}
	}
	return -1;
}
//任意位置添加数据
void SeqListInsert(SL* ps, int pos, SLDataType x) {
	//暴力方式:当括号里为真时，不出会调用这个函数，当括号里为假时才会调用这个函数。
	assert(pos <= ps->size && pos >= 0);
	if (ps->size == ps->capacity) {
		SeqListMoreCapacity(ps);
	}
	int end = ps->size-1;
	while (end >= pos) {
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos) {

	assert(pos >= 0 && pos < ps->size);
	while (pos < ps->size-1) {
		ps->a[pos] = ps->a[pos + 1];
		pos++;
	}
	ps->size--;
}
