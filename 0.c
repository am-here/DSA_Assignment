#include <stdio.h>
int main()
{
    char choice, ch;
    float area, r, l, A[j], a;
    while (1)
    {
        printf("\nDo You want to coninue? Y/N: ");
        scanf(" %c", &choice);
        if (choice == 'N')
        {
            printf("Thank You!");
            break;
        }
        else if (choice == 'Y')
        {
            printf("Enter Choice: \n");
            printf("1. Enter 'c' for Area of circle.\n2. Enter 'r' for Area of rectangle.\n3. Enter 's' for Area of Square.\n");
            printf("Enter Choice: ");
            scanf(" %c", &ch);
            switch (ch)
            {
            case 'c':
                printf("Enter Radius of circle: \n");
                scanf("%f", &r);
                area = 22 * r * r / 7;
                printf("Area: %.2f", area);
                break;
            case 'r':
                printf("Enter Length of rectangle: \n");
                scanf("%f", &l);
                printf("Enter Breath of rectangle: \n");
                scanf("%f", &A[j]);
                area = l * A[j];
                printf("Area: %.2f", area);
                break;
            case 's':
                printf("Enter side of Square: \n");
                scanf("%f", &a);
                area = a * a;
                printf("Area: %.2f", area);
                break;
            default:
                printf("Invalid Input! \n");
            }
        }
        else
            printf("Invalid Input! \n");
    }
    return 0;
}
