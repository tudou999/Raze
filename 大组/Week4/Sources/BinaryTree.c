#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "binary_sort_tree.h"

//定义显示主菜单的函数
void DisplayMainMenu()
{
	//输出边界线
	printf("\n======================\n");

	//输出主体
	for (int i = 0; i < 8; i++)
		printf("%s\n", MainMenu[i]);

	printf("======================\n");
}

//判断非法输入
int errorinput(char ch)
{
	if (ch < '1' || ch > '8')
		return 0;
	return 1;
}

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

//入栈
LinkStack* pushLStack(LinkStack* s, NodePtr Tpoint)
{
	//开辟新节点
	LinkStackPtr p = (LinkStackPtr)malloc(LEN1);
	p->point = Tpoint;

	//如果栈不为空
	if (isEmptyLStack(s))
	{
		//更新栈顶
		p->next = s->top;
		s->top = p;
	}

	//如果栈为空
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
	//如果栈不为空
	if (isEmptyLStack(s))
	{
		//初始化，p1为栈顶，p2为栈顶下一位
		LinkStackPtr p1 = s->top;
		LinkStackPtr p2 = p1->next;

		p1->next = NULL;

		s->top = p2;
		s->count--;
	}

	//返回新栈
	return s;
}

//得到栈顶元素
int getTopLStack(LinkStack* s)
{
	return s->top->point->value;
}

//初始化队列
void InitLQueue(LQueue* Q)
{
	//初始化为一个空队列
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
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

//入队操作
LQueue* EnLQueue(LQueue* Q, NodePtr Tpoint)
{
	LNode* p = (LNode*)malloc(LEN4);
	p->point = Tpoint;

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
		LNode* p1 = Q->front;
		LNode* p2 = p1->next;

		p1->next = NULL;

		Q->front = p2;
		Q->length--;
	}

	//返回新栈
	return Q;
}

//初始化二叉树
BinarySortTreePtr BST_init(BinarySortTreePtr tree)
{
	//初始化，即将根节点指向为NULL
	tree = (BinarySortTreePtr)malloc(len_tree);
	tree->root = NULL;
	return tree;
}

//插入节点
BinarySortTreePtr BST_insert(BinarySortTreePtr tree, ElemType data)
{
	//判断节点是否为空
	if (tree == NULL)
	{
		printf("二叉树未初始化！\n");
		return NULL;
	}

	//如果已经初始化但是根节点为空
	if (tree->root == NULL)
	{
		//开辟根节点，并赋值
		tree->root = (NodePtr)malloc(len_node);
		tree->root->value = data;

		//将左右叶赋值为空
		tree->root->left = NULL;
		tree->root->right = NULL;

		printf("数据插入成功！\n");
		return tree;
	}

	//定义指针p1用于遍历二叉树
	NodePtr p1 = tree->root, p2 = p1;

	while (p1 != NULL)
	{
		//p2用于存储空指针的前一个节点
		p2 = p1;

		//如果小，遍历到左边
		if (data < p1->value)
		{
			p1 = p1->left;
			continue;
		}

		//如果大，遍历到右边
		if (data > p1->value)
		{
			p1 = p1->right;
			continue;
		}

		if (data == p1->value)
		{
			printf("数据插入失败！\n");
			return tree;
		}
	}

	if (data < p2->value)
	{
		//开辟新节点
		p2->left = (NodePtr)malloc(len_node);
		p1 = p2->left;
	}

	if (data > p2->value)
	{
		//开辟新节点
		p2->right = (NodePtr)malloc(len_node);
		p1 = p2->right;
	}

	//调整结构体中的数值
	p1->value = data;
	p1->left = NULL;
	p1->right = NULL;

	printf("数据插入成功！\n");
	return tree;
}

//删除节点
BinarySortTreePtr BST_delete(BinarySortTreePtr tree, ElemType data)
{
	//首先遍历，找节点
	
	//判断节点是否为空
	if (tree == NULL || tree->root == NULL)
	{
		printf("二叉树未初始化或无数据！\n");
		return NULL;
	}

	//定义指针p1用于遍历二叉树
	NodePtr p1 = tree->root, p2 = p1;

	while (p1 != NULL)
	{
		//p2为p1的前一个节点
		p2 = p1;

		//如果小，遍历到左边
		if (data < p1->value)
		{
			p1 = p1->left;
			continue;
		}
		if (data > p1->value)
		{
			p1 = p1->left;
			continue;
		}
		if (data == p1->value)
			break;
	}

	//判断该节点是否存在
	if (p1 == NULL)
	{
		//不存在报错
		printf("该节点不存在！\n");
		return tree;
	}

	else
	{
		//要删除的节点是叶子，直接删
		if (p1->left == NULL && p1->right == NULL)
			p1 = NULL;

		//有两个孩子
		if (p1->left != NULL && p1->right != NULL)
		{
			//找直接前驱
			p2 = p1->left;

			while (p2->right != NULL && p2 != NULL)
				p2 = p2->right;

			//遍历结束时，p2的数值即为直接前驱
			p1->value = p2->value;
			p2 = NULL;
		}

		//只有一个孩子
		else
		{
			//如果是左叶
			if (p1->left != NULL && p1->right == NULL)
			{
				if (p1->value < p2->value)
				{
					p2->left = p1->left;
					p1 = NULL;
				}
				if (p1->value > p2->value)
				{
					p2->right = p1->left;
					p1 = NULL;
				}
			}		

			//如果是右叶
			if (p1->left == NULL && p1->right != NULL)
			{
				if (p1->value < p2->value)
				{
					p2->left = p1->right;
					p1 = NULL;
				}
				if (p1->value > p2->value)
				{
					p2->right = p1->right;
					p1 = NULL;
				}
			}
		}
	}

	return tree;
}

