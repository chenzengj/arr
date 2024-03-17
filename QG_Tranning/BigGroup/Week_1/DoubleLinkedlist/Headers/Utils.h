#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#define upkey 72
#define downkey 80
#define leftkey 75
#define rightkey 77
typedef struct DoubleNode{
	int data;
	struct DoubleNode* next;
	struct DoubleNode* prior;
}DNode;
#define LEN sizeof(DNode)
void InitDNode();//声明创建空链表函数
void DestroyDNode();//声明销毁链表函数
void InsertHeadList();//声明头插法
void InsertLastList();//声明尾插法
void DeleteDNode();//声明删除数据函数
void SearchDNode();//声明查找数据函数
void ErgodicDNode();//声明遍历函数
void MenuControl();//声明菜单函数