#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)
//stack
//[0,1,2,3,4,5,6]
//
typedef struct stack_ {
	int* stack;
	int f;
	int r;
	int n;
	int numOfData;
}stack;
int size(stack* stack)
{
	return(stack->numOfData);
}

int Next(int i, stack *stack)//f한칸 뒤 반환
{
	if (i + 1 == stack->n)
		return(0);
	return(i + 1);
}

int	Prev(int i, stack* stack) //f한칸 앞 반환.
{
	if (i == 0)
		return(stack->n - 1);
	return(stack->f - 1);
}

void	push(stack* stack, int data)
{
	//printf("stack f : %d\n", stack->f);
	stack->stack[stack->f] = data;
	stack->f = Next(stack->f, stack);
	stack->numOfData++;
}

int pop(stack* stack)
{
	if (Prev(Prev(stack->f, stack),stack) == stack->r)// Empty
		return(-1);
	stack->f = Prev(stack->f , stack);
	int data = stack->stack[stack->f];
	stack->numOfData--;
	return(data);
}
int empty(stack* stack)
{
	return(Prev(Prev(stack->f, stack), stack) == stack->r);
}
int top(stack* stack)
{
	if (empty(stack))
		return(-1);
	
	return(stack->stack[Prev(stack->f, stack)]);
}
/*  n = 9
0 1 2 3 4 5 6 7 8 
  f r


0 1 2 3 4 5 6 7 8 
      f         r  
  1 2 3 4 
  비어있는 개수 = r - f
*/
stack *	makeStack(int n)
{
	stack *s = (stack*)malloc(sizeof(stack));
	s->stack = (int*)malloc(sizeof(int) * n);
	s->f = 1;
	s->r = n - 1;
	s->n = n;
	s->numOfData = 0;
	return(s);
}

int main()
{
	stack* stack;
	int n;
	int data;
	scanf("%d", &n);
	stack = makeStack(n);

	char order[100];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", order);
		if (!strcmp(order, "push"))
		{
			
			scanf("%d", &data);
			push(stack, data);
		}
		else if (!strcmp(order, "pop"))
		{
			printf("%d\n", pop(stack));
		}
		else if (!strcmp(order, "size"))
		{
			printf("%d\n", size(stack));

		}
		else if (!strcmp(order, "empty"))
		{
			printf("%d\n", empty(stack));

		}
		else if (!strcmp(order, "top"))
		{
			printf("%d\n", top(stack));

		}
	}

	free(stack->stack);
	free(stack);

}