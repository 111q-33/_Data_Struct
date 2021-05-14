#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
test1()
{
	Stack s1;
	Stack* ps = &s1;
	StackInit(ps);
	StackPush(ps, 1);
	StackPush(ps, 2);
	StackPush(ps, 3);
	StackPush(ps, 4);
	while (!StackEmpty(ps))
	{
		printf("%d ", StackTop(ps));
		StackPop(ps);
	}
}

int main()
{
	test1();
	return 0;
}