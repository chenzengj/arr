#include "Caculator.h"
//�ַ�ջ��ʼ��
int InitStack(SqStack *S){
    S->base=(ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!S->base)
        return ERROR;  //����ʧ��
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//������ջ��ʼ��
int InitStack_N(NStack *S){
    S->base=(ElemType2 *)malloc(STACK_INIT_SIZE * sizeof(ElemType2));
    if(!S->base)
        return ERROR;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//�ַ�ջ��ջ
int Push(SqStack *S,ElemType e){
    //�ж�ջ��
    if(S->top - S->base >= S->stacksize){
        S->base = (ElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(ElemType));
        if(NULL == S->base)  //����ʧ��
            return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize = S->stacksize+STACKINCREMENT;
    }
    *S->top = e;
    S->top++;
    return OK;
}

//������ջ��ջ
int Push_N(NStack *S,ElemType2 e){
    if(S->top - S->base >= S->stacksize){
        S->base = (ElemType2 *)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(ElemType2));
        if(NULL == S->base)
            return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize = S->stacksize+STACKINCREMENT;
    }
    *S->top = e;
    S->top++;
    return OK;
}

//�ַ�ջ��ջ
int Pop(SqStack *S,ElemType *e){
    //�ж�ջ��
    if(S->top == S->base)
        return ERROR;
    S->top--;
    *e=*S->top;
    return OK;
}

//������ջ��ջ
int Pop_N(NStack *S,ElemType2 *e){
    if(S->top == S->base)
        return ERROR;
    S->top--;
    *e=*S->top;
    return OK;
}

//�ж�ջ��
int StackEmpty(SqStack *s){
    if(s->top == s->base)
        return OK;
    return ERROR;
}
//�ж�������׺���ʽ�Ϸ���
int Judge(char* str){
	int i,j=1;
	int k,l=0;//��¼���Ÿ��� 
	if(str[0]!='-'&&!isdigit(str[0])&&str[0]!='(')//��λ��� 
	return ERROR;
	for(i=1;i<strlen(str);i++){
		if(isdigit(str[i])){//�ж��Ƿ�Ϊ��������� 
			;
		}//�ж��Ƿ�Ϊ���������
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
		
			if(isdigit(str[i-1])&&isdigit(str[i+1]))
			   		;
			else if(str[i-1]=='('){
				if(str[i]!='-')
				return ERROR;
				if(!isdigit(str[i+1]))
				return ERROR;				
			}else if(str[i-1]==')'){
				if(!isdigit(str[i+1])&&str[i+1]!='(')
				return ERROR;
			}
			else if(isdigit(str[i-1])){
				if(str[i+1]!='('&&!isdigit(str[i+1]))
				return ERROR;
			}
			else{
				return ERROR;
			}
		}
		else if(str[i]=='.'){
			if(!isdigit(str[i-1])&&(!isdigit(str[i+1])))
			return ERROR;
		}
		else if(str[i]=='('){
			if(1==j){
				if(str[0]=='(')
				j++;
				for(k=i+1;k<strlen(str);k++){
					if(str[k]=='(')
					j++;
					if(str[k]==')')
					l++;
				}
				if(j!=l)//�������������Ų�ƥ�� 
					return ERROR;
			}
			if(str[i+1]!='-'&&!isdigit(str[i+1])&&str[i+1]!='('){
				return ERROR;
			}
		}
		else if(str[i]==')') {
			int m=0;
			for(k=i-1;k>=0;k--){//�ж�����Ƿ��������� 
				if(str[k]=='(')
				m++;
			}
			if(m==0)
			return ERROR;
			if(str[i+1]!=')'&&str[i]!='+'&&str[i]!='-'&&str[i]!='*'&&str[i]!='/'&&str[i+1]!='\0'){
				return ERROR;
			}
		}
		else{
			return ERROR;
		}
	}
	return OK;
	}

