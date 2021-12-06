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
void PUSH(int ch);
int POP();
int calculator(int a, int b, char c);
void compute();
int ifoperators(char ch);

int STACK[100];
int top = -1;

int main()
{
    char s[100];
    int n;
    do
    {
        printf("\nEnter Postfix Expression: ");
        gets(s);
        n = strlen(s);
        compute(s, n);
    } while (1);
    return 0;
}
int calculator(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else if (c == '/')
        return a / b;
    else
        return a % b;
}
int ifoperators(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}
void compute(char s[], int n)
{
    int i;
    int a, b;
    for (i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            continue;
        if (ifoperators(s[i]))
        {
            b = POP();
            a = POP();
            PUSH(calculator(a, b, s[i]));
        }
        else
        {
            PUSH(s[i] - 48);
        }
    }
    printf("Answer: %d", POP());
}
void PUSH(int value)
{
    STACK[++top] = value;
}
int POP()
{
    return STACK[top--];
}