#include <stdio.h>

// Iterative linear search function
int linearSearchIterative(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Recursive linear search function
int linearSearchRecursive(int arr[], int n, int x, int i) {
    if (i < n) {
        if (arr[i] == x)
            return i;
        return linearSearchRecursive(arr, n, x, i + 1);
    }
    return -1;
}

int main() {
    int arr[] = {2,3,4,10,40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int iterative_result = linearSearchIterative(arr, n, x);
    int recursive_result = linearSearchRecursive(arr, n, x, 0);
    printf("Element %d found at index %d in iterative search.\n", x, iterative_result);
    printf("Element %d found at index %d in recursive search.\n", x, recursive_result);
    return 0;
}