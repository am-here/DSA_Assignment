/*
    data = {
        author: Harsh Baid,
        roll: BTech/CSE/2020/024,
    }
*/

#include <stdio.h>
#include <stdlib.h>

int binary_search();
int interpolation_search();

int binary_search(int A[], int n, int key)
{
    int l, u, mid, count, ans;
    l = 0, u = n - 1, count = 0, ans = A[0];
    while (l <= u)
    {
        count++;
        mid = (l + u) / 2;
        if (A[mid] == key)
        {
            ans = mid + 1;
            break;
        }
        else if (A[mid] > key)
            u = mid - 1;
        else
            l = mid + 1;
    }
    printf("Number of interations executed: %d\n", count);
    return ans;
}
int main()
{
    int A[100];
    int n, i, ch, key, x;
    do
    {
        printf("\n1. Binary Search\n2. Interpolation Search\nEnter your Choice: ");
        scanf("%d", &ch);
        printf("Enter size of the Array: ");
        scanf("%d", &n);
        printf("Please Intialize the array: ");
        for (i = 0; i < n; i++)
            scanf("%d", &A[i]);
        printf("Enter element to be searched: ");
        scanf("%d", &key);
        switch (ch)
        {
        case 1:
            x = binary_search(A, n, key);
            if (A[x - 1] == key)
                printf("Element found at position %d\n", x);
            else
                printf("Element not found\n");
            break;
        case 2:
            // interpolation_search();
            break;
        default:
            break;
        }
    } while (1);
    return 0;
}