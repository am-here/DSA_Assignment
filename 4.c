#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
int CIRCULAR_QUEUE[SIZE];
int rear = -1;
int front = -1;
void CENQUE(int value)
{
	if (front == -1 && rear == -1)
		front = 0;
	rear = (rear + 1) % SIZE;
	CIRCULAR_QUEUE[rear] = value;
}
int CDELQUE()
{
	int deleted = CIRCULAR_QUEUE[front];
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	front = (front + 1) % SIZE;
	return deleted;
}
void CDISPLAY()
{
	int i;
	printf("\nCIRCULAR_QUEUE Elements:\n\n");
	i = front;
	if (front <= rear)
		for (; i <= rear; i++)
			printf("%d ", CIRCULAR_QUEUE[i]);
	else
	{
		for (; i < SIZE; i++)
			printf("%d ", CIRCULAR_QUEUE[i]);
		i = 0;
		for (; i <= rear; i++)
			printf("%d ", CIRCULAR_QUEUE[i]);
	}
	printf("\n\n");
}
int main()
{
	int i, value, ch;
	while (1)
	{
		printf("1.Insert an element in the CIRCULAR_QUEUE\n2.Delete an element in the CIRCULAR_QUEUE\n3.Display all the elements of the CIRCULAR_QUEUE\n4.Quit\n");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			if (front == (rear + 1) % SIZE)
			{
				printf("\nCIRCULAR_QUEUE Overflow\n\n");
				break;
			}
			printf("\nEnter value to be entered: ");
			scanf("%d", &value);
			CENQUE(value);
			printf("\n");
			break;
		case 2:
			if (front == -1)
			{
				printf("\nCIRCULAR_QUEUE is Empty\n\n");
				break;
			}
			printf("\nPopped value: %d\n\n", CDELQUE());
			break;
		case 3:
			if (front == -1)
				printf("\nCIRCULAR_QUEUE is Empty");
			else
				CDISPLAY();
			break;
		case 4:
			printf("\n***************************Thank You***************************\n\n");
			exit(1);
		default:
			printf("\nInvalid Input! \n\n");
		}
	}
	return 0;
}
