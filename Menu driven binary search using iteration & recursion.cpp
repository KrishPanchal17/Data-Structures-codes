#include<stdio.h>
//using recursion
int bsrecursive(int a[], int l, int h, int key) {
    if (l<=h) {
        int mid=l+(h-l)/2;
        if (a[mid]==key)
            return mid;
        else if (a[mid] < key)
            return bsrecursive(a, mid + 1, h, key);
        else
            return bsrecursive(a, l, mid - 1, key);
    }
    return -1;
}
//using iteration
int bsiterative(int a[], int n, int key) {
    int l=0;
    int h=n-1;
    while (l<=h) {
        int mid=l+(h-l)/2;
        if (a[mid]==key)
            return mid;
        else if(a[mid]<key)
            l=mid+1;
        else
            h= mid - 1;
    }
    return -1; 
}
//main function
int main() {
    int choice, n, key;
    printf("Enter the no.of elements of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("Enter the element you want to search: ");
    scanf("%d", &key);
    printf("1 Binary Search with Iteration\n");
    printf("2 Binary Search with Recursion\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    int res;
//switch case
    switch(choice){
        case 1:
            res=bsiterative(a, n, key);
            break;
        case 2:
            res= bsrecursive(a, 0, n-1, key);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
    if (res!=-1)
        printf("Element %d found at index %d\n", key, res);
    else
        printf("Element %d not found in the array\n",key);
    return 0;
}
