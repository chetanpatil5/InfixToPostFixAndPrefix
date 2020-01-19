
#pragma once
#include<stdio.h>

typedef struct Stack
{
	int top;
	char arr[30];
}Stack;

int isEmpty(Stack *);
int isFull(Stack *);
void push(Stack *,char );
char pop(Stack *);
void displayStack(Stack *s);
char* InfixToPostFix(Stack *s, char *exp);
char topIs(Stack *);
void InfixToPreFix(Stack *s, char *exp);