#include "LinkStack.h"
int main() {
	int e=0,length=0;
	int a=1;
	LinkStack* s=(LinkStack*)malloc(sizeof(LinkStack));
	while (1) {
		menu();
		scanf("%d", &a);
		/*if (isdigit(a)) {
			printf("����Ƿ�������������\n");
			goto p;
		}*/
		switch (a) {
		case 0:
			printf("�˳�����ɹ�\n");
			return 0;
		case 1:
			if (initLStack(s))
				printf("��ʼ���ɹ�\n");
			else
				printf("��ʼ��ʧ��\n");
			break;
		case 2:
			if (OK==isEmptyLStack(s))
				printf("ջΪ��\n");
			else if (2 == isEmptyLStack(s))
				printf("ջδ��ʼ��\n");
			else
				printf("ջ��Ϊ��\n");
			break;
		case 3:
			if (getTopLStack(s, &e)) {
				printf("ջ��Ԫ��Ϊ%d\n", e);
			}
			else {
				printf("ջΪ�ջ���ջδ��ʼ��\n");
			}
			break;
		case 4:
			if (clearLStack(s))
				printf("������\n");
			else
				printf("ջΪ�ջ���ջδ��ʼ��\n");
			break;
		case 5:
			if (destroyLStack(s))
				printf("ջ���ٳɹ�\n");
			else
				printf("ջδ��ʼ��\n");
			break;
		case 6:
			printf("������Ҫ����ջ�����֣�");
			scanf("%d", &e);
			if (pushLStack(s, e))
				printf("��ջ�ɹ�\n");
			else
				printf("ջδ��ʼ��,��ջʧ��\n");
			break;
		case 7:
			if (popLStack(s, &e)) {
				printf("��ջ�ɹ���ȡ��������Ϊ%d\n", e);
			}
			else
				printf("��ջʧ�ܣ�ջΪ�ջ���ջδ��ʼ��\n");
			break;
		case 8:
			if (LStackLength(s, &length))
				printf("ջ����Ϊ%d\n", length);
			else
				printf("ջΪ�ջ���ջδ��ʼ��\n");
			break;
		default:
			printf("����ָ��Ƿ�������������\n");
			break;
		}
	}
	return 0;
}
Status initLStack(LinkStack* s) {//��ʼ��ջ
	s->top = (LinkStackPtr)malloc(LEN);//Ϊջ��ָ�����ռ䣬��Ϊ
	if (s->top == NULL) {
		return ERROR;
	}
	s->top->next = NULL;
	s->count = 0;
	return OK;
}
Status isEmptyLStack(LinkStack* s) {//�ж�ջ�Ƿ�Ϊ��
	if (s->top == NULL)
		return 2;
	if (s->top->next == NULL) {//���ջ��ָ��ָ��գ���Ϊ��
		return OK;
	}
	return ERROR;
}
Status getTopLStack(LinkStack* s, ElemType* e) {//�õ�ջ��Ԫ��
	if (isEmptyLStack(s)||s->top==NULL) //�ж�ջ��
		return ERROR;
	*e = s->top->data;//ȡ��ջ��Ԫ�أ�����ɾ��
	return OK;
}
Status clearLStack(LinkStack* s) {
	if (isEmptyLStack(s)||s->top==NULL)//�ж�ջ��
		return ERROR;
	//while (s->top != NULL) {
		s->top->next= NULL;//������ݣ����ͷſռ䣬Ҳ����ջ����
	//	s->top = s->top->next;
	//}
	return OK;
}//���ջ
Status destroyLStack(LinkStack* s) {//����ջ
	if (s->top == NULL)//�ж�ջ�Ƿ��ʼ��
		return ERROR;
	LinkStackPtr p;
	while (s->top != NULL) {
		p = s->top;//����ʱ������¼��ǰջ��ָ��
		s->top = s->top->next;
		free(p);//�ͷſռ������ٽڵ�
	}
	//free(s->top);
	s->count = 0;//ջ����Ϊ0
	return OK;
	}
Status LStackLength(LinkStack* s, int* length) {//���ջ����
	if (isEmptyLStack(s)||s->top==NULL)//�ж�ջ��
		return ERROR;
	*length = s->count;
	return OK;
}
Status pushLStack(LinkStack* s, ElemType data) {//��ջ
	LinkStackPtr p = (LinkStackPtr)malloc(LEN);
	if (p == NULL||s->top==NULL)
		return ERROR;
	p->data = data;
	p->next = s->top;//�½ڵ�ֱ�Ӻ��ָ��ǰջ���ڵ�
	s->top = p;
	(s->count)++;
	return OK;
}
Status popLStack(LinkStack* s, ElemType* data) {//��ջ
	if (isEmptyLStack(s)||s->top==NULL)
		return ERROR;
	LinkStackPtr p;
	*data = s->top->data;
	p = s->top;//��ջ���ڵ㸳��p
	s->top = p->next;//��ջ���ڵ�ָ������һλ��ָ����һ�ڵ�
	free(p);
	s->count--;
	return OK;
}
void menu() {
	printf("\n======================================\n");
	printf("\t1.��ʼ��ջ\n");
	printf("\t2.�ж�ջ�Ƿ�Ϊ��\n");
	printf("\t3.�õ�ջ��Ԫ��\n");
	printf("\t4.���ջ\n");
	printf("\t5.����ջ\n");
	printf("\t6.��ջ\n");
	printf("\t7.��ջ\n");
	printf("\t8.���ջ����\n");
	printf("\t0.�˳�����\n");
	printf("\n======================================\n");
	printf("������������еĲ���(0-8)��");

}