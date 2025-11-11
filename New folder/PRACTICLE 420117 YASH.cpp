#include <stdio.h>

int linearSearch(int arr[], int target, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int target, int size) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[5] = {2, 4, 6, 8, 10};  // already sorted for binary search
    int target;
    int size = 5;  // manually set size

    printf("Enter a number to search: ");
    scanf("%d", &target);

    int lin = linearSearch(arr, target, size);
    if (lin != -1)
        printf("Linear search: found at index %d\n", lin);
    else
        printf("Linear search: not found\n");

    int bin = binarySearch(arr, target, size);
    if (bin != -1)
        printf("Binary search: found at index %d\n", bin);
    else
        printf("Binary search: not found\n");

    return 0;
}