//查找节点
BinarySortTreePtr BST_search(BinarySortTreePtr tree, ElemType data)
{
	//首先遍历，找节点

    //判断节点是否为空
	if (tree == NULL || tree->root == NULL)
	{
		printf("二叉树未初始化或无数据！\n");
		return NULL;
	}

	//定义指针p1用于遍历二叉树
	NodePtr p1 = tree->root, p2 = p1;

	while (p1 != NULL)
	{
		//p2为p1的前一个节点
		p2 = p1;

		//如果小，遍历到左边
		if (data < p1->value)
		{
			p1 = p1->left;
			continue;
		}
		if (data > p1->value)
		{
			p1 = p1->left;
			continue;
		}
		if (data == p1->value)
		{
			printf("二叉树中存在该数据！\n");
			return tree;
		}
	}

	//到最后没找到，返回failed
	printf("二叉树中查无此数据！\n");
	return tree;
}

//前序遍历（非递归）
Status BST_preorderI(NodePtr point)	
{
	if (point == NULL)
		return failed;

	LinkStack* STACK = (LinkStack*)malloc(LEN2);
	initLStack(STACK);

	//将第一个节点压栈
	STACK = pushLStack(STACK, point);

	//初始化指针p1为根节点
	NodePtr p1 = STACK->top->point;

	while (p1 && isEmptyLStack(STACK))
	{
		//输出栈顶后出栈
		printf("%d ", p1->value);
		STACK = popLStack(STACK);

		if (p1->right)
			STACK = pushLStack(STACK, p1->right);
		if (p1->left)
			STACK = pushLStack(STACK, p1->left);
		if (isEmptyLStack(STACK))
			p1 = STACK->top->point;
		if (isEmptyLStack(STACK) == 0)
			break;
	}

	free(STACK);
	return succeed;
}

//前序遍历（递归）
Status BST_preorderR(NodePtr point)
{
	//判断节点是否为空
	if (point == NULL)
		return;

	printf("%d ", point->value);
	BST_preorderR(point->left);
	BST_preorderR(point->right);
}

//中序遍历（非递归）
Status BST_inorderI(NodePtr point)
{
	if (point == NULL)
		return failed;

	LinkStack* STACK = (LinkStack*)malloc(LEN2);
	initLStack(STACK);

	//将第一个节点压栈
	STACK = pushLStack(STACK, point);

	//初始化指针p1为根节点
	NodePtr p1 = STACK->top->point;

	//当栈不为空时循环迭代
	while (p1 && isEmptyLStack(STACK))
	{
		//当找到最左叶时停下
		while (p1->left)
		{
			p1 = p1->left;
			STACK = pushLStack(STACK, p1);
		}

		//检查栈顶是否有右子树
		
		//如果有，先将栈顶出栈后开始重新遍历
		if (p1->right)
		{
			printf("%d ", p1->value);
			STACK = popLStack(STACK);
			p1 = p1->right;
			STACK = pushLStack(STACK, p1);
			if (isEmptyLStack(STACK))
				p1 = STACK->top->point;
			else
				break;
		}

		//如果没有，直接进入父节点，并循环直到父节点出现右子树
		else
		{
			while (p1->right == NULL)	
			{
				printf("%d ", p1->value);
				STACK = popLStack(STACK);
				if (isEmptyLStack(STACK))
					p1 = STACK->top->point;
				else
				{
					p1 = NULL;
					break;
				}
			}
			if (p1)
			{
				printf("%d ", p1->value);
				STACK = popLStack(STACK);

				p1 = p1->right;
				STACK = pushLStack(STACK, p1);
				if (isEmptyLStack(STACK))
					p1 = STACK->top->point;
				else
					break;
			}
			else
				break;
		}
	}

	free(STACK);
	return succeed;
}

//中序遍历（递归）
Status BST_inorderR(NodePtr point)
{
	//判断节点是否为空
	if (point == NULL)
		return;

	BST_inorderR(point->left);
	printf("%d ", point->value);
	BST_inorderR(point->right);
}

