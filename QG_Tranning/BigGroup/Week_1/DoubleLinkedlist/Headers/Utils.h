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
void InitDNode();//����������������
void DestroyDNode();//��������������
void InsertHeadList();//����ͷ�巨
void InsertLastList();//����β�巨
void DeleteDNode();//����ɾ�����ݺ���
void SearchDNode();//�����������ݺ���
void ErgodicDNode();//������������
void MenuControl();//�����˵�����