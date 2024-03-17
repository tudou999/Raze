#define _CRT_SECURE_NO_WARNINGS
#define LEN sizeof(struct Node)
#include <stdio.h>
#include <Windows.h>
#include "LinkedList.h"

//����ȫ�ֱ���n��������¼�ڵ����
int n;

//������ʾ���˵��ĺ���
void DisplayMainMenu()
{
	//����߽���
	printf("\n======================\n");

	//�������
	for (int i = 0; i < 12; i++)
		printf("%s\n", MainMenu[i]);

	printf("======================\n");
}

//���崴������ĺ���
struct Node* CreateNode()
{
	struct Node* head, * p1, * p2;
	n = 0;
	head = NULL;
	p1 = (struct Node*)malloc(LEN);
	p2 = p1;
	printf("�������1�����ݣ�������0���������");
	scanf("%d", &p1->data);
	while (p1->data != 0)
	{
		n++;
		if (n == 1)
			//�ǵ�һ����
			head = p1;

		else
			p2->next = p1;

		p2 = p1;
		p1 = (struct Node*)malloc(LEN);
		printf("�������%d�����ݣ�������0���������", n + 1);
		scanf("%d", &p1->data);
	}
	p2->next = NULL;
	return(head);
}

//�������ڵ�ĺ���
struct Node* InsertNode(struct Node* head)
{
	struct Node* p1, * p3 = (struct Node*)malloc(LEN);
	int where;

	//�жϵ�ǰ�Ƿ�������
	if (head == NULL)
	{
		printf("��ǰ������\n");
		return NULL;
	}
	printf("����������������ĸ����ݺ�");
	scanf("%d", &where);
	p1 = head;
	while (p1->data != where && p1->next != NULL)
		p1 = p1->next;

	if (p1->data == where)
	{
		printf("�����������������֣�");
		scanf("%d", &p3->data);
		//�ڱ�ͷ�����
		if (p1->next != NULL)
		{
			p3->next = p1->next;
			head->next = p3;
		}
		//�ڱ�β
		else
		{
			p1->next = p3;
			p3->next = NULL;
		}
	}
	else
		printf("���޴˽ڵ㣡\n");
	return head;
}

//����ݹ鷴ת����ĺ���
struct Node* Reverse1(struct Node* head)
{
	if (head == NULL)
	{
		printf("��ǰ������\n");
		return head;
	}

	if (head->next == NULL)
		return(head);

	//�ݹ鷴תhead�������
	struct Node* last = Reverse1(head->next);

	//��head�������Ĳ���
	head->next->next = head;
	head->next = NULL;
	printf("����ת�ɹ���\n");
	return last;
}

//�����������ĺ���
void PrintList(struct Node* head)
{
	n = 0;
	struct Node* p = head;
	if (p == NULL)
	{
		printf("��ǰ������\n");
		return;
	}
	for (; p != NULL;)
	{
		n++;
		printf("��%d���ڵ�������%d\n", n, p->data);
		p = p->next;
	}
	printf("\n");
}

//����Ѱ�������е�ĺ���
struct Node* MidNode(struct Node* head)
{
	if (head == NULL)
	{
		printf("��ǰ������\n");
		return NULL;
	}

	if (head->next == NULL)
	{
		printf("��ǰ����ֻ��һ���ڵ㣡\n");
		return NULL;
	}

	struct Node* slow, * fast;
	slow = head;
	fast = head;
	while (slow != NULL)
	{
		if (fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		else
		{
			if (fast->next == NULL)
			{
				printf("�����������ż����û���е㣡\n");
				return NULL;
			}
			else 
			{
				printf("���������е㣡\n");
				return slow;
			}
		}
	}
}

//�����ж������Ƿ�ɻ��ĺ���
void JudgeCircleNode(struct Node* head)
{
	if (head == NULL)
	{
		printf("��ǰ������\n");
		return NULL;
	}

	if (head->next == NULL)
	{
		printf("��ǰ����ֻ��һ���ڵ㣬�޷��ɻ�\n");
		return NULL;
	}

	if (head->next != NULL && head->next->next == NULL)
	{
		printf("��ǰ����ֻ�������ڵ㣬�޷��ɻ�\n");
		return NULL;
	}

	struct Node* slow, * fast;
	slow = head;
	fast = head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			printf("�õ�����ɻ���\n");
			return NULL;
		}
	}
	printf("�õ������ɻ���\n");
}

