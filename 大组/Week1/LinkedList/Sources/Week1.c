#define _CRT_SECURE_NO_WARNINGS
#define LEN sizeof(struct Node)
#include <stdio.h>
#include <Windows.h>
#include "LinkedList.h"

//定义全局变量n，用来记录节点个数
int n;

//定义显示主菜单的函数
void DisplayMainMenu()
{
	//输出边界线
	printf("\n======================\n");

	//输出主体
	for (int i = 0; i < 12; i++)
		printf("%s\n", MainMenu[i]);

	printf("======================\n");
}

//定义创建链表的函数
struct Node* CreateNode()
{
	struct Node* head, * p1, * p2;
	n = 0;
	head = NULL;
	p1 = (struct Node*)malloc(LEN);
	p2 = p1;
	printf("请输入第1个数据（若输入0则结束）：");
	scanf("%d", &p1->data);
	while (p1->data != 0)
	{
		n++;
		if (n == 1)
			//是第一个？
			head = p1;

		else
			p2->next = p1;

		p2 = p1;
		p1 = (struct Node*)malloc(LEN);
		printf("请输入第%d个数据（若输入0则结束）：", n + 1);
		scanf("%d", &p1->data);
	}
	p2->next = NULL;
	return(head);
}

//定义插入节点的函数
struct Node* InsertNode(struct Node* head)
{
	struct Node* p1, * p3 = (struct Node*)malloc(LEN);
	int where;

	//判断当前是否有链表
	if (head == NULL)
	{
		printf("当前无链表！\n");
		return NULL;
	}
	printf("请输入您想插入在哪个数据后：");
	scanf("%d", &where);
	p1 = head;
	while (p1->data != where && p1->next != NULL)
		p1 = p1->next;

	if (p1->data == where)
	{
		printf("请输入您想插入的数字：");
		scanf("%d", &p3->data);
		//在表头或表中
		if (p1->next != NULL)
		{
			p3->next = p1->next;
			head->next = p3;
		}
		//在表尾
		else
		{
			p1->next = p3;
			p3->next = NULL;
		}
	}
	else
		printf("查无此节点！\n");
	return head;
}

//定义递归反转链表的函数
struct Node* Reverse1(struct Node* head)
{
	if (head == NULL)
	{
		printf("当前无链表！\n");
		return head;
	}

	if (head->next == NULL)
		return(head);

	//递归反转head后的链表
	struct Node* last = Reverse1(head->next);

	//在head处做最后的操作
	head->next->next = head;
	head->next = NULL;
	printf("链表反转成功！\n");
	return last;
}

//定义输出链表的函数
void PrintList(struct Node* head)
{
	n = 0;
	struct Node* p = head;
	if (p == NULL)
	{
		printf("当前无链表！\n");
		return;
	}
	for (; p != NULL;)
	{
		n++;
		printf("第%d个节点数据是%d\n", n, p->data);
		p = p->next;
	}
	printf("\n");
}

//定义寻找链表中点的函数
struct Node* MidNode(struct Node* head)
{
	if (head == NULL)
	{
		printf("当前无链表！\n");
		return NULL;
	}

	if (head->next == NULL)
	{
		printf("当前链表只有一个节点！\n");
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
				printf("该链表个数是偶数，没有中点！\n");
				return NULL;
			}
			else 
			{
				printf("该链表有中点！\n");
				return slow;
			}
		}
	}
}

//定义判断链表是否成环的函数
void JudgeCircleNode(struct Node* head)
{
	if (head == NULL)
	{
		printf("当前无链表！\n");
		return NULL;
	}

	if (head->next == NULL)
	{
		printf("当前链表只有一个节点，无法成环\n");
		return NULL;
	}

	if (head->next != NULL && head->next->next == NULL)
	{
		printf("当前链表只有两个节点，无法成环\n");
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
			printf("该单链表成环！\n");
			return NULL;
		}
	}
	printf("该单链表不成环！\n");
}

//定义删除节点的函数
struct Node* DeleteNode(struct Node* head)
{
	struct Node* p1, * p2;
	int where;
	//判断当前是否有链表
	if (head == NULL)
	{
		printf("当前无链表！\n");
		return NULL;
	}
	p1 = head;
	p2 = NULL;
	printf("请输入您想删除的数据：");
	scanf("%d", &where);
	while (p1->data != where && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->data == where)
	{
		//就在链表头
		if (p1 == head)
			head = p1->next;
		//在链表中或表尾
		else
			p2->next = p1->next;
	}
	else
		printf("查无此节点！\n");
	return head;
}

