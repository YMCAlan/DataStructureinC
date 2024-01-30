#include "stack.h"

Stack* createStack(void)
{
	//Local definition
	Stack* stack;

	//statementds
	//allocate memory
	stack = (Stack*)malloc(sizeof(Stack));

	//initialize if stack == true
	if (stack)
	{
		stack->count = 0;
		stack->top = NULL;
	}
	return stack;
}

bool pushStack(Stack* stack, void* dataInPtr)
{
	//Local definitions
	stackNode* newPtr;

	//Statements
	//allocate new node
	newPtr = (stackNode*)malloc(sizeof(stackNode));

	//if newPtr is false
	if (!newPtr)
	{
		return false;
	}

	//store data in new node
	newPtr->dataPtr = dataInPtr;
	//link the new node link to stack top
	newPtr->link = stack->top;
	//make new node the top
	stack->top = newPtr;
	//increment stack count
	stack->count++;
	return true;
}

void* popStack(Stack* stack)
{
	//Local definitions
	void* dataOutPtr;
	stackNode* temp;

	//statements
	//if stack is empty
	if (stack->count == 0)
	{
		//Success to false
		dataOutPtr = NULL;
	}
	else
	{
		//get data form node data pointer
		dataOutPtr = stack->top->dataPtr;
		//temp node store current stack top
		temp = stack->top;
		//make second node become the top node
		stack->top = stack->top->link;
		//decrement stack count
		stack->count--;
		free(temp);
	}
	return dataOutPtr;
}

void* stackTop(Stack* stack)
{
	if (emptyStack(stack) == true)
	{
		//success to false
		return NULL;
	}
	else
	{
		return stack->top->dataPtr;
	}
}

bool emptyStack(Stack* stack)
{
	//if count = 0 return true else return false
	return (stack->count == 0);
}

bool fullStack(Stack* stack)
{
	//Local definition
	stackNode* temp;
	temp = NULL;

	//if memory not available
	if (temp == (stackNode*)malloc(sizeof(*(stack->top))))
	{
		free(temp);
		return true;
	}
	//Malloc fail
	return false;
}

int stackCount(Stack* stack)
{
	return stack->count;
}

Stack* destoryStack(Stack* stack)
{
	//Local definitions
	stackNode* temp;
	//statements
	//if stack in not empty
	if (stack)
	{
		//loop stack not empty
		while (stack->top != NULL)
		{
			//Delete data (data pointer point to)
			temp = stack->top;
			stack->top = stack->top->link;
			//delete top node
			free(temp);

		}
		//delete stack head
		free(stack);
	}
	return NULL;
}
