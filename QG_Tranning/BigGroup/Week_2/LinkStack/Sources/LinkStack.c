#include "LinkStack.h"
int main() {
	int e=0,length=0;
	int a=1;
	LinkStack* s=(LinkStack*)malloc(sizeof(LinkStack));
	while (1) {
		menu();
		scanf("%d", &a);
		/*if (isdigit(a)) {
			printf("输入非法，请重新输入\n");
			goto p;
		}*/
		switch (a) {
		case 0:
			printf("退出程序成功\n");
			return 0;
		case 1:
			if (initLStack(s))
				printf("初始化成功\n");
			else
				printf("初始化失败\n");
			break;
		case 2:
			if (OK==isEmptyLStack(s))
				printf("栈为空\n");
			else if (2 == isEmptyLStack(s))
				printf("栈未初始化\n");
			else
				printf("栈不为空\n");
			break;
		case 3:
			if (getTopLStack(s, &e)) {
				printf("栈顶元素为%d\n", e);
			}
			else {
				printf("栈为空或者栈未初始化\n");
			}
			break;
		case 4:
			if (clearLStack(s))
				printf("清空完毕\n");
			else
				printf("栈为空或者栈未初始化\n");
			break;
		case 5:
			if (destroyLStack(s))
				printf("栈销毁成功\n");
			else
				printf("栈未初始化\n");
			break;
		case 6:
			printf("请输入要存入栈的数字：");
			scanf("%d", &e);
			if (pushLStack(s, e))
				printf("入栈成功\n");
			else
				printf("栈未初始化,入栈失败\n");
			break;
		case 7:
			if (popLStack(s, &e)) {
				printf("岀栈成功，取出的数据为%d\n", e);
			}
			else
				printf("岀栈失败，栈为空或者栈未初始化\n");
			break;
		case 8:
			if (LStackLength(s, &length))
				printf("栈长度为%d\n", length);
			else
				printf("栈为空或者栈未初始化\n");
			break;
		default:
			printf("输入指令非法，请重新输入\n");
			break;
		}
	}
	return 0;
}
Status initLStack(LinkStack* s) {//初始化栈
	s->top = (LinkStackPtr)malloc(LEN);//为栈顶指针分配空间，作为
	if (s->top == NULL) {
		return ERROR;
	}
	s->top->next = NULL;
	s->count = 0;
	return OK;
}
Status isEmptyLStack(LinkStack* s) {//判断栈是否为空
	if (s->top == NULL)
		return 2;
	if (s->top->next == NULL) {//如果栈顶指针指向空，则为空
		return OK;
	}
	return ERROR;
}
Status getTopLStack(LinkStack* s, ElemType* e) {//得到栈顶元素
	if (isEmptyLStack(s)||s->top==NULL) //判断栈空
		return ERROR;
	*e = s->top->data;//取出栈顶元素，无需删除
	return OK;
}
Status clearLStack(LinkStack* s) {
	if (isEmptyLStack(s)||s->top==NULL)//判断栈空
		return ERROR;
	//while (s->top != NULL) {
		s->top->next= NULL;//清空数据，不释放空间，也不把栈销毁
	//	s->top = s->top->next;
	//}
	return OK;
}//清空栈
Status destroyLStack(LinkStack* s) {//销毁栈
	if (s->top == NULL)//判断栈是否初始化
		return ERROR;
	LinkStackPtr p;
	while (s->top != NULL) {
		p = s->top;//用临时变量记录当前栈顶指针
		s->top = s->top->next;
		free(p);//释放空间以销毁节点
	}
	//free(s->top);
	s->count = 0;//栈长度为0
	return OK;
	}
Status LStackLength(LinkStack* s, int* length) {//检测栈长度
	if (isEmptyLStack(s)||s->top==NULL)//判断栈空
		return ERROR;
	*length = s->count;
	return OK;
}
Status pushLStack(LinkStack* s, ElemType data) {//入栈
	LinkStackPtr p = (LinkStackPtr)malloc(LEN);
	if (p == NULL||s->top==NULL)
		return ERROR;
	p->data = data;
	p->next = s->top;//新节点直接后继指向当前栈顶节点
	s->top = p;
	(s->count)++;
	return OK;
}
Status popLStack(LinkStack* s, ElemType* data) {//出栈
	if (isEmptyLStack(s)||s->top==NULL)
		return ERROR;
	LinkStackPtr p;
	*data = s->top->data;
	p = s->top;//把栈顶节点赋给p
	s->top = p->next;//将栈顶节点指针下移一位，指向下一节点
	free(p);
	s->count--;
	return OK;
}
void menu() {
	printf("\n======================================\n");
	printf("\t1.初始化栈\n");
	printf("\t2.判断栈是否为空\n");
	printf("\t3.得到栈顶元素\n");
	printf("\t4.清空栈\n");
	printf("\t5.销毁栈\n");
	printf("\t6.入栈\n");
	printf("\t7.岀栈\n");
	printf("\t8.检测栈长度\n");
	printf("\t0.退出程序\n");
	printf("\n======================================\n");
	printf("请输入你想进行的操作(0-8)：");

}