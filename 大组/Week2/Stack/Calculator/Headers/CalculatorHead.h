#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define LEN1 sizeof(StackNode)
#define LEN2 sizeof(LinkStack)

//ȫ�ֱ�����midΪ�������׺���ʽ��behindΪ������ĺ�׺���ʽ
char mid[1000], behind[1000];

//����һ���ַ������������j����temp���±�
int j = 0;

typedef int ElemType;

typedef  struct StackNode
{
	char data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	//ջ��ָ��
	LinkStackPtr top;

	//ջ��Ԫ�ظ���
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