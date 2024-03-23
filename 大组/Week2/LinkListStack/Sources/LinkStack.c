#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "LinkStack.h"

//初始化栈
void initLStack(LinkStack* s)
{
	//初始化为一个空链栈
	s->top = NULL;
	s->count = 0;
}

//判断栈是否为空
int isEmptyLStack(LinkStack* s)
{
	//如果栈为空返回0
	if (s->top == NULL)
		return 0;

	//栈不为空返回1
	else
		return 1;
}

//得到栈顶元素
int getTopLStack(LinkStack* s)
{
	return s->top->data;
}

//清空栈（清空数据但是保留长度)
void clearLStack(LinkStack* s)
{
	//栈不为空则清空栈
	if(isEmptyLStack(s))
	{
		//p1为栈顶
		LinkStackPtr p1 = s->top;

		while (p1 != NULL)
		{
			p1->data = 0;
			p1 = p1->next;
		}

		printf("栈已被清空！\n");
	}

	//如果栈为空则报错
	else
		printf("栈为空，无法清空！\n");
}

//销毁栈
void destroyLStack(LinkStack* s)
{
	if (isEmptyLStack(s))
	{
		//p1为栈顶，p2为栈顶下一位
		LinkStackPtr p1 = s->top;
		LinkStackPtr p2 = p1->next;

		while (p1 != NULL && p2 != NULL)
		{
			p1->next == NULL;
			free(p1);
			p1 = p2;
			p2 = p2->next;
		}

		//将栈底销毁
		free(p1);
		s->count = 0;
		s->top = NULL;

		printf("栈已被销毁！\n");
	}

	//如果栈为空则报错
	else
		printf("栈为空，无法销毁！\n");
}

//检测栈长度
int LStackLength(LinkStack* s)
{
	return s->count;
}

//入栈
LinkStack* pushLStack(LinkStack* s)
{

	//开辟新节点
	LinkStackPtr p = (LinkStackPtr)malloc(LEN1);

	//输入数据
	printf("请输入您想入栈的数据：");
	scanf("%d", &p->data);


	if (isEmptyLStack(s))
	{
		//更新栈顶
		p->next = s->top;
		s->top = p;
	}

	else
	{
		p->next = NULL;
		s->top = p;
	}

	s->count++;

	//返回新栈
	return s;
}

//出栈
LinkStack* popLStack(LinkStack* s)
{
	if (isEmptyLStack(s))
	{
		//初始化，p1为栈顶，p2为栈顶下一位
		LinkStackPtr p1 = s->top;
		LinkStackPtr p2 = p1->next;

		p1->next = NULL;
		free(p1);

		s->top = p2;
		s->count--;

		printf("弹出成功！\n");
	}

	else
		printf("栈为空，无法弹出！\n");

	//返回新栈
	return s;
}

//打印链栈
void printStack(LinkStack* s)
{
	if (isEmptyLStack(s))
	{
		LinkStackPtr p = s->top;
		printf("从栈顶至栈底的数据为：\n");

		while (p != NULL)
		{
			printf("%d\n", p->data);
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
	LinkStack* STACK = (LinkStack*)malloc(LEN2);
	initLStack(STACK);
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

		switch (number - '0')
		{
		//输出链栈
		case 1:
			printStack(STACK);
			break;

		//判断栈是否为空
		case 2:
			if (isEmptyLStack(STACK))
				printf("栈不为空！\n");
			else
				printf("栈为空！\n");
			break;

		//得到栈顶元素
		case 3:
			if (isEmptyLStack(STACK))
			{
				element = getTopLStack(STACK);
				printf("栈顶元素为：%d\n", element);
			}
			else
				printf("栈为空！\n");
			break;

		//清空栈
		case 4:
			clearLStack(STACK);
			break;

		//销毁栈
		case 5:
			destroyLStack(STACK);
			break;

		//检测栈长度
		case 6:
			Length = LStackLength(STACK);
			printf("栈长度为：%d\n", Length);
			break;

		//入栈
		case 7:
			STACK = pushLStack(STACK);
			break;

		//出栈
		case 8:
			STACK = popLStack(STACK);
			break;

		case 9:
			return 0;
		}
	}
}