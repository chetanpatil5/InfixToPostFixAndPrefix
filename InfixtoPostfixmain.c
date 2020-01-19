#include<stdio.h>
#include "Stack.h"
#include<string.h>

int main()
{
	char chch = '\0';
	int sw = 0;
	struct Stack s1;
	s1.top = -1;
	int ch = 0;
	char choice = ' ';
	char a='\0' ;
	char b='\0' ;

	for (int i = 0; i < 30; i++)
	{
		s1.arr[i] = 0;
	}

	//char exp[] = "(a+b)*(C-D)";
	char exp[30];
	
	char catchstr[30];

	printf("\nEnter the Infix expression");
	scanf_s("%s", exp,sizeof(exp) );
	
		printf("\n1. Prefix");
		printf("\n2. Postfix");
		scanf_s("%d", &sw);
		switch (sw)
		{
		case 1:InfixToPreFix(&s1, exp);
			break;
		case 2:
			strcpy_s(catchstr, sizeof(catchstr), InfixToPostFix(&s1, exp));
			printf("Postfix String is : %s",catchstr);
			break;
		default:
			break;
		}

	
	
	
	/*
	printf("\nConverting to Prefix now\n");
	strcpy_s(catchstr, sizeof(catchstr), InfixToPreFix(&s1, retstr));
	printf("\n");
	printf("\CatchStr : %s", catchstr);*/
	

	
	
	
	//displayStack(&s1);
	/*push(&s1, 'x');
	push(&s1, 'y');
	push(&s1, 'z');
	push(&s1, 'b');
	push(&s1, 'c');
	displayStack(&s1);*/

	//do
	//{
	//	printf("\n1. Push ");
	//	printf("\n2. Pop ");
	//	printf("\n3. Display \n");
	//	scanf_s("%d", &ch);

	//	switch (ch)
	//	{
	//	case 1:
	//		printf("\nEnter the Element to be entered into stack");
	//		scanf_s("%c",&b,sizeof(b));
	//		push(&s1,b);
	//		break;
	//	case 2:
	//		a = pop(&s1);
	//		printf("\nDeleted %c",a);
	//		if (a == '!')
	//		{
	//			printf("Element cannot be deleted ");
	//		}
	//		break;
	//	case 3:displayStack(&s1);
	//		break;
	//	default:
	//		break;
	//	}


	//	printf("\n\nContinue y/n : ");
	//	scanf_s("%c", &choice,sizeof(choice));
	//	scanf_s("%c", &choice,sizeof(choice));
	//} while (choice == 'y' || choice == 'Y');




	system("pause");
	return 0;
}