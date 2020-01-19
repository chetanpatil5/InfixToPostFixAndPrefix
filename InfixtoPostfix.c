
#include<stdio.h>
#include<string.h>
#include "Stack.h"

int isEmpty(Stack *s)
{
	if (s->top == -1)
	{
		return 1;
	}
	else
		return 0;
}
int isFull(Stack *s)
{
	if (s->top >= 29)
	{
		return 1;
	}
	else
		return 0;

}
void push(Stack *s ,char val)
{
	//int val = 0;
	if (!isFull(s))
	{
		s->top++;
		s->arr[s->top] = val;
	}
	else
	{
		printf("\nNo more elements can be added");
	}
}
char pop(Stack *s)
{
	char val = ' ';
	if (!isEmpty(s))
	{
		val = s->arr[s->top];
		s->top--;
		printf("\nElement %c deleted from successfully", val);
		return val; //0is returned because if top =0 then top-- top=-1 will be retunred
	}
	else
	{
		return '!';//if -1 is returned then element cannot be deleted
	}

}

void displayStack(Stack *s)
{
	for (int i = 0; i <= s->top; i++)
	{
		printf("%c -> ", s->arr[i]);

	}
}

char topIs(Stack *s)
{
	return s->arr[s->top];
}

int Prec(char ch)
{
	switch (ch)
	{
	case '+':
		return 1;
	case '-':
		return 1;

	case '*':
		return 2;
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

char* InfixToPostFix(Stack *s1, char *exp)
{
	char str[30];
	int k = 0;
	char poppedElement = '\0';
	int len = 0;
	for (int i = 0; exp[i] != '\0'; i++)
	{
		len++;
	}
	//printf("\n%d",len);
	for (int i = 0; i < len; i++)
	{
		//printf("%c\n",str[k]);
		if ((exp[i] >= 'a'&& exp[i] <= 'z') || (exp[i] >= 'A'&& exp[i] <= 'Z'))
		{
			str[k] = exp[i];
			k++;
		}
		else if (exp[i] == '(')
		{
			push(s1, exp[i]);
		}
		else if (exp[i] == ')')
		{
			while (topIs(s1) != '(' && !isEmpty(s1))
			{
				poppedElement = pop(s1);
				str[k] = poppedElement;
				k++;
			}
			if (!isEmpty(s1) && topIs(s1) != '(')
				return -1; // invalid expression              
			else
				poppedElement = pop(s1);
			//poppedElement = pop(s1); //because ( is still there in stack and must be removed
		}
		else
		{
			//it is a operator
			while (!isEmpty(s1) && Prec(exp[i]) <= Prec(topIs(s1)))
			{
				poppedElement = pop(s1);
				str[k] = poppedElement;
				k++;
			}
			push(s1, exp[i]);
		}

	}
	while (!isEmpty(s1))
	{
		poppedElement = pop(s1);
		str[k] = poppedElement;
		k++;
	}
	str[k] = '\0';
	//printf("\n%s\n", str);
	int lengthofstr = 0;
	int cnt = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		lengthofstr++;
		printf("\n%c , Len=%d", str[i], lengthofstr);
	}


	printf("\nLength is : %d", lengthofstr);
	char str1[30] = {'\0'};

	strcpy_s(str1, sizeof(str1), str);
	return str1;
}


void InfixToPreFix(Stack *s, char *exp)
{
	char retstr[30];
	_strrev(exp);

	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
		{
			exp[i] = ')';
		}
		else if (exp[i] == ')')
			exp[i] = '(';
	}



	strcpy_s(retstr, sizeof(retstr), InfixToPostFix(s, exp));
	_strrev(retstr);
	printf("\nPrefix String is %s", retstr);

	//InfixToPostFix(s,)
}