/*
	data = {
		author: Harsh Baid,
		roll: BTech/CSE/2020/024,
	}
*/

#include <stdio.h>
#include <stdlib.h>

int main();
void enque();
void deque();
void display();
void invalid();

typedef struct sll
{
    int data;
    struct sll *next;
} node;

int main()
{
    int ch;
    node *front = NULL;
    node *rear = NULL;
    do
    {
        system("cls");
        display(&front, &rear);
        printf("\n1. Enque\n2. Deque\n3. Quit\nEnter your choice: ");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 1:
            enque(&front, &rear);
            break;
        case 2:
            deque(&front);
            break;
        case 3:
            system("cls");
            display(&front, &rear);
            break;
        default:
            printf("\nInvalid Input!\n\n");
        }
    } while (ch != 3);
    printf("\n****Thank You****\n\n");
    return 0;
}
void enque(node **front, node **rear)
{
    int x;
    node *temp = (node *)malloc(sizeof(node));
    printf("\nEnter element: ");
    scanf("%d", &x);
    temp->data = x;
    temp->next = NULL;
    if ((*front) == NULL)
    {
        (*front) = temp;
        (*rear) = temp;
    }
    else
    {
        (*rear)->next = temp;
        (*rear) = temp;
    }
}
void deque(node **front)
{
    node *temp = *front;
    if (temp == NULL)
        return;
    temp = temp->next;
    (*front) = temp;
}
void display(node **front, node **rear)
{
    printf("\nQUEUE\n\n");
    node *temp = *front;
    if (temp == NULL)
    {
        printf("[Empty]\n");
        return;
    }
    // extra code for better printing work!
    printf("\t");
    while (temp != NULL)
    {
        printf("----");
        temp = temp->next;
    }
    printf("\nEXIT\t");
    // */
    temp = *front;
    while (temp != (*rear))
    {
        printf(" %d |", temp->data);
        temp = temp->next;
    }
    printf(" %d \t", temp->data);
    // extra code for better printing work!

    printf(" ENTRY\n", temp->data);
    temp = *front;
    printf("\t");
    while (temp != NULL)
    {
        printf("----");
        temp = temp->next;
    }
}