//strΪ��ת������׺���ʽ�ַ���,pΪת����ĺ�׺���ʽ�ַ���
void Transform(ElemType *str,ElemType *p){  
    //��ʼ��һ����ջ
    SqStack s;
    InitStack(&s);
    ElemType e;

    int i;
    int j=0;
    for(i=0 ; i<strlen(str) ; i++)  //������׺���ʽ
    {
        if('-' == str[i])    //��������ж�
        {
            //���ʽ��λ��'-',��һ������Ϊ��������
            if(0 == i)
                p[j++]=str[i++];
            //'-'ǰ����'(',��һ������Ϊ��������
            else if('(' == str[i-1])
                p[j++]=str[i++];
        }


        //�������ֺ�С����ֱ�����
        while(isdigit(str[i]) || '.'==str[i])
        {
            p[j++]=str[i++];
            if(!isdigit(str[i]) && '.'!=str[i])
                p[j++]=' ';   //һ���������������ʹ�ÿո�����������������ַָ���,Ҳ����Ϊ�����ж����� 
        }

        //����������ֱ����ջ
        if('('==str[i])
            Push(&s,str[i]);

        //����������ֱ�ӳ�ջ��ֱ�������ų�ջ(�����Ų����)
        if(')'==str[i])
        {
            while('(' != *(s.top-1))
            {
                Pop(&s,&e);
                p[j++]=e;
                p[j++]=' ';
            }
            Pop(&s,&e);  //�����ų�ջ�������
        }

        //����+��
        //1.ջ��/ջ��Ϊ������:ֱ����ջ
        //2.����һֱ��ջ,ֱ��ջ��/ջ��Ϊ������,����ջ
        if('+'==str[i] || '-'==str[i])
        {
            while(!StackEmpty(&s) && '('!=*(s.top-1))  //ջ�ǿ� �� ջ����������
            {
                Pop(&s,&e);
                p[j++]=e;
                p[j++]=' ';
            }
            Push(&s,str[i]);
        }

        //����*��/
        //1.ջ��/ջ��Ϊ������/ջ��������Ϊ+ ���� -:ֱ����ջ
        //2.����һֱ��ջ,ֱ������1,����ջ
        if('*'==str[i] || '/'==str[i] || '%'==str[i])
        {//ջ�ǿշ������ŷ�+ - 
            while(!StackEmpty(&s) &&'('!=*(s.top-1) && '+'!=*(s.top-1) && '-'!=*(s.top-1))
            {
                Pop(&s,&e);
                p[j++]=e;
                p[j++]=' ';
            }
            Push(&s,str[i]);
        }
    }
    //��׺���ʽ�������,������ջ���Ƿ���δ�������� 
    //�ж�ջ��,�ǿ���ֱ�ӳ�ջ�����(�����Ų������)
    while(!StackEmpty(&s)){
        Pop(&s,&e);
        if('('!=e)
        {
            p[j++]=e;
            p[j++]=' ';
        }
    }
    p[--j]='\0';// ��׺���ʽ������ֹ�� 
}

//strΪ������ĺ�׺���ʽ,����ֵΪ������
double Caculate(char *str){
    ElemType2 e,a,b;
    char d[LEN];//�������ַ��� 
    //��ʼ��һ��������ջ����������
    NStack n;
    InitStack_N(&n);
    int i=0;
    int j=0;
    //�������������ֱ�ӌ�ջ���Σ�������ֱ����ջ 
    while(str[i])  //������׺���ʽ
    {
        switch(str[i])
        {
            case '-':
                if( isdigit(str[i+1]) )  //�ж�'-'����Ϊ��������or�������ͨ����һλ�Ƿ�Ϊ�ո��жϣ� 
                {
                    d[j++]=str[i++];  //�����ż����������ַ���
                    d[j]='\0';
                    break;  
                }
                else//�Ǹ������ 
                {
                    Pop_N(&n,&b);//���������������ջ���� 
                    Pop_N(&n,&a);
                    Push_N(&n,a-b);//�����ջ 
                    i++;
                    break;
                }
            case '+':
                Pop_N(&n,&b);
                Pop_N(&n,&a);
                Push_N(&n,a+b);
                i++;
                break;
            case '*':
                Pop_N(&n,&b);
                Pop_N(&n,&a);
                Push_N(&n,a*b);
                i++;
                break;
            case '/':
                Pop_N(&n,&b);
                Pop_N(&n,&a);
                Push_N(&n,a/b);
                i++;
                break;
            case ' ':i++;//�ո�ֱ������ 
        }//swith����,�������ж����ֲ��� 

        //����������ֱ����ջ(��ת��double����)
        //d�����׺���ʽ�е��ַ�����ʽ��������
        //ʹ��atof���ַ���ת��Ϊdouble����
        //ʹ��isdight�ж��Ƿ�Ϊʮ�������� 
        while(isdigit(str[i]) || '.'==str[i])
        {
            d[j++]=str[i++];
            d[j]='\0';
            if( ' ' == str[i] )
            {
                e = atof(d);  //��ʱ��e����������������
                Push_N(&n,e);
                i++;
                j = 0;//d�������¿�ʼ��¼������ 
            }
        }
    }
    Pop_N(&n,&e);//�����ս����ջ 
    return e;
}

int main()
{
    char str[LEN];
    char transform[LEN];
    int i;
    printf("\n��������ȷ������ʽ(Ӣ�����뷨)\n");
    gets(str);
    while(str){
    if(Judge(str)==0){
    	printf("���ʽ�����������������룡\n");
    	goto a;
	}
	if(strlen(str)==1){
		if(isdigit(str[0])){
		printf("\n��Ӧ��׺���ʽΪ:\n%s",str);
		printf("\n���Ϊ:\n%s",str);
		goto a;
		}
		else{
		printf("���ʽ�����������������룡\n");
		goto b;
		}
	}
    printf("\n��Ӧ�ĺ�׺���ʽΪ��\n");
    Transform(str,transform);
    printf("%s",transform);
    printf("\n\n���Ϊ\n");
    printf("%f",Caculate(transform));
    a:
    system("pause");
    system("cls");
    b:
	printf("\n��������ȷ������ʽ(Ӣ�����뷨)\n");
    gets(str);}
    return 0;
}
