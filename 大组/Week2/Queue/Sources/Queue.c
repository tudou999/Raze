#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "LQueue.h"

//��ʼ������
void InitLQueue(LQueue* Q)
{
	//��ʼ��Ϊһ���ն���
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

//���ٶ���
void DestoryLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		//p1Ϊ��ͷ��p2Ϊ��ͷ��һλ
		Node* p1 = Q->front;
		Node *p2 = p1->next;

		while (p1 != NULL && p2 != NULL)
		{
			p1->next == NULL;
			free(p1);
			p1 = p2;
			p2 = p2->next;
		}

		//����β����
		free(p1);
		Q->front = NULL;
		Q->rear = NULL;
		Q->length = 0;

		printf("�����ѱ����٣�\n");
	}

	//�������Ϊ���򱨴�
	else
		printf("����Ϊ�գ��޷����٣�\n");
}

//�������Ƿ�Ϊ��
int IsEmptyLQueue(LQueue* Q)
{
	//�������Ϊ�շ���0
	if (Q->front == NULL)
		return 0;

	//���в�Ϊ�շ���1
	else
		return 1;
}

//�鿴��ͷԪ��
void* GetHeadLQueue(const LQueue* Q)
{
	return &Q->front->data;
}

//ȷ�����г���
int LengthLQueue(LQueue* Q)
{
	return Q->length;
}

//��Ӳ���
LQueue* EnLQueue(LQueue* Q, void* data)
{
	p->data = data;

	if (IsEmptyLQueue(Q))
	{
		//�����β
		Q->rear->next = p;
		p->next = NULL;
		Q->rear = p;
	}

	else
	{
		Q->rear = p;
		Q->front = p;
		p->next = NULL;
	}

	Q->length++;

	//���ض���
	return Q;
}

//���Ӳ���
LQueue* DeLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		//��ʼ����p1Ϊ��ͷ��p2Ϊ��ͷ��һλ
		Node* p1 = Q->front;
		Node* p2 = p1->next;

		p1->next = NULL;
		free(p1);

		Q->front = p2;
		Q->length--;

		printf("���ӳɹ���\n");
	}

	else
		printf("����Ϊ�գ��޷�������\n");

	//������ջ
	return Q;
}

//��ն���
void ClearLQueue(LQueue* Q)
{
	//���в�Ϊ������ն���
	if (IsEmptyLQueue(Q))
	{
		//p1Ϊջ��
		Node* p1 = Q->front;

		while (p1 != NULL)
		{
			p1->data = 0;
			p1 = p1->next;
		}

		printf("�����ѱ���գ�\n");
	}

	//���ջΪ���򱨴�
	else
		printf("����Ϊ�գ��޷���գ�\n");
}

//�������
void LPrint(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		Node* p = Q->front;
		printf("�Ӷ�ͷ����β������Ϊ��\n");

		while (p != NULL)
		{
			switch (p->type)
			{
			case 1:
				printf("%d\n", *(int*)p->data);
				break;
			case 2:
				printf("%f\n", *(float*)p->data);
				break;
			case 3:
				printf("%c\n", *(char*)p->data);
				break;
			}			
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

//������ʾѡ��˵��ĺ���
void DisplayChooseMenu()
{
	//����߽���
	printf("\n======================\n");

	//�������
	for (int i = 0; i < 4; i++)
		printf("%s\n", ChooseMenu[i]);

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

	int number1;
	float number2;
	char number3;
	LQueue* QUEUE = (LQueue*)malloc(LEN2);
	InitLQueue(QUEUE);
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

		switch (number-'0')
		{
			//���ٶ���
		case 1:
			DestoryLQueue(QUEUE);
			break;


			//�ж϶����Ƿ�Ϊ��
		case 2:
			if (IsEmptyLQueue(QUEUE))
				printf("���в�Ϊ�գ�\n");
			else
				printf("����Ϊ�գ�\n");
			break;


			//�鿴��ͷԪ��
		case 3:
			if (IsEmptyLQueue(QUEUE))
			{
				printf("��ͷԪ��Ϊ��");
				switch (QUEUE->front->type)
				{
				case 1:
					printf("%d\n", *(int*)QUEUE->front->data);
					break;
				case 2:
					printf("%f\n", *(float*)QUEUE->front->data);
					break;
				case 3:
					printf("%c\n", *(char*)QUEUE->front->data);
					break;
				}
			}
			else
				printf("��ͷΪ�գ�\n");
			break;


			//ȷ�����г���
		case 4:
			Length = LengthLQueue(QUEUE);
			printf("���г���Ϊ��%d\n", Length);
			break;


			//���
		case 5:
			system("cls");
			DisplayChooseMenu();

			printf("������������������ͣ���������1-4�������س���");
			scanf("%s", &number);

			while (errorinput(number) == 0)
			{
				printf("����������ֲ��Ϲ淶�����������룡\n");
				printf("������������������ͣ���������1-4�������س���");
				scanf("%s", &number);
			}

			p = (Node*)malloc(LEN1);

			switch (number-'0')
			{
				//����
			case 1:
				printf("�������������ݣ�");
				scanf("%d", &number1);
				p->data = &number1;
				p->type = 1;
				break;		


				//������
			case 2:
				printf("�����븡�������ݣ�");
				scanf("%f", &number2);
				p->data = &number2;
				p->type = 2;
				break;			


				//�ַ���
			case 3:
				printf("�������ַ���");
				scanf("%s", &number3);
				p->data = &number3;
				p->type = 3;
				break;				
				

				//ȡ������
			case 4:
				system("cls");
				break;
			}
			QUEUE = EnLQueue(QUEUE, p->data);
			system("cls");
			DisplayMainMenu();
			break;


			//����
		case 6:
			QUEUE = DeLQueue(QUEUE);
			break;


			//��ն���
		case 7:
			ClearLQueue(QUEUE);
			break;


			//��ӡ����
		case 8:
			LPrint(QUEUE);
			break;


			//�˳�
		case 9:
			return;
		}

	}
}