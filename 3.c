#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
char QUEUE[SIZE];
int rear = -1;
int front = -1;
void ENQUE(char value)
{
	if (front == rear + 1)
	{
		front = -1;
		rear = -1;
	}
	if (front == -1 && rear == -1)
		front = 0;
	QUEUE[++rear] = value;
}
char DELQUE()
{
	return QUEUE[front++];
}
void DISPLAY()
{
	int i;
	printf("\nQUEUE Elements:\n\n");
	for (i = front; i <= rear; i++)
		printf("%c ", QUEUE[i]);
	printf("\n\n");
}
int main()
{
	int i;
	char ch, value;
	while (1)
	{
		DISPLAY();
		printf("Front = %d\nRear = %d\n\n", front, rear);
		printf("a) Insert an element in the QUEUE\nb) Delete an element in the QUEUE\nc) Display all the elements of the QUEUE\nd) Quit\n");
		printf("\nEnter your choice : ");
		scanf(" %c", &ch);
		switch (ch)
		{
		case 'a':
			if (rear == SIZE - 1 && front != rear + 1)
			{
				printf("\nQUEUE Overflow\n\n");
				break;
			}
			printf("\nEnter value to be entered: ");
			scanf(" %c", &value);
			ENQUE(value);
			printf("\n");
			system("cls");
			break;
		case 'b':
			if (front == -1 || front == rear + 1)
			{
				printf("\nQUEUE is Empty\n\n");
				break;
			}
			printf("\nPopped value: %c\n\n", DELQUE());
			system("cls");
			break;
		case 'c':
			if (front == -1 || front == rear + 1)
			{
				printf("\nQUEUE is Empty\n\n");
				break;
			}
			DISPLAY();
			system("cls");
			break;
		case 'd':
			printf("\n********************************************************************************\n\n");
			exit(1);
		default:
			printf("\nInvalid Input! \n\n");
			break;
		}
	}
	return 0;
}