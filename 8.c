/*
	data = {
		author: Harsh Baid,
		roll: BTech/CSE/2020/024,
	}
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main();
void menu();
void input();
void insertion();
void evaluate();
void display();
void menu();

typedef struct sll
{
    int val;
    int exp;
    struct sll *next;
} node;

int main()
{
    char ch;
    do
    {
        system("cls");
        menu();
        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &ch);
        while (ch != 'Y' && ch != 'N')
        {
            printf("\nInvalid Input!\n\n");
            printf("Do you want to continue? (Y/N): ");
            scanf(" %c", &ch);
        }
    } while (ch == 'Y');
    system("cls");
    printf("\nWell! I hope you enjoyed a lot!\n");
    printf("\n****Thank You****\n\n");
    return 0;
}
void menu()
{
    node *pol1 = NULL;
    node *pol2 = NULL;
    node *pol3 = NULL;
    printf("\nEnter details for First Polynomial:\n");
    input(&pol1);
    system("cls");
    printf("\nEnter details for Second Polynomial:\n");
    input(&pol2);
    system("cls");
    printf("\n\n--/--/--/--/--Evaluating--/--/--/--/--\n");
    evaluate(&pol1, &pol2, &pol3);
    printf("\nFirst Polynomial: ");
    display(&pol1);
    printf("\nSecond Polynomial: ");
    display(&pol2);
    printf("\nResultant Polynomial:");
    display(&pol3);
}
void input(node **start)
{
    int n, val, exp, last = INT_MAX;
    printf("\nEnter number of terms in your polynomial: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("\nEnter the co-efficient of term %d: ", i);
        scanf("%d", &val);
        printf("What would be it's exponent? ");
        scanf("%d", &exp);
        while (exp > last || exp < 0 || exp < (n - i))
        {
            if (exp > last)
                printf("\nSorry! currently we are not capable of getting a polynomial in any random manner.\nWe are excepting the polynomial with exponents only in descending order!\n");
            else if (exp < 0)
                printf("\nSorry! currently we are not accepting negative values!\nWe are expecting a polynomial only with positive exponents!\n");
            else
                printf("\nIf you proceed with this exponent, you wouldn't be able to create a valid Polynomial!\nWe are excepting the polynomial with exponents only in descending order!\n");
            printf("\nWhat would be it's exponent? ");
            scanf("%d", &exp);
        }
        last = exp;
        insertion(start, val, exp);
    }
}
void insertion(node **start, int val, int exp)
{
    node *temp = (node *)malloc(sizeof(node)), *t;
    temp->val = val;
    temp->exp = exp;
    temp->next = NULL;
    if (*start == NULL)
    {
        temp->next = (*start);
        (*start) = temp;
    }
    else
    {
        t = (*start);
        while (t->next != NULL)
            t = t->next;
        t->next = temp;
    }
}
void evaluate(node **pol1, node **pol2, node **pol3)
{
    node *ans = *pol3;
    node *l1 = *pol1;
    node *l2 = *pol2;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->exp > l2->exp)
        {
            insertion(&ans, l1->val, l1->exp);
            l1 = l1->next;
        }
        else if (l1->exp < l2->exp)
        {
            insertion(&ans, l2->val, l2->exp);
            l2 = l2->next;
        }
        else
        {
            insertion(&ans, l1->val + l2->val, l2->exp);
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    while (l1 != NULL)
    {
        insertion(&ans, l1->val, l1->exp);
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        insertion(&ans, l2->val, l2->exp);
        l2 = l2->next;
    }
    (*pol3) = ans;
}
void display(node **start)
{
    node *temp = *start;
    while (temp->next != NULL)
    {
        if (temp->val < 0)
            printf("(%d)x^%d + ", temp->val, temp->exp);
        if (temp->val > 0)
            printf("%dx^%d + ", temp->val, temp->exp);
        temp = temp->next;
    }
    if (temp->val < 0)
    {
        if (temp->exp == 0)
            printf("(%d)", temp->val);
        else
            printf("(%d)x^%d", temp->val, temp->exp);
    }
    if (temp->val > 0)
    {
        if (temp->exp == 0)
            printf("%d", temp->val);
        else
            printf("%dx^%d", temp->val, temp->exp);
    }
}