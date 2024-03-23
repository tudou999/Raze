#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "LQueue.h"

//初始化队列
void InitLQueue(LQueue* Q)
{
	//初始化为一个空队列
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

//销毁队列
void DestoryLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		//p1为队头，p2为队头下一位
		Node* p1 = Q->front;
		Node *p2 = p1->next;

		while (p1 != NULL && p2 != NULL)
		{
			p1->next == NULL;
			free(p1);
			p1 = p2;
			p2 = p2->next;
		}

		//将队尾销毁
		free(p1);
		Q->front = NULL;
		Q->rear = NULL;
		Q->length = 0;

		printf("队列已被销毁！\n");
	}

	//如果队列为空则报错
	else
		printf("队列为空，无法销毁！\n");
}

//检查队列是否为空
int IsEmptyLQueue(LQueue* Q)
{
	//如果队列为空返回0
	if (Q->front == NULL)
		return 0;

	//队列不为空返回1
	else
		return 1;
}

//查看队头元素
void* GetHeadLQueue(const LQueue* Q)
{
	return &Q->front->data;
}

//确定队列长度
int LengthLQueue(LQueue* Q)
{
	return Q->length;
}

//入队操作
LQueue* EnLQueue(LQueue* Q, void* data)
{
	p->data = data;

	if (IsEmptyLQueue(Q))
	{
		//插入队尾
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

	//返回队列
	return Q;
}

//出队操作
LQueue* DeLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		//初始化，p1为队头，p2为队头下一位
		Node* p1 = Q->front;
		Node* p2 = p1->next;

		p1->next = NULL;
		free(p1);

		Q->front = p2;
		Q->length--;

		printf("出队成功！\n");
	}

	else
		printf("队列为空，无法操作！\n");

	//返回新栈
	return Q;
}

//清空队列
void ClearLQueue(LQueue* Q)
{
	//队列不为空则清空队列
	if (IsEmptyLQueue(Q))
	{
		//p1为栈顶
		Node* p1 = Q->front;

		while (p1 != NULL)
		{
			p1->data = 0;
			p1 = p1->next;
		}

		printf("队列已被清空！\n");
	}

	//如果栈为空则报错
	else
		printf("队列为空，无法清空！\n");
}

//输出队列
void LPrint(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		Node* p = Q->front;
		printf("从队头至队尾的数据为：\n");

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
		printf("栈为空！\n");
}

//定义显示主菜单的函数
void DisplayMainMenu()
{
	//输出边界线
	printf("\n======================\n");

	//输出主体
	for (int i = 0; i < 9; i++)
		printf("%s\n", MainMenu[i]);

	printf("======================\n");
}

//定义显示选择菜单的函数
void DisplayChooseMenu()
{
	//输出边界线
	printf("\n======================\n");

	//输出主体
	for (int i = 0; i < 4; i++)
		printf("%s\n", ChooseMenu[i]);

	printf("======================\n");
}

//判断非法输入
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
		printf("请输入您想实现的功能（输入数字1-9）后点击回车：");
		scanf("%s", &number);

		while (errorinput(number) == 0)
		{
			printf("您输入的数字不合规范，请重新输入！\n");
			printf("请输入您想实现的功能（输入数字1-9）后点击回车：");
			scanf("%s", &number);
		}

		switch (number-'0')
		{
			//销毁队列
		case 1:
			DestoryLQueue(QUEUE);
			break;


			//判断队列是否为空
		case 2:
			if (IsEmptyLQueue(QUEUE))
				printf("队列不为空！\n");
			else
				printf("队列为空！\n");
			break;


			//查看队头元素
		case 3:
			if (IsEmptyLQueue(QUEUE))
			{
				printf("队头元素为：");
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
				printf("队头为空！\n");
			break;


			//确定队列长度
		case 4:
			Length = LengthLQueue(QUEUE);
			printf("队列长度为：%d\n", Length);
			break;


			//入队
		case 5:
			system("cls");
			DisplayChooseMenu();

			printf("请输入您想输入的类型（输入数字1-4）后点击回车：");
			scanf("%s", &number);

			while (errorinput(number) == 0)
			{
				printf("您输入的数字不合规范，请重新输入！\n");
				printf("请输入您想输入的类型（输入数字1-4）后点击回车：");
				scanf("%s", &number);
			}

			p = (Node*)malloc(LEN1);

			switch (number-'0')
			{
				//整型
			case 1:
				printf("请输入整型数据：");
				scanf("%d", &number1);
				p->data = &number1;
				p->type = 1;
				break;		


				//浮点型
			case 2:
				printf("请输入浮点型数据：");
				scanf("%f", &number2);
				p->data = &number2;
				p->type = 2;
				break;			


				//字符型
			case 3:
				printf("请输入字符：");
				scanf("%s", &number3);
				p->data = &number3;
				p->type = 3;
				break;				
				

				//取消操作
			case 4:
				system("cls");
				break;
			}
			QUEUE = EnLQueue(QUEUE, p->data);
			system("cls");
			DisplayMainMenu();
			break;


			//出队
		case 6:
			QUEUE = DeLQueue(QUEUE);
			break;


			//清空队列
		case 7:
			ClearLQueue(QUEUE);
			break;


			//打印队列
		case 8:
			LPrint(QUEUE);
			break;


			//退出
		case 9:
			return;
		}

	}
}