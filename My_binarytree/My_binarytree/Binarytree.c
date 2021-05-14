#define _CRT_SECURE_NO_WARNINGS
#include"Binarytree.h"
#include"Queue.h"

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (!root->_left && !root->_right)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	k--;
	return BinaryTreeLevelKSize(root->_left, k) 
		+ BinaryTreeLevelKSize(root->_right, k);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* rl;
	BTNode* rr;
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
    rl = BinaryTreeFind(root->_left, x);
	if (rl)
		return rl;
	rr = BinaryTreeFind(root->_right, x);
	if (rr)
		return rr;
	return NULL;
}

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c\n", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	printf("%c\n", root->_data);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c\n", root->_data);
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	//1.利用队列
	Queue q;
	QueueInit(&q);
	//2.根入队列
	if (root)
	{
		QueuePush(&q, root);
	}
	//出队头的节点时，将他的左右子树入队，队列为NULL时退出循环
	while (!QueueEmpty(&q))
	{
		BTNode* r = QueueFront(&q);
		if (root->_left)
		{
			QueuePush(&q, root->_left);
		}
		if (root->_right)
		{
			QueuePush(&q, root->_right);
		}
		QueuePop(&q);
		printf("%c ", r->_data);
		QueueDestroy(&q);
	}
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	//将NULL也入队列，NULL出队列时，若队列中还有有效地址时，则不是完全二叉树
	while (!QueueEmpty(&q))
	{
		BTNode* r = QueueFront(&q);
		QueuePop(&q);
		if (r == NULL)
			break;
		QueuePush(&q, root->_left);
		QueuePush(&q, root->_right);
	}
	while (!QueueEmpty(&q))
	{
		if (QueueFront(&q))
			return false;
		QueueFront(&q);
	}
	QueueDestroy(&q);
	return true;
}