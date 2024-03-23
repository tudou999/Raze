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
	//ջ��ָ��
	LinkStackPtr top;

	//ջ��Ԫ�ظ���
	int	count;
}LinkStack;



//��ջ
void initLStack(LinkStack* s);//��ʼ��ջ
int isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
int getTopLStack(LinkStack* s, ElemType* e);//�õ�ջ��Ԫ��
void clearLStack(LinkStack* s);//���ջ
void destroyLStack(LinkStack* s);//����ջ
int LStackLength(LinkStack* s, int* length);//���ջ����
LinkStack* pushLStack(LinkStack* s);//��ջ
LinkStack* popLStack(LinkStack* s);//��ջ
void printStack(LinkStack* s);//��ӡ��ջ
void DisplayMainMenu();
int errorinput(char ch);

//���˵�
char MainMenu[9][30] =
{
		"1.��ӡջ",
		"2.�ж�ջ�Ƿ�Ϊ��",
		"3.�õ�ջ��Ԫ��",
		"4.���ջ",
		"5.����ջ",
		"6.���ջ����",
		"7.��ջ",
		"8.��ջ",
		"9.�˳�",
};


#endif 