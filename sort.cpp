#include <stdio.h>


void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void display(int arr[], int n);

int main() 
{
    int arr[10];
    int n, choice;

    printf("Enter how many elements (max 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) 
	{
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1) 
	{
        printf("\n=== Sorting Menu ===\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                bubbleSort(arr, n);
                printf("Array sorted using Bubble Sort.\n");
                break;
            case 2:
                selectionSort(arr, n);
                printf("Array sorted using Selection Sort.\n");
                break;
            case 3:
                insertionSort(arr, n);
                printf("Array sorted using Insertion Sort.\n");
                break;
            case 4:
                display(arr, n);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


void bubbleSort(int arr[], int n) 
{
    int temp;
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int arr[], int n) 
{
    int min, temp;
    for (int i = 0; i < n - 1; i++) 
	{
        min = i;
        for (int j = i + 1; j < n; j++) 
		{
            if (arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


void insertionSort(int arr[], int n) 
{
    int key, j;
    for (int i = 1; i < n; i++) 
	{
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void display(int arr[], int n) 
{
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

