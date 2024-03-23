#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define LEN1 sizeof(StackNode)
#define LEN2 sizeof(LinkStack)

//typedef enum Status
//{
//	ERROR = 0,
//	SUCCESS = 1
//} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	//栈顶指针
	LinkStackPtr top;

	//栈中元素个数
	int	count;
}LinkStack;



//链栈
void initLStack(LinkStack* s);//初始化栈
int isEmptyLStack(LinkStack* s);//判断栈是否为空
int getTopLStack(LinkStack* s, ElemType* e);//得到栈顶元素
void clearLStack(LinkStack* s);//清空栈
void destroyLStack(LinkStack* s);//销毁栈
int LStackLength(LinkStack* s, int* length);//检测栈长度
LinkStack* pushLStack(LinkStack* s);//入栈
LinkStack* popLStack(LinkStack* s);//出栈
void printStack(LinkStack* s);//打印链栈
void DisplayMainMenu();
int errorinput(char ch);

//主菜单
char MainMenu[9][30] =
{
		"1.打印栈",
		"2.判断栈是否为空",
		"3.得到栈顶元素",
		"4.清空栈",
		"5.销毁栈",
		"6.检测栈长度",
		"7.入栈",
		"8.出栈",
		"9.退出",
};


#endif 