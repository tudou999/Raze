#pragma once

//���˵�
char MainMenu[12][30] =
{
		"1.��ʼ������",
		"2.�����½ڵ�",
		"3.��ת����(�ݹ飩",
		"4.�������",
		"5.Ѱ�������е�",
		"6.�ж������Ƿ�ɻ�",
		"7.ɾ���ڵ�",
		"8.��ż��ת",
		"9.��ѯ����",
		"10.����ѭ������",
		"11.��ת����(������",
		"12.�˳�",
};
//�����еĽڵ�
struct Node
{
	int data;
	struct Node* next;
};

void DisplayMainMenu();

struct Node* CreateNode();
struct Node* InsertNode(struct Node* head);
struct Node* Reverse1(struct Node* head);
void PrintList(struct Node* head);
struct Node* MidNode(struct Node* head);
void JudgeCircleNode(struct Node* head);
struct Node* DeleteNode(struct Node* head);
struct Node* SDReverseNode(struct Node* head);
void SearchNode(struct Node* head);
struct Node* CreateCircle();
struct Node* Reverse2(struct Node* head);
