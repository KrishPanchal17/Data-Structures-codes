#include<stdio.h>
int iterativeBinarySearch(int array[], int l, int h, int key){
   while (l<=h){
      int middle = l + (h-l)/2;
      if (array[middle] == key)
         return middle;
      if (array[middle] < key)
        l= middle + 1;
      else
        h= middle - 1;
   }
   return -1;
}
int main(void){
   int array[] = {5,6,7,8,9,10};
   int n = 7;
   int key= 8;
   int found_index = iterativeBinarySearch(array, 0, n-1, key);
   if(found_index == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Element found at index : %d",found_index);
   }
   return 0;
}
