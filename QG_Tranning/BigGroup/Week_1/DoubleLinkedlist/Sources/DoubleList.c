#include "Utils.h"
DNode* head = NULL;
int main() {
	MenuControl();
	return 0;
}
void InitDNode() {
	DNode* node;
	node = (DNode*)malloc(LEN);//���ٿռ�
	if (node == NULL) {
		printf("�ڴ����ʧ��\n");
		return;
	}
	node->next = NULL;
	node->prior = NULL;
	//head = node;//����ͷ���
	head = node;
	printf("����������ɹ���\n");
}
void DestroyDNode() {
	if (head == NULL || head->next == NULL) {
		printf("����Ϊ�գ��������٣�\n");
		return;
	}
	DNode* temp;//��¼��ǰ�ڵ�
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);//�ͷŵ�ǰ�ڵ㣬�����ٵ�����
	}
	printf("���ٳɹ���\n");
}
void InsertHeadList() {
	if (head == NULL) {
		printf("����δ���������ȴ�������\n");
		return;
	}
	DNode* newNode = (DNode*)malloc(LEN);
	printf("���������ݣ�");
	scanf("%d", &newNode->data);
	if (head->next ==NULL) {
		head->next = newNode;
		newNode->prior = head;//˫����������������Ҫָ��ȥ
		newNode->next = NULL;
	}
	else {
		DNode* temp;
		temp = head->next;
		head->next = newNode;
		newNode->next = temp;//ͷ�巨�������ݣ���ͷ�������
		temp->prior = newNode;
		newNode->prior = head;//����ָ
	}
	printf("���ݲ���ɹ���\n");
}
void InsertLastList() {
	if (head == NULL) {
		printf("����δ���������ȴ�������\n");
		return;
	}
	DNode* newNode = (DNode*)malloc(LEN);
	DNode* node = head;
	printf("���������ݣ�");
	scanf("%d", &newNode->data);
	while(node->next != NULL) {//β�巨�����ȱ���������β��
		node = node->next;
	}
	node->next = newNode;//ֱ�Ӳ���
	newNode->prior = node;//����ָ��ԭ��β�ڵ�
	newNode->next = NULL;
	printf("���ݲ���ɹ���\n");
}
void DeleteDNode() {
	if (head == NULL || head->next == NULL) {
		printf("����Ϊ�գ�����ɾ����\n");
		return;
	}
	int num = 0;
	printf("����������ɾ�������ݣ�");
	scanf("%d", &num);
	DNode* current = head, * node = head->next;
	//Ѱ��ɾ���ڵ��λ��
	while (node->data != num) {
		current = node;
		node = node->next;
		if (node == NULL) {
			printf("δ�ҵ�������!\n");
			return;
		}
	}
	if (node->next == NULL)//������β�ڵ㣬ֱ�Ӱ�β�ڵ��ÿ�
		current->next = NULL;
	else {
		current->next = node->next;//��������ɾ���Ľڵ�
		node->next->prior = current;
	}
	free(node);
	printf("ɾ���ɹ�!\n");
}
void SearchDNode() {
	if (head == NULL || head->next == NULL) {
		printf("����Ϊ�գ��޷����ң�\n");
		return;
	}
	int num = 0;
	printf("������������ҵ����ݣ�");
	scanf("%d", &num);
	DNode* node = head->next;
	while (node != NULL) {//��������Ѱ�Ҹ�����
		if (node->data == num) {
			printf("�ҵ��������ˣ�\n");
			return;//�ҵ���ֱ�ӷ���
		}
		node = node->next;
	}
	printf("�Ҳ��������ݣ�\n");
}
void ErgodicDNode() {
	if (head == NULL || head->next == NULL) {
		printf("����Ϊ��,���ȴ�������\n");
		return;
	}
	DNode* current = head->next;
	printf("������������\n");
	while (current != NULL) {
		printf("%d\t", current->data);//��ӡ�����е�����
		current = current->next;
	}
	printf("\n");
	return;
}