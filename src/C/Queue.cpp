#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int QElemtype;
typedef int Status;

/*
 * �洢�ṹ
 */
 
typedef struct QNode
{
	QElemtype data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;//��ͷָ�� 
	QueuePtr rear;//��βָ�� 
}LinkQueue;
/*
 * ��ʼ������
 */

Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
	{
		exit(OVERFLOW);
	}
	Q->front->next = NULL;
	return OK;
}
/*
 * ���ٶ���
 */
Status destroyQueue(LinkQueue *Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

/*
 * ��ն���
 */
Status clearQueue(LinkQueue *Q)
{
	destroyQueue(Q);
	InitQueue(Q);
}
/*
 * �ж϶����Ƿ�Ϊ��
 */
Status IsEmpty(LinkQueue Q)
{
	if(Q.front->next==NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
 } 
/*
 * ��ȡ���еĳ���
 */
Status getLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p = Q.front;
	while (Q.rear!=p)
	{
		i++;
		p = p->next;
	}
	return i;
 } 
/*
 * ��ȡ��ͷԪ��
 */
Status getHead(LinkQueue Q, QElemtype *e)
{
	QueuePtr p;
	if(Q.front==Q.rear)
	{
		return ERROR; 
	}
	p = Q.front->next;
	*e = p->data;
	return OK;
}
/*
 * ���
 */
Status EnQueue(LinkQueue *Q, QElemtype e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
	{
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}
/*
 * ����
 */
 
Status deQueue(LinkQueue *Q, QElemtype *e)
{
	QueuePtr p;
	if(Q->front == Q->rear)
	{
		return ERROR;
	}
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if(Q->rear==p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}
/*
 * ����Ԫ��
 */
 void visit(QElemtype e)
 {
 	printf("%d ", e);
 }
 /*
 * ��������
 */
 
 
