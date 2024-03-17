#include "Utils.h"
DNode* head = NULL;
int main() {
	MenuControl();
	return 0;
}
void InitDNode() {
	DNode* node;
	node = (DNode*)malloc(LEN);//开辟空间
	if (node == NULL) {
		printf("内存分配失败\n");
		return;
	}
	node->next = NULL;
	node->prior = NULL;
	//head = node;//设立头结点
	head = node;
	printf("创建空链表成功！\n");
}
void DestroyDNode() {
	if (head == NULL || head->next == NULL) {
		printf("链表为空，无需销毁！\n");
		return;
	}
	DNode* temp;//记录当前节点
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);//释放当前节点，起到销毁的作用
	}
	printf("销毁成功！\n");
}
void InsertHeadList() {
	if (head == NULL) {
		printf("链表未创建，请先创建链表！\n");
		return;
	}
	DNode* newNode = (DNode*)malloc(LEN);
	printf("请输入数据：");
	scanf("%d", &newNode->data);
	if (head->next ==NULL) {
		head->next = newNode;
		newNode->prior = head;//双链表有两个方向，需要指回去
		newNode->next = NULL;
	}
	else {
		DNode* temp;
		temp = head->next;
		head->next = newNode;
		newNode->next = temp;//头插法插入数据，从头结点后插入
		temp->prior = newNode;
		newNode->prior = head;//往回指
	}
	printf("数据插入成功！\n");
}
void InsertLastList() {
	if (head == NULL) {
		printf("链表未创建，请先创建链表！\n");
		return;
	}
	DNode* newNode = (DNode*)malloc(LEN);
	DNode* node = head;
	printf("请输入数据：");
	scanf("%d", &newNode->data);
	while(node->next != NULL) {//尾插法，故先遍历至链表尾端
		node = node->next;
	}
	node->next = newNode;//直接插入
	newNode->prior = node;//往回指向原先尾节点
	newNode->next = NULL;
	printf("数据插入成功！\n");
}
void DeleteDNode() {
	if (head == NULL || head->next == NULL) {
		printf("链表为空，无需删除；\n");
		return;
	}
	int num = 0;
	printf("请输入你想删除的数据：");
	scanf("%d", &num);
	DNode* current = head, * node = head->next;
	//寻找删除节点的位置
	while (node->data != num) {
		current = node;
		node = node->next;
		if (node == NULL) {
			printf("未找到该数据!\n");
			return;
		}
	}
	if (node->next == NULL)//数据在尾节点，直接把尾节点置空
		current->next = NULL;
	else {
		current->next = node->next;//跳过即将删除的节点
		node->next->prior = current;
	}
	free(node);
	printf("删除成功!\n");
}
void SearchDNode() {
	if (head == NULL || head->next == NULL) {
		printf("链表为空，无法查找；\n");
		return;
	}
	int num = 0;
	printf("请输入你想查找的数据：");
	scanf("%d", &num);
	DNode* node = head->next;
	while (node != NULL) {//遍历链表，寻找该数据
		if (node->data == num) {
			printf("找到该数据了！\n");
			return;//找到了直接返回
		}
		node = node->next;
	}
	printf("找不到该数据！\n");
}
void ErgodicDNode() {
	if (head == NULL || head->next == NULL) {
		printf("链表为空,请先创建链表；\n");
		return;
	}
	DNode* current = head->next;
	printf("链表数据如下\n");
	while (current != NULL) {
		printf("%d\t", current->data);//打印链表中的数据
		current = current->next;
	}
	printf("\n");
	return;
}