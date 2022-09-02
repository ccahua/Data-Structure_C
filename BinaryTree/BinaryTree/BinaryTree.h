#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef char BTDataType;

typedef struct BTNode{
	BTDataType data;
	struct BTNode* Lchild;
	struct BTNode* Rchild;
}BTNode,*BiTree;


void CreateBTree(BiTree* T);

void FloorOrder(BiTree T);

void PreTraverseBTree(BiTree p);

void InTraverseBTree(BiTree p);

void PostTraverseBTree(BiTree p);

void Preorder_unrec(BiTree T);

void InOrder_unrec(BiTree T);

void Postorder_unrec(BiTree T);

