#pragma once

//主菜单
char MainMenu[12][30] =
{
		"1.初始化链表",
		"2.插入新节点",
		"3.反转链表(递归）",
		"4.输出链表",
		"5.寻找链表中点",
		"6.判断链表是否成环",
		"7.删除节点",
		"8.奇偶反转",
		"9.查询链表",
		"10.构造循环链表",
		"11.反转链表(迭代）",
		"12.退出",
};
//链表中的节点
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
