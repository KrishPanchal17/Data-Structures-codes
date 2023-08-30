#include <stdio.h>   
int partition (int a[], int l, int h)  
{  
    int pivot=a[h]; // pivot element  
    int i=(l-1);  
    for (int j=l;j<=h-1;j++)  
    {  
        // If current element is smaller than the pivot  
        if (a[j]<pivot)  
        {  
            i++; // increment index of smaller element  
            int t=a[i];  
            a[i]=a[j];  
            a[j]=t;  
        }  
    }  
    int t=a[i+1];  
    a[i+1]=a[h];  
    a[h]=t;  
    return (i+1);  
}  
void quick_sort(int a[], int l, int h) 
{  
    if (l<h)  
    {  
        int p=partition(a,l,h);
        quick_sort(a, l, p - 1);  
        quick_sort(a, p + 1, h);  
    }  
}   
void printArr(int a[], int n)  
{  
    int i;  
    for (i=0;i<n;i++)  
        printf("%d\n", a[i]);  
}  
int main()  
{  
    int a[] = {74, 9, 489, 37, 82, 54, 84, 29, 17};  
    int n = sizeof(a)/sizeof(a[0]);  
    printf("Original array: \n");  
    printArr(a, n);  
    quick_sort(a, 0, n - 1);  
    printf("\nAfter sorting array elements are:\n");    
    printArr(a, n);  
      
    return 0;  
}

