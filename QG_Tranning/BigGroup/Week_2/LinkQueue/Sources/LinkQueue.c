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
			printf("�˳�����ɹ�\n");
			return 0;
		case '1':
			InitLQueue(Q);
				printf("��ʼ���ɹ�\n");
			break;
		case '2':
			if (IsEmptyLQueue(Q))
				printf("����Ϊ��\n");
			else
				printf("���в�Ϊ��\n");
			break;
		case '3':
			if (GetHeadLQueue(Q, &e)) {
				printf("��ͷԪ��Ϊ%d\n", e);
			}
			else {
				printf("����Ϊ�ջ��߶���δ��ʼ��\n");
			}
			break;
		case '4':
			ClearLQueue(Q);
				printf("������\n");
			break;
		case '5':
			DestoryLQueue(Q);
				printf("�������ٳɹ�\n");
			
			break;
		case '6':
		 jump:
			
				c:
				printf("������������");
				scanf("%s", &b);
				for (int i = 0; i < strlen(b); i++) {
					if (!isdigit(b[i])) {
						printf("����Ƿ�������������\n");
						goto c;
					}
				}
				e = (int)atof(b);
				if ((EnLQueue(Q, &e)))
					printf("��ӳɹ�\n");
				else
					printf("����δ��ʼ��,���ʧ��\n");
			
			break;
		case '7':
			if (DeLQueue(Q) ){
				printf("����гɹ�\n");
			}
			else
				printf("�����ʧ�ܣ�����Ϊ�ջ��߶���δ��ʼ��\n");
			break;
		case '8':
			length = LengthLQueue(Q);
				printf("���г���Ϊ%d\n", length);
			break;
		case '9':
			TraverseLQueue(Q,q);
			printf("�������");
			break;
		default:
		d:
			printf("����ָ���������������\n");
			break;
		}
	}
	return 0;
}
void InitLQueue(LQueue* Q) {//��ʼ������
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)
		return;//�ڴ濪��ʧ��
	p->next = NULL;
	Q->front = p;//��ʼ��ʱ��ͷ��βָ��ͬһ��ռ�
	Q->rear = p;
	return;
}
Status IsEmptyLQueue(const LQueue* Q) {//�����п�
	if (Q->front == Q->rear)//ͷβ�ڵ�ͬʱָ��ͬһ���ռ��ʱ�򣬶���Ϊ��
		return TRUE;
	else
		return FALSE;
}
Status EnLQueue(LQueue* Q, void* data) {//���
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)//����ʧ��
		return FALSE;
	p->data = (void*)malloc(Q->length);//����������ռ�������
	//memcpy(p->data, data, Q->length);//��length���ֽڵ�data����ֱ�Ӹ��Ƶ�p->data��
	p->data = data;
	p->next = NULL;
	//if (IsEmptyLQueue(Q)) {//����ͷ������
	//	Q->front = p;
	//	Q->rear = p;
	//}
	Q->rear->next = p;//��β��p����
	Q->rear = p;//��βָ��p
	return TRUE;
}
Status DeLQueue(LQueue* Q) {//����
	if (IsEmptyLQueue(Q))//ִ���пղ���
		return FALSE;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front->next;//ʹpָ���ͷ
	Q->front->next = p->next;//����ԭ�ȵĶ�ͷ
	if (NULL == Q->front->next)//��������ֻ��һ��Ԫ��ʱ
		Q->rear = Q->front;
	free(p);
	return TRUE;
}
Status GetHeadLQueue(LQueue* Q, void* e) {//ȡ����ͷԪ��
	if (IsEmptyLQueue(Q))
		return FALSE;
	e = Q->front->next->data;//��ֵ
	//memcpy(e, Q->front->next->data, Q->length);//��ͷ�����һ���ڵ�ָ���λ�ø����ֽ��� 
	return TRUE;
}
int LengthLQueue(LQueue* Q) {//���г���
	int length;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;//ͷ��㿪ʼ������
	for (length = 0; p != Q->rear; length++)
		p = p->next;
	return length;
}
void ClearLQueue(LQueue* Q) {//��ն���
	if (IsEmptyLQueue(Q))
		return;
	Node* p, * q;
	Q->rear = Q->front;//����βָ���ջ�
	p = Q->front->next;//ָ���ͷ
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
}
void DestoryLQueue(LQueue* Q) {//���ٶ���
	if (IsEmptyLQueue(Q))
		return;
	ClearLQueue(Q);//����ն���
	//free(Q->front);//����ͷ�ڵ�β�ڵ�
	//free(Q->rear);
	Q->front = NULL;
	Q->rear = NULL;
}
 //foo��ʾ����ָ��foo��void(*)()���͵�
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {//��������
	if (IsEmptyLQueue(Q))
		return FALSE;
	Node* p ;
	for (p = Q->front->next; p != NULL; p = p->next) {
		foo(p->data);
	}
	printf("\n");
	return TRUE;
}
void LPrint(LQueue* Q)//��ӡ
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
	printf("\t1.��ʼ������\n");
	printf("\t2.�ж϶����Ƿ�Ϊ��\n");
	printf("\t3.�õ���ͷԪ��\n");
	printf("\t4.��ն���\n");
	printf("\t5.���ٶ���\n");
	printf("\t6.���\n");
	printf("\t7.���\n");
	printf("\t8.�����г���\n");
	printf("\t9.��������\n");
	printf("\t0.�˳�����\n");
	printf("\n======================================\n");
	printf("������������еĲ���(0-9)��");

}