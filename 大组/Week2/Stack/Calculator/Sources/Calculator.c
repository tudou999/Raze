#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "CalculatorHead.h"

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
char getTopLStack(LinkStack* s)
{
	return s->top->data;
}

//入栈
LinkStack* pushLStack(LinkStack* s, char ch)
{
	//开辟新节点
	LinkStackPtr p = (LinkStackPtr)malloc(LEN1);

	p->data = ch;

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
	}

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

//判断字符是否为数字
int judgeNum(char ch)
{
	//如果是数字，返回1
	//如果非数字，返回0
	return(ch >= '0' && ch <= '9');
}

//将中缀表达式转为后缀表达式
void transform(char mid[])
{
	//创建一个空栈并初始化
	LinkStack* stack = (LinkStack*)malloc(LEN2);
	initLStack(stack);

	//创建栈顶
	char top;

	for (int i = 0;; i++)
	{
		if(mid[i] != '\0')
		{
			//如果字符是数字，直接输出到temp
			if (judgeNum(mid[i]))
			{
				behind[j] = mid[i];
				j++;
			}

			else
			{
				if (isEmptyLStack(stack))
				{
					//得到栈顶元素
					top = getTopLStack(stack);

					switch (mid[i])
					{
						//左括号直接压栈
					case '(':
						stack = pushLStack(stack, mid[i]);
						break;


						//乘除号判断栈顶是否为乘或除
					case '*':
					case '/':
					case 'x':
					case 'X':
						while (top == '*' || top == '/' || top == 'x' || top == 'X')
						{
							//获得栈顶的字符后直接弹出
							behind[j] = getTopLStack(stack);
							j++;
							stack = popLStack(stack);
							if (isEmptyLStack(stack))
								top = getTopLStack(stack);
							else
								break;
						}
						//当字符与栈顶不再冲突时，压栈
						stack = pushLStack(stack, mid[i]);
						break;


						//加减号判断栈顶是否为左括号或数字，如果是直接压栈，如果不是就弹出栈顶再判断
					case '+':
					case '-':
						while (top == '*' || top == '/' || top == '+' || top == '-' || top == 'x' || top == 'X')
						{
							//获得栈顶的字符后直接弹出
							behind[j] = getTopLStack(stack);
							j++;
							stack = popLStack(stack);
							if (isEmptyLStack(stack))
								top = getTopLStack(stack);
							else
								break;
						}
						//当字符与栈顶不再冲突时，压栈
						stack = pushLStack(stack, mid[i]);
						break;

						//右括号
					case ')':
						while (top != '(')
						{
							//获得栈顶的字符后直接弹出
							behind[j] = getTopLStack(stack);
							j++;
							stack = popLStack(stack);
							if (isEmptyLStack(stack))
								top = getTopLStack(stack);
							else 
								break;
						}
						stack = popLStack(stack);
						break;
					}
				}
				else
					stack = pushLStack(stack, mid[i]);
			}
		}
		else
		{
			while (isEmptyLStack(stack))
			{
				//获得栈顶的字符后直接弹出
				behind[j] = getTopLStack(stack);
				j++;
				stack = popLStack(stack);
			}
			break;
		}
	}
}

//判断非法输入
int errorinput(char str[])
{
	if (str[strlen(str) - 1] < '0' || str[strlen(str) - 1] > '9')
		return 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			continue;
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')' || str[i] == 'x' || str[i] == 'X')
			continue;
		else
			return 0;
	}
	return 1;
}

//计算后缀表达式
void calculate(char str[])
{
	//创建一个空栈并初始化
	LinkStack* stack = (LinkStack*)malloc(LEN2);
	initLStack(stack);

	//遍历后缀表达式
	for (int i = 0; i < strlen(str); i++)
	{
		//数字直接压栈
		if (judgeNum(str[i]))
			stack = pushLStack(stack, str[i]);

		//符号弹出栈顶再计算
		else
		{
			//将栈顶两个数弹出
			char test1;
			char temp[3];
			temp[2] = getTopLStack(stack);
			temp[1] = str[i];
			stack = popLStack(stack);
			temp[0] = getTopLStack(stack);
			stack = popLStack(stack);

			switch (temp[1])
			{
			case '+':
				test1 = ((temp[0] - '0') + (temp[2] - '0')) + '0';
				stack = pushLStack(stack, test1);
				break;


			case '-':
				test1 = ((temp[0] - '0') - (temp[2] - '0')) + '0';
				stack = pushLStack(stack, test1);
				break;


			case '*':
			case 'x':
			case 'X':
				test1 = ((temp[0] - '0') * (temp[2] - '0')) + '0';
				stack = pushLStack(stack, test1);
				break;

			case '/':
				test1 = ((temp[0] - '0') / (temp[2] - '0')) + '0';
				stack = pushLStack(stack, test1);
				break;
			}
		}
	}

	int final = getTopLStack(stack) - '0';
	printf("最终结果是：%d\n", final);
}

int main()
{
	printf("请输入您想运算的中缀表达式：");
	gets(mid);

	while(errorinput(mid) == 0)
	{
		printf("当前中缀表达式有非法输入，请重新输入！\n");
		printf("请输入您想运算的中缀表达式：");
		scanf("%s", mid);
	}

	printf("\n");

	transform(mid);

	behind[j + 1] = '\0';
	printf("其后缀表达式为：%s\n", behind);

	calculate(behind);

}