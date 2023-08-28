#include <stdio.h>
int binarySearchIterative(int arr[], int size, int key) {
    int l = 0;
    int h = size - 1;

    while (l <= h) {
        int mid = l + (h-l) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            l = mid + 1;
        else
            h= mid - 1;
    }
    return -1; 
}

int binarySearchRecursive(int arr[], int l, int h, int key) {
    if (l<= h) {
        int mid = l + (h-l) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            return binarySearchRecursive(arr, mid + 1, h, key);
        else
            return binarySearchRecursive(arr, l, mid - 1, key);
    }
    return -1;
}

int main() {
    int choice, size, key;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key element to search: ");
    scanf("%d", &key);

    printf("\nSearch Menu:\n");
    printf("1. Binary Search with Iteration\n");
    printf("2. Binary Search with Recursion\n");
    printf("Enter your choice 1/2: ");
    scanf("%d", &choice);

    int result;

    switch (choice) {
        case 1:
            result = binarySearchIterative(arr, size, key);
            break;
        case 2:
            result = binarySearchRecursive(arr, 0, size - 1, key);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found in the array\n",key);
    return 0;
}

