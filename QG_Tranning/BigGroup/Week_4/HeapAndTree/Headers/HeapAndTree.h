#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define MAX_SIZE 100

//二叉堆结构体定义
typedef struct BinaryHeap {
    int size;
    int arr[MAX_SIZE];
} BinaryHeap;
//AVL树节点定义
typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;
//节点颜色
enum Color {
    RED,
    BLACK
};

//红黑树节点定义
typedef struct RBNode {
    int data;
    enum Color color;
    struct RBNode* parent;
    struct RBNode* left;
    struct RBNode* right;
} RBNode;
//创建新的堆
BinaryHeap* createHeap();
//交换两个元素
void swap(int* a, int* b);
//上浮操作
void HeapUp(BinaryHeap* heap, int index);
//下沉操作
void HeapDown(BinaryHeap* heap, int index);
//插入元素
void InsertRoot(BinaryHeap* heap, int value);
//删除根节点
int DeleteRoot(BinaryHeap* heap);
//打印堆
void printHeap(BinaryHeap* heap);
//获取节点高度
int getHeight(AVLNode* node);

//获取平衡因子
int getBalanceFactor(AVLNode* node);
//右旋转
AVLNode* AVLrightRotate(AVLNode* y);
//左旋转
AVLNode* AVLleftRotate(AVLNode* x);
//插入节点
AVLNode* insertAVLNode(AVLNode* node, int data);
//查找节点
AVLNode* searchAVLNode(AVLNode* root, int data);
//获取最小值节点
AVLNode* getMinNode(AVLNode* node);
// 删除节点
AVLNode* deleteNode(AVLNode* root, int data);
//中序遍历
void inorderAVLTraversal(AVLNode* root);
//创建新节点
RBNode* createNode(int data);
// 左旋转
void RBleftRotate(RBNode** root, RBNode* x);
// 右旋转
void RBrightRotate(RBNode** root, RBNode* y);
// 插入节点
void insertRBNode(RBNode** root, RBNode* node);

// 插入修复
void insertFixup(RBNode** root, RBNode* node);
// 查找节点
RBNode* searchRBNode(RBNode* root, int data);
// 中序遍历
void inorderRBTraversal(RBNode* root);
