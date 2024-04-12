//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int
#define len_tree sizeof(BinarySortTreePtr)
#define len_node sizeof(NodePtr)
#define LEN1 sizeof(StackNode)
#define LEN2 sizeof(LinkStack)
#define LEN3 sizeof(LQueue)
#define LEN4 sizeof(LNode)
#define _CRT_SECURE_NO_WARNINGS

typedef int ElemType;

//�������ṹ
typedef struct Node 
{
    ElemType value; 
    struct Node* left, * right;
}Node, * NodePtr;

typedef struct BinarySortTree 
{
    NodePtr root;
} BinarySortTree, * BinarySortTreePtr;

//��ջ�ṹ
typedef  struct StackNode
{
	NodePtr point;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	//ջ��ָ��
	struct StackNode* top;

	//ջ��Ԫ�ظ���
	int	count;
}LinkStack;

//��ʽ���нṹ
typedef struct node
{
	NodePtr point;
	struct node* next;            //ָ��ǰ������һ���
} LNode;

typedef struct Lqueue
{
	LNode* front;                   //��ͷ
	LNode* rear;                    //��β
	size_t length;            //���г���
} LQueue;


//���˵�
char MainMenu[8][30] =
{
		"1.��ʼ��������",
		"2.���ҽڵ�",
		"3.����ڵ�",
		"4.ɾ���ڵ�",
		"5.����������ǵݹ飩",
		"6.����������ݹ飩",
		"7.�������",
		"8.�˳�",
};

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
BinarySortTreePtr BST_init(BinarySortTreePtr);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
BinarySortTreePtr BST_insert(NodePtr, ElemType);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
BinarySortTreePtr BST_delete(BinarySortTreePtr, ElemType);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
BinarySortTreePtr BST_search(BinarySortTreePtr, ElemType);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(NodePtr);

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr);

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(NodePtr);

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(NodePtr);

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr);

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(NodePtr);

void DisplayMainMenu();
int errorinput(char ch);
void initLStack(LinkStack*);
int isEmptyLStack(LinkStack*);
LinkStack* pushLStack(LinkStack*, int);
LinkStack* popLStack(LinkStack*);
int getTopLStack(LinkStack*);
int isEmptyLStack(LinkStack*);
void InitLQueue(LQueue* Q); 
int IsEmptyLQueue(LQueue* Q);
LQueue* EnLQueue(LQueue* Q, NodePtr Tpoint);
LQueue* DeLQueue(LQueue* Q);

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
