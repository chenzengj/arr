#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#define STACK_INIT_SIZE 10  //存储空间初始分配量
#define STACKINCREMENT 5  //存储空间分配增量
#define LEN 50

typedef char ElemType; //定义字符数据类型
typedef double ElemType2;  //定义运算数数据类型

enum{//利用枚举赋值 
	ERROR,
	OK
};
//字符栈
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize; 
}SqStack;

//运算数栈
typedef struct{
    ElemType2 *base;
    ElemType2 *top;
    int stacksize;
}NStack;

int InitStack(SqStack *S);   //构造空栈
int push(SqStack *S,ElemType e); //入栈
int Pop(SqStack *S,ElemType *e);  //出栈
int StackEmpty(SqStack *s);  //栈空判断
void Transform(ElemType *str,ElemType *p);  //中缀表达式转后缀表达式
double Caculate(char *str);  //计算后缀表达式

