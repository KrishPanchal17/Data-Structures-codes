#include <stdio.h>  
void insertion_sort(int a[], int n) 
{  
    int i, j, temp;  
    for (i=1;i<n;i++) {  
        temp = a[i];  
        j=i-1;  
        while(j>=0 && temp <= a[j])
        {    
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = temp;    
    }  
}  
void printArr(int a[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
  //main code
int main()  
{  
    int a[] = { 12, 31, 25, 8, 32, 17 };  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Original array: \n");  
    printArr(a, n);  
    insertion_sort(a, n);  
    printf("\nAfter sorting array : \n");    
    printArr(a, n);  
    return 0;  
} 
