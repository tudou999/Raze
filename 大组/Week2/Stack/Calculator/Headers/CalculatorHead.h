#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define LEN1 sizeof(StackNode)
#define LEN2 sizeof(LinkStack)

//全局变量，mid为输入的中缀表达式，behind为计算出的后缀表达式
char mid[1000], behind[1000];

//创建一个字符串用于输出，j用于temp的下标
int j = 0;

typedef int ElemType;

typedef  struct StackNode
{
	char data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	//栈顶指针
	LinkStackPtr top;

	//栈中元素个数
	int	count;
}LinkStack;

void initLStack(LinkStack* s);
int isEmptyLStack(LinkStack* s);
char getTopLStack(LinkStack* s);
LinkStack* pushLStack(LinkStack* s, char ch);
LinkStack* popLStack(LinkStack* s);
void printStack(LinkStack* s);
int judgeNum(char ch);
void transform(char mid[]);
int errorinput(char str[]);
void calculate(char str[]);

#endif 