//����ɾ���ڵ�ĺ���
struct Node* DeleteNode(struct Node* head)
{
	struct Node* p1, * p2;
	int where;
	//�жϵ�ǰ�Ƿ�������
	if (head == NULL)
	{
		printf("��ǰ������\n");
		return NULL;
	}
	p1 = head;
	p2 = NULL;
	printf("����������ɾ�������ݣ�");
	scanf("%d", &where);
	while (p1->data != where && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->data == where)
	{
		//��������ͷ
		if (p1 == head)
			head = p1->next;
		//�������л��β
		else
			p2->next = p1->next;
	}
	else
		printf("���޴˽ڵ㣡\n");
	return head;
}

//������ż��ת�ĺ���
struct Node* SDReverseNode(struct Node* head)
{
	if (head == NULL)
	{
		printf("��ǰ������\n");
		return head;
	}

	if (head->next == NULL)
		return(head);

	struct Node* p1, * p2, * temp, * newhead;
	p1 = head;
	p2 = head->next;
	newhead = p2;

	while (p1 != NULL && p2 != NULL)
	{
		temp = p2->next;
		p2->next = p1;
		p1->next = temp;
		p1 = p1->next;
		p2 = p1->next;
	}

	return head;
}

//������ҽڵ�ĺ���
void SearchNode(struct Node* head)
{
	//�жϵ�ǰ�Ƿ�������
	if (head == NULL)
	{
		printf("��ǰ������\n");
		return NULL;
	}
	//n���ڼ�¼����λ��
	n = 1;
	int number;
	struct Node* p1, * p2;
	p1 = head;
	p2 = NULL;
	printf("������������ҵ����ݣ�");
	scanf("%d", &number);
	while (p1->data != number && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
		n++;
	}
	if (p1->data == number)
		printf("�������ڵ�%d���ڵ�\n", n);
	else
		printf("���޴˽ڵ㣡\n");
}

//���崴��ѭ������ĺ���
struct Node* CreateCircle()
{
	struct Node* head, * p1, * p2;
	n = 0;
	head = NULL;
	p1 = (struct Node*)malloc(LEN);
	p2 = p1;
	printf("�������1�����ݣ�������0���������");
	scanf("%d", &p1->data);
	while (p1->data != 0)
	{
		n++;
		if (n == 1)
			//�ǵ�һ����
			head = p1;

		else
			p2->next = p1;

		p2 = p1;
		p1 = (struct Node*)malloc(LEN);
		printf("�������%d�����ݣ�������0���������", n + 1);
		scanf("%d", &p1->data);
	}
	p2->next = head;
	return(head);
}

//���������ת����ĺ���
struct Node* Reverse2(struct Node* head)
{
	if (head == NULL)
	{
		printf("��ǰ������\n");
		return head;
	}

	if (head->next == NULL)
		return(head);

	struct Node* p1, * p2, * temp;
	p1 = head;
	p2 = NULL;

	while (p1 != NULL)
	{
		temp = p1->next;
		p1->next = p2;
		p2 = p1;
		p1 = temp;
	}

	printf("����ת�ɹ���\n");
	return(p2);
}

int main()
{
	int number;
	struct Node* head = NULL, * mid;
	DisplayMainMenu();

	while (1)
	{
		printf("����������ʵ�ֵĹ��ܣ���������1-12�������س���");

		scanf("%d", &number);

		while (number < 1 || number > 12)
		{
			printf("����������ֲ��Ϲ淶�����������룡\n");
			printf("����������ʵ�ֵĹ��ܣ���������1-12�������س���");
			scanf("%d", &number);
		}

		switch (number)
		{

		//��ʼ������
		case 1:
			head = CreateNode();
			system("cls");
			DisplayMainMenu();
			break;

		//�����½ڵ�
		case 2:
			head = InsertNode(head);
			break;

		//�ݹ鷴ת����
		case 3:
			head = Reverse1(head);
			break;

		//�������
		case 4:
			PrintList(head);
			break;

		//Ѱ�������е�
		case 5:
			mid = MidNode(head);
			break;

		//�жϵ������Ƿ�ɻ�
		case 6:
			JudgeCircleNode(head);
			break;

		//ɾ���ڵ�
		case 7:
			head = DeleteNode(head);
			break;

		//��ż��ת
		case 8:
			head = SDReverseNode(head);
			break;

		//��ѯ����
		case 9:
			SearchNode(head);
			break;

		//����ѭ������
		case 10:
			head = CreateCircle();
			break;

		//������ת����
		case 11:
			head = Reverse2(head);
			break;

		case 12:
			return 0;
		}
	}
}