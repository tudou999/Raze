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

//二叉树结构
typedef struct Node 
{
    ElemType value; 
    struct Node* left, * right;
}Node, * NodePtr;

typedef struct BinarySortTree 
{
    NodePtr root;
} BinarySortTree, * BinarySortTreePtr;

//链栈结构
typedef  struct StackNode
{
	NodePtr point;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	//栈顶指针
	struct StackNode* top;

	//栈中元素个数
	int	count;
}LinkStack;

//链式队列结构
typedef struct node
{
	NodePtr point;
	struct node* next;            //指向当前结点的下一结点
} LNode;

typedef struct Lqueue
{
	LNode* front;                   //队头
	LNode* rear;                    //队尾
	size_t length;            //队列长度
} LQueue;


//主菜单
char MainMenu[8][30] =
{
		"1.初始化二叉树",
		"2.查找节点",
		"3.插入节点",
		"4.删除节点",
		"5.三序遍历（非递归）",
		"6.三序遍历（递归）",
		"7.层序遍历",
		"8.退出",
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
