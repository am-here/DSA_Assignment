#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int STACK[SIZE];
int top = -1;

void PUSH(int value)
{
	STACK[++top] = value;
}
int POP()
{
	return STACK[top--];
}
void DISPLAY()
{
	printf("\nSTACK\n\n");
	int i;
	if (top == -1)
		printf("[Empty]\n");
	else
	{
		for (i = top; i >= 0; i--)
			printf("| %d |\n|___|\n", STACK[i]);
	}
	printf("\n\n");
}

int main()
{
	int i, value, ch;
	while (1)
	{
		system("cls");
		DISPLAY();
		printf("1.Push\n2.Pop\n3.Display\n4.Quit\n");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			if (top == SIZE - 1)
			{
				printf("Stack Overflow\n");
				break;
			}
			printf("\nEnter value to be pushed: ");
			scanf("%d", &value);
			PUSH(value);
			printf("\n");
			break;
		case 2:
			if (top == -1)
			{
				printf("\nStack is Empty\n\n");
				break;
			}
			printf("\nPopped value: %d\n\n", POP());
			break;
		case 3:
			DISPLAY();
			break;
		case 4:
			printf("\n***************************Thank You***************************\n\n");
			exit(1);
		default:
			printf("\nInvalid Input! \n");
		}
	}
	return 0;
}
