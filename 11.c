/*
    data = {
        author: Harsh Baid,
        roll: BTech/CSE/2020/024,
    }
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct sll
{
    int data;
    struct sll *left;
    struct sll *right;
} node;
node *insert(node *root, int x)
{
    if (root == NULL)
    {
        node *NODE = (node *)malloc(sizeof(node));
        NODE->data = x;
        NODE->right = NULL;
        NODE->left = NULL;
        return NODE;
    }
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main()
{
    int i, n, x;
    char ch;
    node *root = NULL;
    do
    {
        printf("Enter number of elements you want to add: ");
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            printf("Enter number: ");
            scanf("%d", &x);
            root = insert(root, x);
        }
        printf("\nInorder: ");
        inorder(root);
        printf("\n\nPreorder: ");
        preorder(root);
        printf("\n\nPostorder: ");
        postorder(root);
        printf("\n\nDo you want to continue? (Y/N): ");
        scanf(" %c", &ch);
        while (ch != 'Y' && ch != 'N')
        {
            printf("Invalid Input!\nDo you want to continue? (Y/N): ");
            scanf(" %c", &ch);
        }
    } while (ch == 'Y');
    printf("\n****Thank You****\n\n");
    return 0;
}
