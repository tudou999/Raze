#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "CalculatorHead.h"

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
char getTopLStack(LinkStack* s)
{
	return s->top->data;
}

//��ջ
LinkStack* pushLStack(LinkStack* s, char ch)
{
	//�����½ڵ�
	LinkStackPtr p = (LinkStackPtr)malloc(LEN1);

	p->data = ch;

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
	}

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

//�ж��ַ��Ƿ�Ϊ����
int judgeNum(char ch)
{
	//��������֣�����1
	//��������֣�����0
	return(ch >= '0' && ch <= '9');
}

//����׺���ʽתΪ��׺���ʽ
void transform(char mid[])
{
	//����һ����ջ����ʼ��
	LinkStack* stack = (LinkStack*)malloc(LEN2);
	initLStack(stack);

	//����ջ��
	char top;

	for (int i = 0;; i++)
	{
		if(mid[i] != '\0')
		{
			//����ַ������֣�ֱ�������temp
			if (judgeNum(mid[i]))
			{
				behind[j] = mid[i];
				j++;
			}

			else
			{
				if (isEmptyLStack(stack))
				{
					//�õ�ջ��Ԫ��
					top = getTopLStack(stack);

					switch (mid[i])
					{
						//������ֱ��ѹջ
					case '(':
						stack = pushLStack(stack, mid[i]);
						break;


						//�˳����ж�ջ���Ƿ�Ϊ�˻��
					case '*':
					case '/':
					case 'x':
					case 'X':
						while (top == '*' || top == '/' || top == 'x' || top == 'X')
						{
							//���ջ�����ַ���ֱ�ӵ���
							behind[j] = getTopLStack(stack);
							j++;
							stack = popLStack(stack);
							if (isEmptyLStack(stack))
								top = getTopLStack(stack);
							else
								break;
						}
						//���ַ���ջ�����ٳ�ͻʱ��ѹջ
						stack = pushLStack(stack, mid[i]);
						break;


						//�Ӽ����ж�ջ���Ƿ�Ϊ�����Ż����֣������ֱ��ѹջ��������Ǿ͵���ջ�����ж�
					case '+':
					case '-':
						while (top == '*' || top == '/' || top == '+' || top == '-' || top == 'x' || top == 'X')
						{
							//���ջ�����ַ���ֱ�ӵ���
							behind[j] = getTopLStack(stack);
							j++;
							stack = popLStack(stack);
							if (isEmptyLStack(stack))
								top = getTopLStack(stack);
							else
								break;
						}
						//���ַ���ջ�����ٳ�ͻʱ��ѹջ
						stack = pushLStack(stack, mid[i]);
						break;

						//������
					case ')':
						while (top != '(')
						{
							//���ջ�����ַ���ֱ�ӵ���
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
				//���ջ�����ַ���ֱ�ӵ���
				behind[j] = getTopLStack(stack);
				j++;
				stack = popLStack(stack);
			}
			break;
		}
	}
}

//�жϷǷ�����
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

//�����׺���ʽ
void calculate(char str[])
{
	//����һ����ջ����ʼ��
	LinkStack* stack = (LinkStack*)malloc(LEN2);
	initLStack(stack);

	//������׺���ʽ
	for (int i = 0; i < strlen(str); i++)
	{
		//����ֱ��ѹջ
		if (judgeNum(str[i]))
			stack = pushLStack(stack, str[i]);

		//���ŵ���ջ���ټ���
		else
		{
			//��ջ������������
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
	printf("���ս���ǣ�%d\n", final);
}

int main()
{
	printf("�����������������׺���ʽ��");
	gets(mid);

	while(errorinput(mid) == 0)
	{
		printf("��ǰ��׺���ʽ�зǷ����룬���������룡\n");
		printf("�����������������׺���ʽ��");
		scanf("%s", mid);
	}

	printf("\n");

	transform(mid);

	behind[j + 1] = '\0';
	printf("���׺���ʽΪ��%s\n", behind);

	calculate(behind);

}