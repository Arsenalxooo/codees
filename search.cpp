#include <stdio.h>
#include <conio.h>


void linearSearch() 
{
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i, num;

    printf("\nEnter the number to be searched: ");
    scanf("%d", &num);

    for (i = 0; i < 10; i++) 
	{
        if (arr[i] == num)
            break;
    }

    if (i == 10)
        printf("Number not present.\n");
    else
        printf("Number found at index %d (position %d)\n", i, i + 1);
}


void binarySearch() 
{
    int arr[10] = {2, 3, 9, 11, 13, 17, 27, 57, 90, 98};
    int mid, lower = 0, upper = 9, num, flag = -1;

    printf("\nEnter the element to be searched: ");
    scanf("%d", &num);

    while (lower <= upper) 
	{
        mid = (upper + lower) / 2;

        if (arr[mid] == num) 
		{
            printf("The number is at location %d (position %d)\n", mid, mid + 1);
            flag = 0;
            break;
        }

        if (arr[mid] > num)
            upper = mid - 1;
        else
            lower = mid + 1;
    }

    if (flag == -1)
        printf("Number not present.\n");
}


int main() 
{
    int choice;

    do 
	{
        printf("\n===== SEARCH MENU =====\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                linearSearch();
                break;

            case 2:
                binarySearch();
                break;

            case 3:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}

