#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "LinkStack.h"

//��ʼ��ջ
void initLStack(LinkStack* s)
{
	//��ʼ��Ϊһ������ջ
	s->top = NULL;
	s->count = 0;
}

//�ж�ջ�Ƿ�Ϊ��
int isEmptyLStack(LinkStack* s)
{
	//���ջΪ�շ���0
	if (s->top == NULL)
		return 0;

	//ջ��Ϊ�շ���1
	else
		return 1;
}

//�õ�ջ��Ԫ��
int getTopLStack(LinkStack* s)
{
	return s->top->data;
}

//���ջ��������ݵ��Ǳ�������)
void clearLStack(LinkStack* s)
{
	//ջ��Ϊ�������ջ
	if(isEmptyLStack(s))
	{
		//p1Ϊջ��
		LinkStackPtr p1 = s->top;

		while (p1 != NULL)
		{
			p1->data = 0;
			p1 = p1->next;
		}

		printf("ջ�ѱ���գ�\n");
	}

	//���ջΪ���򱨴�
	else
		printf("ջΪ�գ��޷���գ�\n");
}

//����ջ
void destroyLStack(LinkStack* s)
{
	if (isEmptyLStack(s))
	{
		//p1Ϊջ����p2Ϊջ����һλ
		LinkStackPtr p1 = s->top;
		LinkStackPtr p2 = p1->next;

		while (p1 != NULL && p2 != NULL)
		{
			p1->next == NULL;
			free(p1);
			p1 = p2;
			p2 = p2->next;
		}

		//��ջ������
		free(p1);
		s->count = 0;
		s->top = NULL;

		printf("ջ�ѱ����٣�\n");
	}

	//���ջΪ���򱨴�
	else
		printf("ջΪ�գ��޷����٣�\n");
}

//���ջ����
int LStackLength(LinkStack* s)
{
	return s->count;
}

//��ջ
LinkStack* pushLStack(LinkStack* s)
{

	//�����½ڵ�
	LinkStackPtr p = (LinkStackPtr)malloc(LEN1);

	//��������
	printf("������������ջ�����ݣ�");
	scanf("%d", &p->data);


	if (isEmptyLStack(s))
	{
		//����ջ��
		p->next = s->top;
		s->top = p;
	}

	else
	{
		p->next = NULL;
		s->top = p;
	}

	s->count++;

	//������ջ
	return s;
}

//��ջ
LinkStack* popLStack(LinkStack* s)
{
	if (isEmptyLStack(s))
	{
		//��ʼ����p1Ϊջ����p2Ϊջ����һλ
		LinkStackPtr p1 = s->top;
		LinkStackPtr p2 = p1->next;

		p1->next = NULL;
		free(p1);

		s->top = p2;
		s->count--;

		printf("�����ɹ���\n");
	}

	else
		printf("ջΪ�գ��޷�������\n");

	//������ջ
	return s;
}

//��ӡ��ջ
void printStack(LinkStack* s)
{
	if (isEmptyLStack(s))
	{
		LinkStackPtr p = s->top;
		printf("��ջ����ջ�׵�����Ϊ��\n");

		while (p != NULL)
		{
			printf("%d\n", p->data);
			p = p->next;
		}
	}
	else
		printf("ջΪ�գ�\n");
}

//������ʾ���˵��ĺ���
void DisplayMainMenu()
{
	//����߽���
	printf("\n======================\n");

	//�������
	for (int i = 0; i < 9; i++)
		printf("%s\n", MainMenu[i]);

	printf("======================\n");
}

//�жϷǷ�����
int errorinput(char ch)
{
	if (ch < '1' || ch > '9')
		return 0;
	return 1;
}


int main()
{
	char number;
    int element, Length;
	LinkStack* STACK = (LinkStack*)malloc(LEN2);
	initLStack(STACK);
	DisplayMainMenu();

	while (1)
	{
		printf("����������ʵ�ֵĹ��ܣ���������1-9�������س���");
		scanf("%s", &number);

		while (errorinput(number) == 0)
		{
			printf("����������ֲ��Ϲ淶�����������룡\n");
			printf("����������ʵ�ֵĹ��ܣ���������1-9�������س���");
			scanf("%s", &number);
		}

		switch (number - '0')
		{
		//�����ջ
		case 1:
			printStack(STACK);
			break;

		//�ж�ջ�Ƿ�Ϊ��
		case 2:
			if (isEmptyLStack(STACK))
				printf("ջ��Ϊ�գ�\n");
			else
				printf("ջΪ�գ�\n");
			break;

		//�õ�ջ��Ԫ��
		case 3:
			if (isEmptyLStack(STACK))
			{
				element = getTopLStack(STACK);
				printf("ջ��Ԫ��Ϊ��%d\n", element);
			}
			else
				printf("ջΪ�գ�\n");
			break;

		//���ջ
		case 4:
			clearLStack(STACK);
			break;

		//����ջ
		case 5:
			destroyLStack(STACK);
			break;

		//���ջ����
		case 6:
			Length = LStackLength(STACK);
			printf("ջ����Ϊ��%d\n", Length);
			break;

		//��ջ
		case 7:
			STACK = pushLStack(STACK);
			break;

		//��ջ
		case 8:
			STACK = popLStack(STACK);
			break;

		case 9:
			return 0;
		}
	}
}