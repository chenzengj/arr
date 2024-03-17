#include "Utils.h"
Node* head = NULL;//全局变量，便于操作
int main() {
	MenuControl();
	//InitList();
	////DestroyList();
	//InsertList();
	//InsertList();
	////InsertList();
	//InsertList();
	//InsertList();
	
	////DeleteList();
	//ErgodicList();
	//MidNode();
	//IsCircleList();
	//head->next=RecurReverseList(head->next);//返回头结点的下一节点，运用头结点连接
	//ExchangeNode();
	//ErgodicList();
	system("pause");
	return 0;
}
void InitList() {
	Node* node;
	node = (Node*)malloc(LEN);//开辟内存空间
	if (node == NULL) {
		printf("创建失败\n");
		return;
	}
	node->next = NULL;
	head = node;
	printf("空链表创建成功！\n");
	return;
}
void DestroyList() {
	Node* temp;
	if (head == NULL) {
		printf("链表为空，无需销毁！\n");
		return;
	}
	while (head != NULL)
	{
		temp = head;
		head= head->next;
		free(temp);
	}//遍历链表，将链表节点不断释放从而销毁链表
	printf("链表销毁完成！\n");
}
void InsertList() {
	if (head == NULL) {
		printf("链表为空，请先创建链表！\n");
		return;
	}
	int num = 0;
	printf("请输入数据：");
	scanf("%d", &num);//输入插入的数据
	Node* node = head;
	Node* newNode = (Node*)malloc(LEN);//创建新节点以存储插入的信息
	if (newNode == NULL) {
		printf("内存分配失败！\n");
		return;
	}
	newNode->data = num;//将数据信息存入节点
	newNode->next = NULL;
	while (node->next != NULL) {
		node = node->next;//遍历至最后一个节点
	}
	node->next = newNode;//将节点插入链表尾端
	printf("数据插入成功！\n");
	return;
}
void DeleteList() {
	if (head == NULL || head->next == NULL) {
		printf("链表为空，无法删除\n");
		return;
	}
	Node* nextNode = head->next;
	Node* currentNode = head;
	int del = 0;
	printf("请输入删除的数据:");
	scanf("%d", &del);
	while (nextNode->data != del) {//遍历寻找数据
		currentNode = nextNode;
		nextNode = nextNode->next;
		if (nextNode == NULL) {
			printf("没有该数据！\n");
			return;
		}
	}
	currentNode->next = nextNode->next;//将含有该数据的节点跳过
	free(nextNode);//释放该节点
	printf("删除成功！\n");
}
void SearchList() {
	if (head == NULL || head->next == NULL) {
		printf("链表为空，无法查找\n");
		return;
	}
	int find = 0;
	Node* p = head;
	printf("请输入查找的数据：");
	scanf("%d", &find);
	while (p != NULL) {//遍历
		if (p->data == find) {//比较数据
			printf("找到该数据了！\n");
			return;//找到了就不再进行后续代码
		}
		p = p->next;
	}
	printf("未找到该数据！\n");//
}
void ErgodicList() {
	Node* node = head->next;
	if (head == NULL || head->next == NULL) {
		printf("链表为空！\n");
		return;
	}
	printf("链表数据如下\n");
	while (node != NULL) {
		printf("%d\t", node->data);
		node= node->next;
	}
	printf("\n");
}
void MidNode() {
	if (head == NULL || head->next == NULL) {
		printf("链表为空！\n");
		return;
	}
	Node* p = head->next;
	int len = 0;//记录链表长度
	while (p != NULL) {
		p = p->next;
		len++;
	}
	if (len % 2 == 0) {
		printf("该链表节点个数为偶数，无中间节点\n");
		return;
	}
	Node* fast = head, * slow = head;
	while (fast != NULL && slow != NULL) {
		fast = fast->next->next;//快指针每次走两个节点
		slow = slow->next;//慢指针每次走一个节点
	}//快指针走到尾端慢指针刚好到中间
	printf("该链表中点的值为%d\n", slow->data);

}
void IsCircleList() {
	Node* fast = head, *slow = head;
	if (head == NULL || head->next == NULL)
	{
		printf("链表为空\n");
		return;
	}
	while (fast->next!= NULL && slow->next != NULL) {
		slow = slow->next;//慢指针走一步
		if ((fast = fast->next->next) == NULL) {//快指针走两步
			printf("链表没有成环\n");
			return;
		}
		if (fast == slow) {//快慢指针相遇，说明链表成环
			printf("链表成环\n");
			return;
		}
	}
	printf("链表没有成环\n");//走完后没有相遇，说明没有成环
}
void ReverseList() {
	if (head == NULL || head->next == NULL)
	{
		printf("链表为空\n");
		return;
	}
	Node* newHead,//记录反转后的第一个结点位置
		* p1,
		* p2;
	p1 = head->next;
	p2 = p1->next;
	p1->next = NULL;
	newHead = p1;
	while (p2 != NULL) {
		p1 = p2;
		p2 = p1->next;//记录反转前下一个节点位置
		p1->next = newHead;//使p1每次的指向都反转，指向前一个节点
		newHead = p1;//记录每次反转后的第一个节点
	}
	head->next = newHead;
	printf("反转成功！\n");
	
}
Node* RecurReverseList(Node* head) {
	if ( head->next == NULL)//跳出递归函数的base case
		return head;
	Node* last = RecurReverseList(head->next);//last节点接收原先的尾端节点
	head->next->next = head;//改变节点指向，从last节点开始往头结点指
	head->next = NULL;//将反转后的尾节点指向置空
	return last;
}
void ExchangeNode() {
	if (head == NULL || head->next == NULL)
	{
		printf("链表为空\n");
		return;
	}
	Node* temp = (Node*)malloc(LEN);//暂时存储数据
	
	Node* p = head->next;
	//for (Node* fast = head, *slow = head; fast != NULL && slow != NULL; fast = fast->next->next, slow = slow->next) {
		//

	//}
	while (p != NULL&&p->next!=NULL) {//交换节点数据
		temp->data = p->data;
		p->data = p->next->data;
		p->next->data = temp->data;
		p = p->next->next;
	}
	printf("交换成功\n");
}
void Jump() {
	head->next= RecurReverseList(head->next);
	printf("反转成功！\n");
}