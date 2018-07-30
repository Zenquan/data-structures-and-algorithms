#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INIT_SIZE 20
#define INCREMENT_SIZE 5

typedef int SElemtype;
typedef int Status;

/*
 * 存储结构
 */
 typedef struct
 {
 	SElemtype *base;
 	SElemtype *top;
 	int size;
 }SqStack;
 
/*
 * 初始化栈
 */
 
Status InitStack(SqStack *S)
{
	S->base = (SElemtype*)malloc(INIT_SIZE*sizeof(SElemtype));
	if(!S->base)
	{
		exit(OVERFLOW);
	} 
	S->top = S->base;
	S->size = INIT_SIZE;
	return OK;
}

/*
 * 销毁栈
 */
Status destroyStack(SqStack *S)
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->size = 0;
	return OK; 
}
/*
 * 清空栈
 */
 
Status ClearStack(SqStack *S)
{
	S->top = S->base;
	return OK;
 } 
 
/*
 * 判断栈是否为空
 */
 
Status isEmpty(SqStack S)
{
	if(S.top==S.base)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
/*
 * 获取栈的长度
 */
Status getLength(SqStack S)
{
	return S.top - S.base;
}

/*
 * 获取栈顶元素
 */
 
Status getTop(SqStack S, SElemtype *e)
{
	
	if(S.top>S.base)
	{
		*e = *(--S.top);
		return OK;
	}
	else 
	{
		return ERROR;
	}
}

/*
 * 压栈
 */
Status Push(SqStack *S, SElemtype e)
{
	if((S->top-S->base)/sizeof(SElemtype)>=S->size)
	{
		S->base = (SElemtype*)realloc(S->base, (S->size + INCREMENT_SIZE)*sizeof(SElemtype));
		if(!S->base)
		{
			exit(OVERFLOW);
			S->top = S->base + S->size;
			S->size += INCREMENT_SIZE;
		}
		*S->top = e;
		S->top++;
		return OK;
	}
}


/*
 * 退栈
 */
 
Status Pop(SqStack *S, SElemtype *e)
{
	if(S->top == S->base)
	{
		return ERROR;
	}
	S->top--;
	*e = *S->top;
	return OK;
}
/*
 * 访问元素
 */
void visit(SElemtype e)
{
	printf("%d ", e);
}

/*
 * 遍历栈
 */
 
Status TraverseStack(SqStack S, void (*visit)(SElemtype))
{
	while(S.top>S.base)
	{
		visit(*S.base);
		S.base++;
	}
	return OK;
}

int main()
{
	SqStack S;
	if (InitStack(&S))
	{
		SElemtype e;
		int i;
		
		printf("init_success\n");
		
		if (isEmpty(S))
		{
			printf("Stack is empty\n");
		}
		
		for (i = 0; i < 10; i++)
		{
			Push(&S, i);
		}
		
		getTop(S, &e);
		printf("The first element is %d\n", e);
		
		printf("length is %d\n", getLength(S));
		
		Pop(&S, &e);
		printf("Pop element is %d\n", e);
	
		TraverseStack(S, *visit);
	
		if (destroyStack(&S))
		{
			printf("\ndestroy_success\n");
		}
	}
}
 

