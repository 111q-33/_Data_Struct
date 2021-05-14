#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)* 2);
	ps->_capacity = 2;
	ps->_top = 0;
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_capacity == ps->_top)//增容
	{
		STDataType* tmp = (STDataType*)realloc(ps->_a,sizeof(STDataType)* ps->_capacity*2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->_a = tmp;
		ps->_capacity = ps->_capacity * 2;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	ps->_top--;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}