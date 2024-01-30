#pragma once
#ifndef STACK_H
#define STACK_H


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack_node stackNode;
typedef struct stack Stack;

struct stack_node
{
	void* dataPtr;
	stackNode* link;
};

struct stack
{
	int count;
	stackNode* top;
};


Stack* createStack(void);

bool pushStack(Stack* stack, void* dataPtr);

void* popStack(Stack* stack);

void* stackTop(Stack* stack);

bool emptyStack(Stack* stack);

bool fullStack(Stack* stack);

int stackCount(Stack* stack);

Stack* destoryStack(Stack* stack);

#endif // !STACK_H