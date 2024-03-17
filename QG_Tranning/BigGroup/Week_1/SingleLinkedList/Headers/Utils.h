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
typedef struct LinkedList {
	int data;//为方便测试，只在节点中存放int类型数据
	struct LinkedList* next;
}Node;
#define LEN sizeof(Node)
void InitList();//声明创建空链表函数
void DestroyList();//声明链表销毁函数
void InsertList();//声明插入函数
void DeleteList();//声明删除结点函数
void SearchList();//声明查找函数
void ErgodicList();//声明遍历函数
void MidNode();//声明查找链表中点函数
void IsCircleList();//声明查找链表成环函数
void ReverseList();//声明链表反转函数（非递归）
Node* RecurReverseList();//声明链表反转函数（递归）
void ExchangeNode();//声明链表奇偶互换函数
void MenuControl();//声明菜单控制函数
void Jump();//