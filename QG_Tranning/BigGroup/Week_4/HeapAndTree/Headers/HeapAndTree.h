#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define MAX_SIZE 100

//����ѽṹ�嶨��
typedef struct BinaryHeap {
    int size;
    int arr[MAX_SIZE];
} BinaryHeap;
//AVL���ڵ㶨��
typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;
//�ڵ���ɫ
enum Color {
    RED,
    BLACK
};

//������ڵ㶨��
typedef struct RBNode {
    int data;
    enum Color color;
    struct RBNode* parent;
    struct RBNode* left;
    struct RBNode* right;
} RBNode;
//�����µĶ�
BinaryHeap* createHeap();
//��������Ԫ��
void swap(int* a, int* b);
//�ϸ�����
void HeapUp(BinaryHeap* heap, int index);
//�³�����
void HeapDown(BinaryHeap* heap, int index);
//����Ԫ��
void InsertRoot(BinaryHeap* heap, int value);
//ɾ�����ڵ�
int DeleteRoot(BinaryHeap* heap);
//��ӡ��
void printHeap(BinaryHeap* heap);
//��ȡ�ڵ�߶�
int getHeight(AVLNode* node);

//��ȡƽ������
int getBalanceFactor(AVLNode* node);
//����ת
AVLNode* AVLrightRotate(AVLNode* y);
//����ת
AVLNode* AVLleftRotate(AVLNode* x);
//����ڵ�
AVLNode* insertAVLNode(AVLNode* node, int data);
//���ҽڵ�
AVLNode* searchAVLNode(AVLNode* root, int data);
//��ȡ��Сֵ�ڵ�
AVLNode* getMinNode(AVLNode* node);
// ɾ���ڵ�
AVLNode* deleteNode(AVLNode* root, int data);
//�������
void inorderAVLTraversal(AVLNode* root);
//�����½ڵ�
RBNode* createNode(int data);
// ����ת
void RBleftRotate(RBNode** root, RBNode* x);
// ����ת
void RBrightRotate(RBNode** root, RBNode* y);
// ����ڵ�
void insertRBNode(RBNode** root, RBNode* node);

// �����޸�
void insertFixup(RBNode** root, RBNode* node);
// ���ҽڵ�
RBNode* searchRBNode(RBNode* root, int data);
// �������
void inorderRBTraversal(RBNode* root);
