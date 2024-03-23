#include "Caculator.h"
//字符栈初始化
int InitStack(SqStack *S){
    S->base=(ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!S->base)
        return ERROR;  //分配失败
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//运算数栈初始化
int InitStack_N(NStack *S){
    S->base=(ElemType2 *)malloc(STACK_INIT_SIZE * sizeof(ElemType2));
    if(!S->base)
        return ERROR;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//字符栈入栈
int Push(SqStack *S,ElemType e){
    //判断栈满
    if(S->top - S->base >= S->stacksize){
        S->base = (ElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(ElemType));
        if(NULL == S->base)  //分配失败
            return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize = S->stacksize+STACKINCREMENT;
    }
    *S->top = e;
    S->top++;
    return OK;
}

//运算数栈入栈
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

//字符栈出栈
int Pop(SqStack *S,ElemType *e){
    //判断栈空
    if(S->top == S->base)
        return ERROR;
    S->top--;
    *e=*S->top;
    return OK;
}

//运算数栈出栈
int Pop_N(NStack *S,ElemType2 *e){
    if(S->top == S->base)
        return ERROR;
    S->top--;
    *e=*S->top;
    return OK;
}

//判断栈空
int StackEmpty(SqStack *s){
    if(s->top == s->base)
        return OK;
    return ERROR;
}
//判断输入中缀表达式合法性
int Judge(char* str){
	int i,j=1;
	int k,l=0;//记录括号个数 
	if(str[0]!='-'&&!isdigit(str[0])&&str[0]!='(')//首位情况 
	return ERROR;
	for(i=1;i<strlen(str);i++){
		if(isdigit(str[i])){//判断是否为运算操作数 
			;
		}//判断是否为运算操作符
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
				if(j!=l)//左括号与右括号不匹配 
					return ERROR;
			}
			if(str[i+1]!='-'&&!isdigit(str[i+1])&&str[i+1]!='('){
				return ERROR;
			}
		}
		else if(str[i]==')') {
			int m=0;
			for(k=i-1;k>=0;k--){//判断左边是否有左括号 
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

//str为待转换的中缀表达式字符串,p为转换后的后缀表达式字符串
void Transform(ElemType *str,ElemType *p){  
    //初始化一个空栈
    SqStack s;
    InitStack(&s);
    ElemType e;

    int i;
    int j=0;
    for(i=0 ; i<strlen(str) ; i++)  //遍历中缀表达式
    {
        if('-' == str[i])    //负数情况判断
        {
            //表达式首位是'-',则一定是作为负数符号
            if(0 == i)
                p[j++]=str[i++];
            //'-'前面是'(',则一定是作为负数符号
            else if('(' == str[i-1])
                p[j++]=str[i++];
        }


        //遇到数字和小数点直接输出
        while(isdigit(str[i]) || '.'==str[i])
        {
            p[j++]=str[i++];
            if(!isdigit(str[i]) && '.'!=str[i])
                p[j++]=' ';   //一个数字完整输出后使用空格与其它运算符或数字分隔开,也可作为负数判断条件 
        }

        //遇到左括号直接入栈
        if('('==str[i])
            Push(&s,str[i]);

        //遇到右括号直接出栈，直到左括号出栈(左括号不输出)
        if(')'==str[i])
        {
            while('(' != *(s.top-1))
            {
                Pop(&s,&e);
                p[j++]=e;
                p[j++]=' ';
            }
            Pop(&s,&e);  //左括号出栈但不输出
        }

        //遇到+或—
        //1.栈空/栈顶为左括号:直接入栈
        //2.否则一直出栈,直到栈空/栈顶为左括号,再入栈
        if('+'==str[i] || '-'==str[i])
        {
            while(!StackEmpty(&s) && '('!=*(s.top-1))  //栈非空 且 栈顶非左括号
            {
                Pop(&s,&e);
                p[j++]=e;
                p[j++]=' ';
            }
            Push(&s,str[i]);
        }

        //遇到*或/
        //1.栈空/栈顶为左括号/栈顶操作符为+ 或者 -:直接入栈
        //2.否则一直出栈,直到满足1,再入栈
        if('*'==str[i] || '/'==str[i] || '%'==str[i])
        {//栈非空非左括号非+ - 
            while(!StackEmpty(&s) &&'('!=*(s.top-1) && '+'!=*(s.top-1) && '-'!=*(s.top-1))
            {
                Pop(&s,&e);
                p[j++]=e;
                p[j++]=' ';
            }
            Push(&s,str[i]);
        }
    }
    //中缀表达式遍历完成,还需检查栈中是否有未输出运算符 
    //判断栈空,非空则直接出栈并输出(左括号不用输出)
    while(!StackEmpty(&s)){
        Pop(&s,&e);
        if('('!=e)
        {
            p[j++]=e;
            p[j++]=' ';
        }
    }
    p[--j]='\0';// 后缀表达式最后的终止符 
}

//str为待计算的后缀表达式,返回值为计算结果
double Caculate(char *str){
    ElemType2 e,a,b;
    char d[LEN];//运算数字符串 
    //初始化一个运算数栈保存运算数
    NStack n;
    InitStack_N(&n);
    int i=0;
    int j=0;
    //遇到运算操作符直接岀栈两次，运算数直接入栈 
    while(str[i])  //遍历后缀表达式
    {
        switch(str[i])
        {
            case '-':
                if( isdigit(str[i+1]) )  //判断'-'是作为负数符号or运算符（通过下一位是否为空格判断） 
                {
                    d[j++]=str[i++];  //将负号加入运算数字符串
                    d[j]='\0';
                    break;  
                }
                else//非负号情况 
                {
                    Pop_N(&n,&b);//遇到运算操作符岀栈两次 
                    Pop_N(&n,&a);
                    Push_N(&n,a-b);//结果入栈 
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
            case ' ':i++;//空格直接跳过 
        }//swith结束,接下来判断数字部分 

        //遇到运算数直接入栈(先转换double类型)
        //d保存后缀表达式中的字符串形式的运算数
        //使用atof将字符串转换为double类型
        //使用isdight判断是否为十进制数字 
        while(isdigit(str[i]) || '.'==str[i])
        {
            d[j++]=str[i++];
            d[j]='\0';
            if( ' ' == str[i] )
            {
                e = atof(d);  //此时的e就是完整的运算数
                Push_N(&n,e);
                i++;
                j = 0;//d数组重新开始记录运算数 
            }
        }
    }
    Pop_N(&n,&e);//将最终结果岀栈 
    return e;
}

int main()
{
    char str[LEN];
    char transform[LEN];
    int i;
    printf("\n请输入正确运算表达式(英文输入法)\n");
    gets(str);
    while(str){
    if(Judge(str)==0){
    	printf("表达式输入有误，请重新输入！\n");
    	goto a;
	}
	if(strlen(str)==1){
		if(isdigit(str[0])){
		printf("\n对应后缀表达式为:\n%s",str);
		printf("\n结果为:\n%s",str);
		goto a;
		}
		else{
		printf("表达式输入有误，请重新输入！\n");
		goto b;
		}
	}
    printf("\n对应的后缀表达式为：\n");
    Transform(str,transform);
    printf("%s",transform);
    printf("\n\n结果为\n");
    printf("%f",Caculate(transform));
    a:
    system("pause");
    system("cls");
    b:
	printf("\n请输入正确运算表达式(英文输入法)\n");
    gets(str);}
    return 0;
}
