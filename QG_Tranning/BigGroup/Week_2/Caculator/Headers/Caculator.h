#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#define STACK_INIT_SIZE 10  //�洢�ռ��ʼ������
#define STACKINCREMENT 5  //�洢�ռ��������
#define LEN 50

typedef char ElemType; //�����ַ���������
typedef double ElemType2;  //������������������

enum{//����ö�ٸ�ֵ 
	ERROR,
	OK
};
//�ַ�ջ
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize; 
}SqStack;

//������ջ
typedef struct{
    ElemType2 *base;
    ElemType2 *top;
    int stacksize;
}NStack;

int InitStack(SqStack *S);   //�����ջ
int push(SqStack *S,ElemType e); //��ջ
int Pop(SqStack *S,ElemType *e);  //��ջ
int StackEmpty(SqStack *s);  //ջ���ж�
void Transform(ElemType *str,ElemType *p);  //��׺���ʽת��׺���ʽ
double Caculate(char *str);  //�����׺���ʽ

