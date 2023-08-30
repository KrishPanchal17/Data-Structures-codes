#include <stdio.h>  
void merge_sort(int a[], int l, int mid, int h)    
{    
    int i, j, k;  
    int n1=mid-l+1;    
    int n2=h-mid;    
      
    int LeftArray[n1], RightArray[n2];   
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[l+ i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
    i = 0;
    j = 0;  
    k = l;
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
void merge_sort(int a[], int l, int h)  
{  
    if (l<h)   
    {  
        int mid =(l+h)/2;  
        merge_sort(a, l, mid);  
        merge_sort(a, mid + 1, h);  
        merge_sort(a, l, mid, h);  
    }  
}    
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  
int main()  
{  
    int a[] = {98,87,54,3,689,54,67,3409,349};  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Original array: \n");  
    printArray(a, n);  
    merge_sort(a, 0, n-1);  
    printf("After sorting array :\n");  
    printArray(a, n);  
    return 0;  
}
