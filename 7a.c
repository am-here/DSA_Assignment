/*
	data = {
		author: Harsh Baid,
		roll: BTech/CSE/2020/024,
	}
*/

#include <stdio.h>
#include <stdlib.h>

int main();
void PUSH();
void POP();
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
    node *top = NULL;
    do
    {
        system("cls");
        display(&top);
        printf("\n1. PUSH\n2. POP\n3. Quit\nEnter your choice: ");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 1:
            PUSH(&top);
            break;
        case 2:
            POP(&top);
            break;
        case 3:
            system("cls");
            display(&top);
            break;
        default:
            printf("\nInvalid Input!\n\n");
        }
    } while (ch != 3);
    printf("\n****Thank You****\n\n");
    return 0;
}
void PUSH(node **top)
{
    int x;
    node *temp = (node *)malloc(sizeof(node));
    printf("\nEnter element: ");
    scanf("%d", &x);
    temp->data = x;
    temp->next = (*top);
    (*top) = temp;
}
void POP(node **top)
{
    node *temp = (*top);
    if (temp == NULL)
        return;
    temp = temp->next;
    (*top) = temp;
}
void display(node **top)
{
    printf("\nSTACK\n\n");
    node *temp = (*top);
    if (temp == NULL)
    {
        printf("[Empty]\n");
        return;
    }
    while (temp != NULL)
    {
        printf("| %d |\n|___|\n", temp->data);
        temp = temp->next;
    }
}`
