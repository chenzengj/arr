#include "LinkQueue.h"
int main() {
	menu();
	int e = 0;
	Node* q=NULL;
	int	length = 0;
	char a[1], b[] = "",str[]="";
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	while (1) {
		scanf("%s", &a);
		if (strlen(a) > 1)
			goto d;
		switch (a[0]) {
		case '0':
			printf("退出程序成功\n");
			return 0;
		case '1':
			InitLQueue(Q);
				printf("初始化成功\n");
			break;
		case '2':
			if (IsEmptyLQueue(Q))
				printf("队列为空\n");
			else
				printf("队列不为空\n");
			break;
		case '3':
			if (GetHeadLQueue(Q, &e)) {
				printf("队头元素为%d\n", e);
			}
			else {
				printf("队列为空或者队列未初始化\n");
			}
			break;
		case '4':
			ClearLQueue(Q);
				printf("清空完毕\n");
			break;
		case '5':
			DestoryLQueue(Q);
				printf("队列销毁成功\n");
			
			break;
		case '6':
		 jump:
			
				c:
				printf("请输入整数：");
				scanf("%s", &b);
				for (int i = 0; i < strlen(b); i++) {
					if (!isdigit(b[i])) {
						printf("输入非法，请重新输入\n");
						goto c;
					}
				}
				e = (int)atof(b);
				if ((EnLQueue(Q, &e)))
					printf("入队成功\n");
				else
					printf("队列未初始化,入队失败\n");
			
			break;
		case '7':
			if (DeLQueue(Q) ){
				printf("岀队列成功\n");
			}
			else
				printf("岀队列失败，队列为空或者队列未初始化\n");
			break;
		case '8':
			length = LengthLQueue(Q);
				printf("队列长度为%d\n", length);
			break;
		case '9':
			TraverseLQueue(Q,q);
			printf("遍历完成");
			break;
		default:
		d:
			printf("输入指令错误，请重新输入\n");
			break;
		}
	}
	return 0;
}
void InitLQueue(LQueue* Q) {//初始化队列
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)
		return;//内存开辟失败
	p->next = NULL;
	Q->front = p;//初始化时队头队尾指向同一块空间
	Q->rear = p;
	return;
}
Status IsEmptyLQueue(const LQueue* Q) {//队列判空
	if (Q->front == Q->rear)//头尾节点同时指向同一个空间的时候，队列为空
		return TRUE;
	else
		return FALSE;
}
Status EnLQueue(LQueue* Q, void* data) {//入队
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)//开辟失败
		return FALSE;
	p->data = (void*)malloc(Q->length);//开辟数据域空间存放数据
	//memcpy(p->data, data, Q->length);//将length个字节的data内容直接复制到p->data中
	p->data = data;
	p->next = NULL;
	//if (IsEmptyLQueue(Q)) {//不含头结点情况
	//	Q->front = p;
	//	Q->rear = p;
	//}
	Q->rear->next = p;//队尾与p连接
	Q->rear = p;//队尾指向p
	return TRUE;
}
Status DeLQueue(LQueue* Q) {//出队
	if (IsEmptyLQueue(Q))//执行判空操作
		return FALSE;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front->next;//使p指向队头
	Q->front->next = p->next;//跳过原先的队头
	if (NULL == Q->front->next)//当队列中只有一个元素时
		Q->rear = Q->front;
	free(p);
	return TRUE;
}
Status GetHeadLQueue(LQueue* Q, void* e) {//取得列头元素
	if (IsEmptyLQueue(Q))
		return FALSE;
	e = Q->front->next->data;//赋值
	//memcpy(e, Q->front->next->data, Q->length);//在头结点下一个节点指向的位置赋予字节数 
	return TRUE;
}
int LengthLQueue(LQueue* Q) {//队列长度
	int length;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;//头结点开始向后遍历
	for (length = 0; p != Q->rear; length++)
		p = p->next;
	return length;
}
void ClearLQueue(LQueue* Q) {//清空队列
	if (IsEmptyLQueue(Q))
		return;
	Node* p, * q;
	Q->rear = Q->front;//将队尾指针收回
	p = Q->front->next;//指向队头
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
}
void DestoryLQueue(LQueue* Q) {//销毁队列
	if (IsEmptyLQueue(Q))
		return;
	ClearLQueue(Q);//先清空队列
	//free(Q->front);//销毁头节点尾节点
	//free(Q->rear);
	Q->front = NULL;
	Q->rear = NULL;
}
 //foo表示函数指针foo是void(*)()类型的
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {//遍历队列
	if (IsEmptyLQueue(Q))
		return FALSE;
	Node* p ;
	for (p = Q->front->next; p != NULL; p = p->next) {
		foo(p->data);
	}
	printf("\n");
	return TRUE;
}
void LPrint(LQueue* Q)//打印
{
	/*Node* p = Q->front->next;
	while (p != NULL) {
		if (1 == sizeof((void*)(p->data))) {
			printf("%c", *((char*)p->data));
		}
		else if (4 == sizeof(p->data)) {
			printf("%d",* ((int*)(p->data)));
		}
		else
			printf("%lf", *((double*)(p->data)));
	}*/
}
void menu() {
	printf("\n======================================\n");
	printf("\t1.初始化队列\n");
	printf("\t2.判断队列是否为空\n");
	printf("\t3.得到队头元素\n");
	printf("\t4.清空队列\n");
	printf("\t5.销毁队列\n");
	printf("\t6.入队\n");
	printf("\t7.岀队\n");
	printf("\t8.检测队列长度\n");
	printf("\t9.遍历队列\n");
	printf("\t0.退出程序\n");
	printf("\n======================================\n");
	printf("请输入你想进行的操作(0-9)：");

}