//后序遍历（非递归）
Status BST_postorderI(NodePtr point)
{
	if (point == NULL)
		return failed;

	LinkStack* STACK = (LinkStack*)malloc(LEN2);
	initLStack(STACK);

	//初始化指针p1为根节点
	NodePtr	p1 = point;
	NodePtr p2 = point;

	//当栈不为空时循环迭代
	while (p1 || isEmptyLStack(STACK))
	{
		//迭代入栈，当找到最左叶时停下
		while (p1)
		{
			STACK = pushLStack(STACK, p1);
			p1 = p1->left;
		}
		p1 = STACK->top->point;

		//检查栈顶是否有右子树
		if (p1 && p1->right && p1->right != p2)
			p1 = p1->right;

		//如果没有右子树或已经被访问
		else
		{
			printf("%d ", p1->value);
			p2 = p1;
			p1 = NULL;
			STACK = popLStack(STACK);
		}
	}

	free(STACK);
	return succeed;
}

//后序遍历（递归）
Status BST_postorderR(NodePtr point)
{
	//判断节点是否为空
	if (point == NULL)
		return;

	BST_postorderR(point->left);
	BST_postorderR(point->right);
	printf("%d ", point->value);
}

//层序遍历
Status BST_levelOrder(NodePtr point)
{
	if (point == NULL)
		return failed;

	//初始化队列
	LQueue* Q = (LQueue*)malloc(LEN3);
	InitLQueue(Q);

	//将第一个节点入队
	Q = EnLQueue(Q, point);

	//初始化指针p1为根节点（队头）
	NodePtr p1 = Q->front->point;

	while (p1 && IsEmptyLQueue(Q))
	{
		//输出队头后出队
		printf("%d ", p1->value);
		Q = DeLQueue(Q);

		if (p1->left)
			EnLQueue(Q, p1->left);
		if (p1->right)
			EnLQueue(Q, p1->right);
		if (IsEmptyLQueue(Q))
			p1 = Q->front->point;
		if (IsEmptyLQueue(Q) == 0)
			break;
	}

	free(Q);
	return succeed;
}

int main()
{
	char number;
	int inputnum;
	BinarySortTreePtr twoXtree = NULL;
	DisplayMainMenu();

	while (1)
	{
		printf("请输入您想实现的功能（输入数字1-8）后点击回车：");
		scanf("%s", &number);

		while (errorinput(number) == 0)
		{
			printf("您输入的数字不合规范，请重新输入！\n");
			printf("请输入您想实现的功能（输入数字1-8）后点击回车：");
			scanf("%s", &number);
		}

		switch (number - '0')
		{
			//初始化二叉树
		case 1:
			twoXtree = BST_init(twoXtree);
			if (twoXtree != NULL)
				printf("初始化二叉树成功！\n");
			else
				printf("初始化二叉树失败！\n");
			break;

			//查找节点
		case 2:
			//判断节点是否为空
			if (twoXtree == NULL || twoXtree->root == NULL)
			{
				printf("二叉树未初始化或无数据！\n");
				break;
			}
			printf("请输出您要查找的数字：");
			scanf("%d", &inputnum);
			twoXtree = BST_search(twoXtree, inputnum);
			break;

			//插入数据
		case 3:
			if (twoXtree == NULL)
			{
				printf("二叉树未初始化！\n");
				break;
			}
			printf("请输出您要插入的数字：");
			scanf("%d", &inputnum);
			twoXtree = BST_insert(twoXtree, inputnum);
			break;

			//删除数据
		case 4:
			if (twoXtree == NULL || twoXtree->root == NULL)
			{
				printf("二叉树未初始化或无数据！\n");
				break;
			}
			printf("请输出您要删除的数字：");
			scanf("%d", &inputnum);
			twoXtree = BST_delete(twoXtree, inputnum);
			break;

			//三序遍历（非递归）
		case 5:
			if (twoXtree == NULL || twoXtree->root == NULL)
			{
				printf("二叉树未初始化或无数据！\n");
				break;
			}
			printf("前序遍历结果：");
			BST_preorderI(twoXtree->root);
			printf("\n");
			printf("中序遍历结果：");
			BST_inorderI(twoXtree->root);
			printf("\n");
			printf("后序遍历结果：");
			BST_postorderI(twoXtree->root);
			printf("\n");
			break;

			//三序遍历（递归）
		case 6:
			if (twoXtree == NULL || twoXtree->root == NULL)
			{
				printf("二叉树未初始化或无数据！\n");
				break;
			}
			printf("前序遍历结果：");
			BST_preorderR(twoXtree->root);
			printf("\n");			
			printf("中序遍历结果：");
			BST_inorderR(twoXtree->root);
			printf("\n");	
			printf("后序遍历结果：");
			BST_postorderR(twoXtree->root);
			printf("\n");
			break;
			
			//层序遍历
		case 7:
			printf("层序遍历结果：");
			BST_levelOrder(twoXtree->root);
			printf("\n");
			break;

			//退出程序
		case 8:
			return;
		}
	}
}