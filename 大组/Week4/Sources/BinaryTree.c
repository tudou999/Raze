#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "binary_sort_tree.h"

//������ʾ���˵��ĺ���
void DisplayMainMenu()
{
	//����߽���
	printf("\n======================\n");

	//�������
	for (int i = 0; i < 8; i++)
		printf("%s\n", MainMenu[i]);

	printf("======================\n");
}

//�жϷǷ�����
int errorinput(char ch)
{
	if (ch < '1' || ch > '8')
		return 0;
	return 1;
}

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

//��ջ
LinkStack* pushLStack(LinkStack* s, NodePtr Tpoint)
{
	//�����½ڵ�
	LinkStackPtr p = (LinkStackPtr)malloc(LEN1);
	p->point = Tpoint;

	//���ջ��Ϊ��
	if (isEmptyLStack(s))
	{
		//����ջ��
		p->next = s->top;
		s->top = p;
	}

	//���ջΪ��
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
	//���ջ��Ϊ��
	if (isEmptyLStack(s))
	{
		//��ʼ����p1Ϊջ����p2Ϊջ����һλ
		LinkStackPtr p1 = s->top;
		LinkStackPtr p2 = p1->next;

		p1->next = NULL;

		s->top = p2;
		s->count--;
	}

	//������ջ
	return s;
}

//�õ�ջ��Ԫ��
int getTopLStack(LinkStack* s)
{
	return s->top->point->value;
}

//��ʼ������
void InitLQueue(LQueue* Q)
{
	//��ʼ��Ϊһ���ն���
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

//�������Ƿ�Ϊ��
int IsEmptyLQueue(LQueue* Q)
{
	//�������Ϊ�շ���0
	if (Q->front == NULL)
		return 0;

	//���в�Ϊ�շ���1
	else
		return 1;
}

//��Ӳ���
LQueue* EnLQueue(LQueue* Q, NodePtr Tpoint)
{
	LNode* p = (LNode*)malloc(LEN4);
	p->point = Tpoint;

	if (IsEmptyLQueue(Q))
	{
		//�����β
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

	//���ض���
	return Q;
}

//���Ӳ���
LQueue* DeLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		//��ʼ����p1Ϊ��ͷ��p2Ϊ��ͷ��һλ
		LNode* p1 = Q->front;
		LNode* p2 = p1->next;

		p1->next = NULL;

		Q->front = p2;
		Q->length--;
	}

	//������ջ
	return Q;
}

//��ʼ��������
BinarySortTreePtr BST_init(BinarySortTreePtr tree)
{
	//��ʼ�����������ڵ�ָ��ΪNULL
	tree = (BinarySortTreePtr)malloc(len_tree);
	tree->root = NULL;
	return tree;
}

//����ڵ�
BinarySortTreePtr BST_insert(BinarySortTreePtr tree, ElemType data)
{
	//�жϽڵ��Ƿ�Ϊ��
	if (tree == NULL)
	{
		printf("������δ��ʼ����\n");
		return NULL;
	}

	//����Ѿ���ʼ�����Ǹ��ڵ�Ϊ��
	if (tree->root == NULL)
	{
		//���ٸ��ڵ㣬����ֵ
		tree->root = (NodePtr)malloc(len_node);
		tree->root->value = data;

		//������Ҷ��ֵΪ��
		tree->root->left = NULL;
		tree->root->right = NULL;

		printf("���ݲ���ɹ���\n");
		return tree;
	}

	//����ָ��p1���ڱ���������
	NodePtr p1 = tree->root, p2 = p1;

	while (p1 != NULL)
	{
		//p2���ڴ洢��ָ���ǰһ���ڵ�
		p2 = p1;

		//���С�����������
		if (data < p1->value)
		{
			p1 = p1->left;
			continue;
		}

		//����󣬱������ұ�
		if (data > p1->value)
		{
			p1 = p1->right;
			continue;
		}

		if (data == p1->value)
		{
			printf("���ݲ���ʧ�ܣ�\n");
			return tree;
		}
	}

	if (data < p2->value)
	{
		//�����½ڵ�
		p2->left = (NodePtr)malloc(len_node);
		p1 = p2->left;
	}

	if (data > p2->value)
	{
		//�����½ڵ�
		p2->right = (NodePtr)malloc(len_node);
		p1 = p2->right;
	}

	//�����ṹ���е���ֵ
	p1->value = data;
	p1->left = NULL;
	p1->right = NULL;

	printf("���ݲ���ɹ���\n");
	return tree;
}

