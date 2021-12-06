/*
	data = {
		author: Harsh Baid,
		roll: BTech/CSE/2020/024,
	}
*/

#include <stdio.h>
#include <stdlib.h>

int main();
void starter_pack();
void menu();
void insert();
void insert_at_beg();
void insert_at_end();
void insert_at_any();
void delete ();
void delete_at_beg();
void delete_at_end();
void delete_at_any();
void display();
void invalid();

typedef struct sll
{
	int data;
	struct sll *next;
} node;

node *start = NULL;
int size = 0;

int main()
{
	int i, n;
	char ch;
	printf("Want to enter some elements initially? (Y/N): ");
	scanf(" %c", &ch);
	while (ch != 'Y' && ch != 'N')
	{
		invalid();
		printf("Want to enter some elements initially? (Y/N): ");
		scanf(" %c", &ch);
	}
	if (ch == 'Y')
		starter_pack();
	do
	{
		menu();
		printf("\nDo you want to continue? (Y/N): ");
		scanf(" %c", &ch);
		while (ch != 'Y' && ch != 'N')
		{
			invalid();
			printf("Do you want to continue? (Y/N): ");
			scanf(" %c", &ch);
		}
	} while (ch == 'Y');
	display();
	printf("\n****Thank You****\n\n");
	return 0;
}
void starter_pack()
{
	int i, n;
	printf("Enter number of elements you want to add: ");
	scanf("%d", &n);
	while (n == 0)
	{
		invalid();
		printf("Enter number of elements you want to add: ");
		scanf("%d", &n);
	}
	for (i = 0; i < n; i++)
		insert_at_end();
}
void menu()
{
	int ch;
	printf("\n1. Insert\n2. Delete\n3. Display\nEnter your choice: ");
	scanf(" %d", &ch);
	switch (ch)
	{
	case 1:
		insert();
		break;
	case 2:
		delete ();
		break;
	case 3:
		display();
		break;
	default:
		invalid();
	}
}
void insert()
{
	char ch;
	printf("\na. At the beginning\nb. At the end\nc. At any position\nEnter your choice: ");
	scanf(" %c", &ch);
	switch (ch)
	{
	case 'a':
		insert_at_beg();
		break;
	case 'b':
		insert_at_end();
		break;
	case 'c':
		insert_at_any();
		break;
	default:
		invalid();
	}
}
void insert_at_beg()
{
	int x;
	node *temp = (node *)malloc(sizeof(node));
	printf("\nEnter element: ");
	scanf("%d", &x);
	temp->data = x;
	temp->next = start;
	start = temp;
	size++;
}
void insert_at_end()
{
	if (size == 0)
	{
		insert_at_beg();
		return;
	}
	int x;
	node *temp = (node *)malloc(sizeof(node));
	printf("\nEnter element: ");
	scanf("%d", &x);
	temp->data = x;
	temp->next = NULL;
	node *t = start;
	while (t->next != NULL)
		t = t->next;
	t->next = temp;
	size++;
}
void insert_at_any()
{
	int x, pos, i;
	printf("\nEnter position: ");
	scanf("%d", &pos);
	if (size == 0 && pos != 1)
	{
		invalid();
		printf("Linked List is empty!\nThus, the element will be added at the beginning!!\n");
		insert_at_beg();
		return;
	}
	if (pos < 1)
	{
		invalid();
		printf("Element will be added at the beginning!!\n");
		insert_at_beg();
		return;
	}
	if (pos > size + 1)
	{
		invalid();
		printf("Element will be added at the end!!\n");
		insert_at_end();
		return;
	}
	if (pos == 1)
	{
		insert_at_beg();
		return;
	}
	if (pos == size + 1)
	{
		insert_at_end();
		return;
	}
	printf("\nEnter element: ");
	scanf("%d", &x);
	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	node *t = start;
	for (i = 1; i < pos - 1; i++)
		t = t->next;
	temp->next = t->next;
	t->next = temp;
	size++;
}
void delete ()
{
	if (size == 0)
	{
		printf("Linked List is empty!\n");
		return;
	}
	char ch;
	printf("\na. At the beginning\nb. At the end\nc. At any position\nEnter your choice: ");
	scanf(" %c", &ch);
	switch (ch)
	{
	case 'a':
		delete_at_beg();
		break;
	case 'b':
		delete_at_end();
		break;
	case 'c':
		delete_at_any();
		break;
	default:
		invalid();
	}
}
void delete_at_beg()
{
	node *temp = start;
	printf("%d is deleted from the list!\n", temp->data);
	start = start->next;
	free(temp);
	size--;
}
void delete_at_end()
{
	if (size == 1)
	{
		delete_at_beg();
		return;
	}
	node *temp = start;
	while (temp->next->next != NULL)
		temp = temp->next;
	node *t = temp->next;
	temp->next = NULL;
	printf("%d is deleted from the list!\n", t->data);
	free(t);
	size--;
}
void delete_at_any()
{
	int x, pos, i;
	printf("Enter position: ");
	scanf("%d", &pos);
	if (pos < 1)
	{
		invalid();
		printf("Element will be deleted from the beginning!!\n");
		delete_at_beg();
		return;
	}
	if (pos > size)
	{
		invalid();
		printf("Element will be deleted from the end!!\n");
		if (size == 1)
			delete_at_beg();
		else
			delete_at_end();
		return;
	}
	if (pos == 1)
	{
		delete_at_beg();
		return;
	}
	if (pos == size)
	{
		delete_at_end();
		return;
	}
	node *temp;
	node *t = start;
	for (i = 1; i < pos - 1; i++)
		t = t->next;
	temp = t->next;
	t->next = temp->next;
	printf("%d is deleted from the list!\n", temp->data);
	free(temp);
	size--;
}
void display()
{
	printf("\nLinked List: ");
	if (size == 0)
	{
		printf("[Empty]\n");
		return;
	}
	node *temp = start;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}
void invalid()
{
	printf("\nInvalid Input!\n\n");
}