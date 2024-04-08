#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include<string.h>
//�����������ڵ㶨��
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
//ջ����
typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;//ջ��ָ��
} Stack;

//���ж���
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;//����ͷ ����β
    QueueNode* rear;
} Queue;
//�����½ڵ�
Node* createNode(int data);
//����ڵ�
Node* insert(Node* root, int data);
//�ݹ��
//�������
void InorderTraversal(Node* root);
//�������
void PreorderTraversal(Node* root);
//�������
void PostorderTraversal(Node* root);
//�����µ�ջ
Stack* CreateStack();
//��ջ����
void push(Stack* stack, Node* treeNode);
//��ջ����
Node* pop(Stack* stack);
//�鿴ջ��Ԫ�أ�ֻ�鿴����ջ��
Node* peek(Stack* stack);
//���ջ�Ƿ�Ϊ��
int isStackEmpty(Stack* stack);
//�ͷ�ջ�ڴ�
void freeStack(Stack* stack);
//��������ǵݹ�ʵ��
void InorderNonRecursion(Node* root);

//��������ǵݹ�ʵ��
void PreorderNonRecursion(Node* root);
//��������ǵݹ�ʵ��
void PostorderNonRecursion(Node* root);
//�����µĶ���
Queue* createQueue();
//��Ӳ���
void Enqueue(Queue* queue, Node* treeNode);
//���Ӳ���
Node* Getqueue(Queue* queue);
//�������Ƿ�Ϊ��
int isQueueEmpty(Queue* queue);
//�ͷŶ����ڴ�
void freeQueue(Queue* queue);
//�������ʵ��
void Sequence(Node* root);
//�����ڵ�
Node* Search(Node* root, int data);
//�ҵ���С�ڵ�
Node* findMin(Node* root);
// ɾ���ڵ�
Node* DeleteNode(Node* root, int data);