//定义奇偶反转的函数
struct Node* SDReverseNode(struct Node* head)
{
	if (head == NULL)
	{
		printf("当前无链表！\n");
		return head;
	}

	if (head->next == NULL)
		return(head);

	struct Node* p1, * p2, * temp1, * temp2, * newhead;
	//初始化
	p1 = head;
	p2 = head->next;
	newhead = p2;
	temp1 = p2->next;

	//在表头的操作
	p2->next = p1;
	p1->next = temp1;
	temp2 = p1;
	p1 = p1->next;
	p2 = p1->next;
	temp1 = p2->next;

	//在表中的操作
	while (p1 != NULL && p2 != NULL)
	{
		p2->next = p1;
		p1->next = temp1;
		temp2->next = p2;
		temp2 = p1;
		p1 = p1->next;
		if (p1 != NULL)
		{
			p2 = p1->next;
			if (p2 != NULL)
				temp1 = p2->next;
			else
				break;
		}
		else
			break;
	}

	return newhead;
}

//定义查找节点的函数
void SearchNode(struct Node* head)
{
	//判断当前是否有链表
	if (head == NULL)
	{
		printf("当前无链表！\n");
		return NULL;
	}
	//n用于记录数据位置
	n = 1;
	int number;
	struct Node* p1, * p2;
	p1 = head;
	p2 = NULL;
	printf("请输入您想查找的数据：");
	scanf("%d", &number);
	while (p1->data != number && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
		n++;
	}
	if (p1->data == number)
		printf("该数据在第%d个节点\n", n);
	else
		printf("查无此节点！\n");
}

//定义创建循环链表的函数
struct Node* CreateCircle()
{
	struct Node* head, * p1, * p2;
	n = 0;
	head = NULL;
	p1 = (struct Node*)malloc(LEN);
	p2 = p1;
	printf("请输入第1个数据（若输入0则结束）：");
	scanf("%d", &p1->data);
	while (p1->data != 0)
	{
		n++;
		if (n == 1)
			//是第一个？
			head = p1;

		else
			p2->next = p1;

		p2 = p1;
		p1 = (struct Node*)malloc(LEN);
		printf("请输入第%d个数据（若输入0则结束）：", n + 1);
		scanf("%d", &p1->data);
	}
	p2->next = head;
	return(head);
}

//定义迭代反转链表的函数
struct Node* Reverse2(struct Node* head)
{
	if (head == NULL)
	{
		printf("当前无链表！\n");
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

	printf("链表反转成功！\n");
	return(p2);
}

int main()
{
	int number;
	struct Node* head = NULL, * mid;
	DisplayMainMenu();

	while (1)
	{
		printf("请输入您想实现的功能（输入数字1-12）后点击回车：");

		scanf("%d", &number);

		while (number < 1 || number > 12)
		{
			printf("您输入的数字不合规范，请重新输入！\n");
			printf("请输入您想实现的功能（输入数字1-12）后点击回车：");
			scanf("%d", &number);
		}

		switch (number)
		{

		//初始化链表
		case 1:
			head = CreateNode();
			system("cls");
			DisplayMainMenu();
			break;

		//插入新节点
		case 2:
			head = InsertNode(head);
			break;

		//递归反转链表
		case 3:
			head = Reverse1(head);
			break;

		//输出链表
		case 4:
			PrintList(head);
			break;

		//寻找链表中点
		case 5:
			mid = MidNode(head);
			break;

		//判断单链表是否成环
		case 6:
			JudgeCircleNode(head);
			break;

		//删除节点
		case 7:
			head = DeleteNode(head);
			break;

		//奇偶反转
		case 8:
			head = SDReverseNode(head);
			break;

		//查询链表
		case 9:
			SearchNode(head);
			break;

		//构建循环链表
		case 10:
			head = CreateCircle();
			break;

		//迭代反转链表
		case 11:
			head = Reverse2(head);
			break;

		case 12:
			return 0;
		}
	}
}
