#include <stdio.h> 
#define SIZE 100
int main()
{
	int arr[SIZE];
	int n,i,num,pos,flag=0;
	char choice,ch;
	printf("Enter size of the Array: ");
	scanf("%d", &n);
	printf("Please Intialize the array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
    while(1)
    {
        printf("\nDo You want to coninue? Y/N: ");
        scanf(" %c", &choice);
        if(choice == 'N')
        {
            printf("Thank You!");
            break;
        }
        else if(choice == 'Y')	
        {
            printf("Enter Choice from: \n");
            printf("a) Insert an element at the any position of the array.\nb) Delete an element from a given position of the array.\nc) Replace the element of a given position with another number.\nd) Search if an element exists in the list.\ne) Display the array elements.\n");
            printf("Your Choice: ");
            scanf(" %c", &ch);
            switch(ch){
                case 'a':
                	printf("Enter element to be added: ");
                	scanf("%d", &num);
                	printf("Enter the position where the number should be added: ");
                	scanf("%d", &pos);
    				n++;
    				for (i = n-1; i >= pos; i--)
        			{
        				arr[i] = arr[i - 1];
					}
    				arr[pos - 1] = num;
                    break;
                case 'b': 
                	printf("Enter the position of the element which should be deleted from the array: ");
                	scanf("%d", &pos);
    				for (i = pos-1; i <n; i++)
        			{
        				arr[i] = arr[i+1];
					}
    				n--;
                    break;
                case 'c':
                	printf("Enter the position from which the number should be replaced: ");
                	scanf("%d", &pos);
                	printf("Enter element to be placed instead: ");
                	scanf("%d", &num);
    				arr[pos - 1] = num;
                	break;
                case 'd':
                	printf("Enter element to be searched: ");
                	scanf("%d", &num);
                	for (i = 0; i < n; i++)
                	{
                		if (arr[i] == num)
            			{
            				flag = 1;
            				break;
						}
					}
					if(flag == 1)
						printf("Element found at position: %d\n", i+1);
					else
						printf("Element not found!\n");
					flag = 0;
                	break;
                case 'e':
                    printf("Array: ");
					for(i=0;i<n;i++)
					{
						printf("%d ",arr[i]);
					}
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