//ɾ���ڵ�
BinarySortTreePtr BST_delete(BinarySortTreePtr tree, ElemType data)
{
	//���ȱ������ҽڵ�
	
	//�жϽڵ��Ƿ�Ϊ��
	if (tree == NULL || tree->root == NULL)
	{
		printf("������δ��ʼ���������ݣ�\n");
		return NULL;
	}

	//����ָ��p1���ڱ���������
	NodePtr p1 = tree->root, p2 = p1;

	while (p1 != NULL)
	{
		//p2Ϊp1��ǰһ���ڵ�
		p2 = p1;

		//���С�����������
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

	//�жϸýڵ��Ƿ����
	if (p1 == NULL)
	{
		//�����ڱ���
		printf("�ýڵ㲻���ڣ�\n");
		return tree;
	}

	else
	{
		//Ҫɾ���Ľڵ���Ҷ�ӣ�ֱ��ɾ
		if (p1->left == NULL && p1->right == NULL)
			p1 = NULL;

		//����������
		if (p1->left != NULL && p1->right != NULL)
		{
			//��ֱ��ǰ��
			p2 = p1->left;

			while (p2->right != NULL && p2 != NULL)
				p2 = p2->right;

			//��������ʱ��p2����ֵ��Ϊֱ��ǰ��
			p1->value = p2->value;
			p2 = NULL;
		}

		//ֻ��һ������
		else
		{
			//�������Ҷ
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

			//�������Ҷ
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

//���ҽڵ�
BinarySortTreePtr BST_search(BinarySortTreePtr tree, ElemType data)
{
	//���ȱ������ҽڵ�

    //�жϽڵ��Ƿ�Ϊ��
	if (tree == NULL || tree->root == NULL)
	{
		printf("������δ��ʼ���������ݣ�\n");
		return NULL;
	}

	//����ָ��p1���ڱ���������
	NodePtr p1 = tree->root, p2 = p1;

	while (p1 != NULL)
	{
		//p2Ϊp1��ǰһ���ڵ�
		p2 = p1;

		//���С�����������
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
			printf("�������д��ڸ����ݣ�\n");
			return tree;
		}
	}

	//�����û�ҵ�������failed
	printf("�������в��޴����ݣ�\n");
	return tree;
}

//ǰ��������ǵݹ飩
Status BST_preorderI(NodePtr point)	
{
	if (point == NULL)
		return failed;

	LinkStack* STACK = (LinkStack*)malloc(LEN2);
	initLStack(STACK);

	//����һ���ڵ�ѹջ
	STACK = pushLStack(STACK, point);

	//��ʼ��ָ��p1Ϊ���ڵ�
	NodePtr p1 = STACK->top->point;

	while (p1 && isEmptyLStack(STACK))
	{
		//���ջ�����ջ
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

//ǰ��������ݹ飩
Status BST_preorderR(NodePtr point)
{
	//�жϽڵ��Ƿ�Ϊ��
	if (point == NULL)
		return;

	printf("%d ", point->value);
	BST_preorderR(point->left);
	BST_preorderR(point->right);
}

//����������ǵݹ飩
Status BST_inorderI(NodePtr point)
{
	if (point == NULL)
		return failed;

	LinkStack* STACK = (LinkStack*)malloc(LEN2);
	initLStack(STACK);

	//����һ���ڵ�ѹջ
	STACK = pushLStack(STACK, point);

	//��ʼ��ָ��p1Ϊ���ڵ�
	NodePtr p1 = STACK->top->point;

	//��ջ��Ϊ��ʱѭ������
	while (p1 && isEmptyLStack(STACK))
	{
		//���ҵ�����Ҷʱͣ��
		while (p1->left)
		{
			p1 = p1->left;
			STACK = pushLStack(STACK, p1);
		}

		//���ջ���Ƿ���������
		
		//����У��Ƚ�ջ����ջ��ʼ���±���
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

		//���û�У�ֱ�ӽ��븸�ڵ㣬��ѭ��ֱ�����ڵ����������
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

//����������ݹ飩
Status BST_inorderR(NodePtr point)
{
	//�жϽڵ��Ƿ�Ϊ��
	if (point == NULL)
		return;

	BST_inorderR(point->left);
	printf("%d ", point->value);
	BST_inorderR(point->right);
}

//����������ǵݹ飩
Status BST_postorderI(NodePtr point)
{
	if (point == NULL)
		return failed;

	LinkStack* STACK = (LinkStack*)malloc(LEN2);
	initLStack(STACK);

	//��ʼ��ָ��p1Ϊ���ڵ�
	NodePtr	p1 = point;
	NodePtr p2 = point;

	//��ջ��Ϊ��ʱѭ������
	while (p1 || isEmptyLStack(STACK))
	{
		//������ջ�����ҵ�����Ҷʱͣ��
		while (p1)
		{
			STACK = pushLStack(STACK, p1);
			p1 = p1->left;
		}
		p1 = STACK->top->point;

		//���ջ���Ƿ���������
		if (p1 && p1->right && p1->right != p2)
			p1 = p1->right;

		//���û�����������Ѿ�������
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

//����������ݹ飩
Status BST_postorderR(NodePtr point)
{
	//�жϽڵ��Ƿ�Ϊ��
	if (point == NULL)
		return;

	BST_postorderR(point->left);
	BST_postorderR(point->right);
	printf("%d ", point->value);
}

//�������
Status BST_levelOrder(NodePtr point)
{
	if (point == NULL)
		return failed;

	//��ʼ������
	LQueue* Q = (LQueue*)malloc(LEN3);
	InitLQueue(Q);

	//����һ���ڵ����
	Q = EnLQueue(Q, point);

	//��ʼ��ָ��p1Ϊ���ڵ㣨��ͷ��
	NodePtr p1 = Q->front->point;

	while (p1 && IsEmptyLQueue(Q))
	{
		//�����ͷ�����
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
		printf("����������ʵ�ֵĹ��ܣ���������1-8�������س���");
		scanf("%s", &number);

		while (errorinput(number) == 0)
		{
			printf("����������ֲ��Ϲ淶�����������룡\n");
			printf("����������ʵ�ֵĹ��ܣ���������1-8�������س���");
			scanf("%s", &number);
		}

		switch (number - '0')
		{
			//��ʼ��������
		case 1:
			twoXtree = BST_init(twoXtree);
			if (twoXtree != NULL)
				printf("��ʼ���������ɹ���\n");
			else
				printf("��ʼ��������ʧ�ܣ�\n");
			break;

			//���ҽڵ�
		case 2:
			//�жϽڵ��Ƿ�Ϊ��
			if (twoXtree == NULL || twoXtree->root == NULL)
			{
				printf("������δ��ʼ���������ݣ�\n");
				break;
			}
			printf("�������Ҫ���ҵ����֣�");
			scanf("%d", &inputnum);
			twoXtree = BST_search(twoXtree, inputnum);
			break;

			//��������
		case 3:
			if (twoXtree == NULL)
			{
				printf("������δ��ʼ����\n");
				break;
			}
			printf("�������Ҫ��������֣�");
			scanf("%d", &inputnum);
			twoXtree = BST_insert(twoXtree, inputnum);
			break;

			//ɾ������
		case 4:
			if (twoXtree == NULL || twoXtree->root == NULL)
			{
				printf("������δ��ʼ���������ݣ�\n");
				break;
			}
			printf("�������Ҫɾ�������֣�");
			scanf("%d", &inputnum);
			twoXtree = BST_delete(twoXtree, inputnum);
			break;

			//����������ǵݹ飩
		case 5:
			if (twoXtree == NULL || twoXtree->root == NULL)
			{
				printf("������δ��ʼ���������ݣ�\n");
				break;
			}
			printf("ǰ����������");
			BST_preorderI(twoXtree->root);
			printf("\n");
			printf("������������");
			BST_inorderI(twoXtree->root);
			printf("\n");
			printf("������������");
			BST_postorderI(twoXtree->root);
			printf("\n");
			break;

			//����������ݹ飩
		case 6:
			if (twoXtree == NULL || twoXtree->root == NULL)
			{
				printf("������δ��ʼ���������ݣ�\n");
				break;
			}
			printf("ǰ����������");
			BST_preorderR(twoXtree->root);
			printf("\n");			
			printf("������������");
			BST_inorderR(twoXtree->root);
			printf("\n");	
			printf("������������");
			BST_postorderR(twoXtree->root);
			printf("\n");
			break;
			
			//�������
		case 7:
			printf("������������");
			BST_levelOrder(twoXtree->root);
			printf("\n");
			break;

			//�˳�����
		case 8:
			return;
		}
	}
}