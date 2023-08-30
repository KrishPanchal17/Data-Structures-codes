#include <stdio.h>
void bubble_sort(int a[], int n) {
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

int main() {
	int a[100],n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements of array: ");
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    printf("\n");
    bubble_sort(a, n);
    printf("Sorted array: %d",a);
    return 0;
}

