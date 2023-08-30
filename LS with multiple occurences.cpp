#include<stdio.h>
int main() {
  int a[20], key, n,i,ind;
  int count= 0; 
  printf("size of array:");  //size of array
  scanf("%d", &n);
  printf("Enter elements of array:");  //elements of your choice in array
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
  }
  printf("Enter the element you want to search: ");
  scanf("%d", &key);
  for (ind=0;ind<n;ind++){
    if(a[ind]==key){ 
    printf("element found at index %d\n", ind);  //index of element
    count++;
    }
  }
  if(count==0){
    printf("Element you want to search is not present");
}
  else{
    printf("element you want to search is present %d times in array\n", count); 
  }return 0;
}

