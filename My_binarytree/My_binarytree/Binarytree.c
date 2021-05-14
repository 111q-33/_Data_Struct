#define _CRT_SECURE_NO_WARNINGS
#include"Binarytree.h"
#include"Queue.h"

// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (!root->_left && !root->_right)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// ��������k��ڵ����
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

// ����������ֵΪx�Ľڵ�
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

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c\n", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	printf("%c\n", root->_data);
	BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c\n", root->_data);
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	//1.���ö���
	Queue q;
	QueueInit(&q);
	//2.�������
	if (root)
	{
		QueuePush(&q, root);
	}
	//����ͷ�Ľڵ�ʱ������������������ӣ�����ΪNULLʱ�˳�ѭ��
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

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	//��NULLҲ����У�NULL������ʱ���������л�����Ч��ַʱ��������ȫ������
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