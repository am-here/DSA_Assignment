/*
	data = {
		author: Harsh Baid,
		roll: BTech/CSE/2020/024,
	}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
void PUSH(char ch);
char POP();
void compute();
int PRE(char ch);
int ifoperators(char ch);

char STACK[100];
int top = -1;

int main()
{
    char s[100];
    int n;
    do
    {
        printf("\nEnter Infix Expression: ");
        gets(s);
        n = strlen(s);
        printf("\nConverted Postfix Expression: ");
        compute(s, n);
    } while (1);
    return 0;
}
int ifoperators(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '(' || ch == ')');
}
int PRE(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 2;
}
void compute(char s[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (ifoperators(s[i]) == 0)
            printf("%c", s[i]);
        else
        {
            if (s[i] == '(')
                PUSH(s[i]);
            else if (s[i] == ')')
                while (STACK[top] != '(')
                    printf("%c", POP());
            else
            {
                if (top == -1 || STACK[top] == '(')
                    PUSH(s[i]);
                else
                {
                    if (PRE(s[i]) > PRE(STACK[top]))
                        PUSH(s[i]);
                    else
                    {
                        while (top != -1)
                        {
                            if (STACK[top] == '(')
                                break;
                            printf("%c", POP());
                        }
                        PUSH(s[i]);
                    }
                }
            }
        }
    }
    for (i = top; i >= 0; i--)
        if (STACK[top] != '(' && STACK[top] != ')')
            printf("%c", POP());
        else
            top--;
}
void PUSH(char value)
{
    STACK[++top] = value;
}
char POP()
{
    return STACK[top--];
}