#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10 //��ʼ������ 
#define INCREMENT_SIZE 5 //�������� 

typedef int Status;
typedef int Elemtype;

/*
* �洢�ṹ 
*/ 
typedef struct
{
	Elemtype *elem; //�洢�ռ��ַ
	int length; //��ǰ���� 
	int size; //��ǰ����ı�����С 
}SqList;

/*
* ��ʼ��һ���յ����Ա� 
*/
Status InitList(SqList *L)
{
	 L->elem = (Elemtype *)malloc(INIT_SIZE*sizeof(SqList));
	 if(!L->elem)
	 {
	 	return ERROR;
	  } 
	  L->length = 0;
	  L->size = INIT_SIZE;
	  return OK; 
}
/*
* ����һ�����Ա� 
*/
Status destoryList(SqList *L)
{
	free(L->elem);
	L->length = 0;
	L->size = 0;
	return OK;
}
/*
 * ������Ա�
 */
Status clearList(SqList *L)
{
	L->length = 0;
	return OK;
}
/*
 * �ж����Ա��Ƿ�Ϊ��
 */
Status isEmpty(const SqList L)
{
	if(L.length==0)
	{
		return TRUE;
	}
	else 
	{
		return FALSE;
	}
}
/*
 * ��ȡ����
 */

Status getLength(const SqList L)
{
	return L.length;
}
/*
 * ����λ�û�ȡԪ��
 */
Status getElem(SqList L, int i, Elemtype *e)
{
	if(i<0||i>L.length)
	{
		return ERROR;
	}
	*e = L.elem[i-1];
	return OK;
}
/*
 * �Ƚ�����Ԫ���Ƿ����
 */
Status compare (Elemtype e1, Elemtype e2)
{
	if(e1>e2)
	{
		return 1;
	}
	else if(e1==e2)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
/*
 * ����Ԫ��
 */
Status findElem(SqList L, Elemtype e, Status (*compare)(Elemtype, Elemtype))
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(!(*compare)(L.elem[i], e))
		{
			return i+1;
		}
	}
	if(i>L.length)
	{
		return ERROR;
	}
}
/*
 * ����ǰ��Ԫ��
 */
Status preElem(const SqList L, Elemtype cur_e, Elemtype *pre_e)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(cur_e==L.elem[i])
		{
			if(i!=0)
			{
				*pre_e = L.elem[i-1];
				return OK;
			}
			else
			{
				return ERROR;
			}
		}
	}
	if(i>L.length)
	{
		return ERROR;
	}
}
/*
 * ���Һ��Ԫ��
 */
Status nextElem(const SqList L, Elemtype cur_e, Elemtype *next_e)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(cur_e==L.elem[i])
		{
			if(i<L.length-1)
			{
				*next_e = L.elem[i-1];
			}
			else
			{
				return ERROR;
			}
		}
	}
	if(i>L.length)
	{
		return ERROR;
	}
}
/*
 * ����Ԫ��
 */
void visit(Elemtype e)
{
	printf("%d ", e);
}
/*
 * �������Ա�
 */
Status TraverseList(const SqList L, void (*visit)(Elemtype))
{
	int i;
	for(i=0;i<L.length;i++)
	{
		visit(L.elem[i]);
	}
	return OK;
}
/*
 * ����Ԫ��
 */
Status InsertElem(SqList *L, int i, Elemtype e)
{
	Elemtype *now;
	if(i<1||i>L->length+1)
	{
		return ERROR;
	}
	if(L->length>L->size)
	{
		now = (Elemtype *)realloc(L->elem, (L->size+INCREMENT_SIZE)*sizeof(Elemtype));
		if(!now)
		{
			return ERROR;
		}
		L->elem = now;
		L->size += INCREMENT_SIZE;
		Elemtype *p = &L->elem[i-1];
		Elemtype *q = &L->elem[L->length-1];
		for(;q>=p;q--)
		{
			*(q+1) = *q;
		}
		*p = e;
		++L->length;
		return OK;
	}
}
/*
 * ɾ��Ԫ�ز�������ֵ
 */
Status deleteElem(SqList *L, int i, Elemtype *e)
{
	if(i<1||i>L->length)
	{
		return ERROR;
	} 
	Elemtype *p = &L->elem[i-1];
	*e = *p;
	for(;p<&L->elem[L->length];p++)
	{
		*p = *(p+1);
	}
	--L->length;
	return OK;
}
int main(void)
{
	SqList L;
	if (InitList(&L))
	{
		Elemtype e;
		printf("init_success\n");
		int i;
		for (i = 0; i < 10; i++)
		{
			InsertElem(&L, i + 1, i);
		}
		printf("length is %d\n", getLength(L));
		if (getElem(L, 1, &e)) {
			printf("The first element is %d\n", e);
		}
		else
		{
			printf("element is not exist\n");		
		}
		if (isEmpty(L))
		{
			printf("list is empty\n");
		}
		else
		{
			printf("list is not empty\n");
		}
		printf("The 5 at %d\n", findElem(L, 5, *compare));
		preElem(L, 6, &e);
		printf("The 6's previous element is %d\n", e);
		nextElem(L, 6, &e);
		printf("The 6's next element is %d\n", e);
		deleteElem(&L, 1, &e);
		printf("delete first element is %d\n", e);
		printf("list:");
		TraverseList(L,visit);
		if (destoryList(&L))
		{
			printf("\ndestroy_success\n");
		}
	}
	return 0;
}