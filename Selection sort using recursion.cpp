#include <stdio.h>
void selection_sort(int a[], int n) {
    for (int i=0;i<n-1;i++){
        int smallest_element=i;
        for (int j=i+1;j<n;j++) {
            if (a[j]<a[smallest_element]){
                smallest_element=j;
            }
        }
        int t=a[i];
        a[i]=a[smallest_element];
        a[smallest_element]=t;
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
    selection_sort(a, n);
    printf("Sorted array: %d",a);
    return 0;
}

