#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include<string.h>
//二叉排序树节点定义
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
//栈定义
typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;//栈顶指针
} Stack;

//队列定义
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;//队列头 队列尾
    QueueNode* rear;
} Queue;
//创建新节点
Node* createNode(int data);
//插入节点
Node* insert(Node* root, int data);
//递归版
//中序遍历
void InorderTraversal(Node* root);
//先序遍历
void PreorderTraversal(Node* root);
//后序遍历
void PostorderTraversal(Node* root);
//创建新的栈
Stack* CreateStack();
//入栈操作
void push(Stack* stack, Node* treeNode);
//出栈操作
Node* pop(Stack* stack);
//查看栈顶元素（只查看不出栈）
Node* peek(Stack* stack);
//检查栈是否为空
int isStackEmpty(Stack* stack);
//释放栈内存
void freeStack(Stack* stack);
//中序遍历非递归实现
void InorderNonRecursion(Node* root);

//先序遍历非递归实现
void PreorderNonRecursion(Node* root);
//后序遍历非递归实现
void PostorderNonRecursion(Node* root);
//创建新的队列
Queue* createQueue();
//入队操作
void Enqueue(Queue* queue, Node* treeNode);
//出队操作
Node* Getqueue(Queue* queue);
//检查队列是否为空
int isQueueEmpty(Queue* queue);
//释放队列内存
void freeQueue(Queue* queue);
//层序遍历实现
void Sequence(Node* root);
//搜索节点
Node* Search(Node* root, int data);
//找到最小节点
Node* findMin(Node* root);
// 删除节点
Node* DeleteNode(Node* root, int data);
