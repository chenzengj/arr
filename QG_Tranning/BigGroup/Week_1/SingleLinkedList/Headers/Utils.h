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
	int data;//Ϊ������ԣ�ֻ�ڽڵ��д��int��������
	struct LinkedList* next;
}Node;
#define LEN sizeof(Node)
void InitList();//����������������
void DestroyList();//�����������ٺ���
void InsertList();//�������뺯��
void DeleteList();//����ɾ����㺯��
void SearchList();//�������Һ���
void ErgodicList();//������������
void MidNode();//�������������е㺯��
void IsCircleList();//������������ɻ�����
void ReverseList();//��������ת�������ǵݹ飩
Node* RecurReverseList();//��������ת�������ݹ飩
void ExchangeNode();//����������ż��������
void MenuControl();//�����˵����ƺ���
void Jump();//