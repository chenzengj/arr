#include "Utils.h"
Node* head = NULL;//ȫ�ֱ��������ڲ���
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
	//head->next=RecurReverseList(head->next);//����ͷ������һ�ڵ㣬����ͷ�������
	//ExchangeNode();
	//ErgodicList();
	system("pause");
	return 0;
}
void InitList() {
	Node* node;
	node = (Node*)malloc(LEN);//�����ڴ�ռ�
	if (node == NULL) {
		printf("����ʧ��\n");
		return;
	}
	node->next = NULL;
	head = node;
	printf("���������ɹ���\n");
	return;
}
void DestroyList() {
	Node* temp;
	if (head == NULL) {
		printf("����Ϊ�գ��������٣�\n");
		return;
	}
	while (head != NULL)
	{
		temp = head;
		head= head->next;
		free(temp);
	}//��������������ڵ㲻���ͷŴӶ���������
	printf("����������ɣ�\n");
}
void InsertList() {
	if (head == NULL) {
		printf("����Ϊ�գ����ȴ�������\n");
		return;
	}
	int num = 0;
	printf("���������ݣ�");
	scanf("%d", &num);//������������
	Node* node = head;
	Node* newNode = (Node*)malloc(LEN);//�����½ڵ��Դ洢�������Ϣ
	if (newNode == NULL) {
		printf("�ڴ����ʧ�ܣ�\n");
		return;
	}
	newNode->data = num;//��������Ϣ����ڵ�
	newNode->next = NULL;
	while (node->next != NULL) {
		node = node->next;//���������һ���ڵ�
	}
	node->next = newNode;//���ڵ��������β��
	printf("���ݲ���ɹ���\n");
	return;
}
void DeleteList() {
	if (head == NULL || head->next == NULL) {
		printf("����Ϊ�գ��޷�ɾ��\n");
		return;
	}
	Node* nextNode = head->next;
	Node* currentNode = head;
	int del = 0;
	printf("������ɾ��������:");
	scanf("%d", &del);
	while (nextNode->data != del) {//����Ѱ������
		currentNode = nextNode;
		nextNode = nextNode->next;
		if (nextNode == NULL) {
			printf("û�и����ݣ�\n");
			return;
		}
	}
	currentNode->next = nextNode->next;//�����и����ݵĽڵ�����
	free(nextNode);//�ͷŸýڵ�
	printf("ɾ���ɹ���\n");
}
void SearchList() {
	if (head == NULL || head->next == NULL) {
		printf("����Ϊ�գ��޷�����\n");
		return;
	}
	int find = 0;
	Node* p = head;
	printf("��������ҵ����ݣ�");
	scanf("%d", &find);
	while (p != NULL) {//����
		if (p->data == find) {//�Ƚ�����
			printf("�ҵ��������ˣ�\n");
			return;//�ҵ��˾Ͳ��ٽ��к�������
		}
		p = p->next;
	}
	printf("δ�ҵ������ݣ�\n");//
}
void ErgodicList() {
	Node* node = head->next;
	if (head == NULL || head->next == NULL) {
		printf("����Ϊ�գ�\n");
		return;
	}
	printf("������������\n");
	while (node != NULL) {
		printf("%d\t", node->data);
		node= node->next;
	}
	printf("\n");
}
void MidNode() {
	if (head == NULL || head->next == NULL) {
		printf("����Ϊ�գ�\n");
		return;
	}
	Node* p = head->next;
	int len = 0;//��¼������
	while (p != NULL) {
		p = p->next;
		len++;
	}
	if (len % 2 == 0) {
		printf("������ڵ����Ϊż�������м�ڵ�\n");
		return;
	}
	Node* fast = head, * slow = head;
	while (fast != NULL && slow != NULL) {
		fast = fast->next->next;//��ָ��ÿ���������ڵ�
		slow = slow->next;//��ָ��ÿ����һ���ڵ�
	}//��ָ���ߵ�β����ָ��պõ��м�
	printf("�������е��ֵΪ%d\n", slow->data);

}
void IsCircleList() {
	Node* fast = head, *slow = head;
	if (head == NULL || head->next == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	while (fast->next!= NULL && slow->next != NULL) {
		slow = slow->next;//��ָ����һ��
		if ((fast = fast->next->next) == NULL) {//��ָ��������
			printf("����û�гɻ�\n");
			return;
		}
		if (fast == slow) {//����ָ��������˵������ɻ�
			printf("����ɻ�\n");
			return;
		}
	}
	printf("����û�гɻ�\n");//�����û��������˵��û�гɻ�
}
void ReverseList() {
	if (head == NULL || head->next == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	Node* newHead,//��¼��ת��ĵ�һ�����λ��
		* p1,
		* p2;
	p1 = head->next;
	p2 = p1->next;
	p1->next = NULL;
	newHead = p1;
	while (p2 != NULL) {
		p1 = p2;
		p2 = p1->next;//��¼��תǰ��һ���ڵ�λ��
		p1->next = newHead;//ʹp1ÿ�ε�ָ�򶼷�ת��ָ��ǰһ���ڵ�
		newHead = p1;//��¼ÿ�η�ת��ĵ�һ���ڵ�
	}
	head->next = newHead;
	printf("��ת�ɹ���\n");
	
}
Node* RecurReverseList(Node* head) {
	if ( head->next == NULL)//�����ݹ麯����base case
		return head;
	Node* last = RecurReverseList(head->next);//last�ڵ����ԭ�ȵ�β�˽ڵ�
	head->next->next = head;//�ı�ڵ�ָ�򣬴�last�ڵ㿪ʼ��ͷ���ָ
	head->next = NULL;//����ת���β�ڵ�ָ���ÿ�
	return last;
}
void ExchangeNode() {
	if (head == NULL || head->next == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	Node* temp = (Node*)malloc(LEN);//��ʱ�洢����
	
	Node* p = head->next;
	//for (Node* fast = head, *slow = head; fast != NULL && slow != NULL; fast = fast->next->next, slow = slow->next) {
		//

	//}
	while (p != NULL&&p->next!=NULL) {//�����ڵ�����
		temp->data = p->data;
		p->data = p->next->data;
		p->next->data = temp->data;
		p = p->next->next;
	}
	printf("�����ɹ�\n");
}
void Jump() {
	head->next= RecurReverseList(head->next);
	printf("��ת�ɹ���\n");
}