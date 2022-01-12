/*
    data = {
        author: Harsh Baid,
        roll: BTech/CSE/2020/024,
    }
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap();
void bubble_sort();
void selection_sort();
void insertion_sort();
void merge();
void merge_sort();
int random();
int partition();
void quick_sort();
void display();

void swap(int *a, int *b)
{
    int x = *a, y = *b;
    x = x + y;
    y = x - y;
    x = x - y;
    *a = x, *b = y;
}
void bubble_sort(int A[], int n)
{
    int i, j;
    int check = 1;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                check = 0;
            }
        }
        if (check == 1)
            return;
        check = 1;
    }
}
void selection_sort(int A[], int n)
{
    int i, j;
    int pos = 0;
    for (i = 0; i < n - 1; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
            if (A[pos] > A[j])
                pos = j;
        swap(&A[i], &A[pos]);
    }
}
void insertion_sort(int A[], int n)
{
    int i, j, pos, val;
    for (i = 1; i < n; i++)
    {
        pos = i - 1;
        val = A[i];
        while (pos >= 0 && val < A[pos])
        {
            A[pos + 1] = A[pos];
            pos--;
        }
        A[pos + 1] = val;
    }
}
void merge(int A[], int l, int mid, int r)
{
    int x = l;
    int M[100];
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
        if (A[i] < A[j])
            M[k++] = A[i++];
        else
            M[k++] = A[j++];
    while (i <= mid)
        M[k++] = A[i++];
    while (j <= r)
        M[k++] = A[j++];
    for (; x <= r; x++)
        A[x] = M[x];
}
void mergeSort(int A[], int l, int r)
{
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, r);
        merge(A, l, mid, r);
    }
    return;
}
int random(int l, int r)
{
    return rand() % (r - l + 1) + l;
}
int partition(int A[], int l, int r)
{
    int ind = random(l, r);
    int pivot = A[ind];
    swap(&A[ind], &A[r]);
    int i = l - 1, j = r;
    while (i <= j)
    {
        while (A[++i] < pivot)
            ;
        while (A[--j] > pivot)
            ;
        if (i < j)
            swap(&A[i], &A[j]);
    }
    swap(&A[i], &A[r]);
    return i;
}
void quick_sort(int A[], int l, int r)
{
    if (l < r)
    {
        int x = partition(A, l, r);
        quick_sort(A, l, x - 1);
        quick_sort(A, x + 1, r);
    }
    return;
}
void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    int A[100];
    int n, i, ch;
    do
    {
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\nEnter your Choice: ");
        scanf("%d", &ch);
        printf("Enter size of the Array: ");
        scanf("%d", &n);
        while (n >= 99)
        {
            printf("Invalid Input! Try again\n");
            printf("Enter size of the Array: ");
            scanf("%d", &n);
        }
        printf("Please Intialize the array: ");
        for (i = 0; i < n; i++)
            scanf("%d", &A[i]);
        switch (ch)
        {
        case 1:
            bubble_sort(A, n);
            break;
        case 2:
            selection_sort(A, n);
            break;
        case 3:
            insertion_sort(A, n);
            break;
        case 4:
            mergeSort(A, 0, n - 1);
            break;
        case 5:
            quick_sort(A, 0, n - 1);
            break;
        default:
            printf("Invalid Input!");
        }
        display(A, n);
        printf("Do you want to continue? (Y/N):");
        scanf(" %c", &ch);
        if (ch == 'N')
            break;
    } while (1);
    return 0;
}
