#include<stdio.h>

int main() {
  int arr[20], size, key, i, index;
  int countKey = 0; 
  printf("Number of elements in the list: ");
  scanf("%d", &size);

  printf("Enter elements of the list: ");
  for (i = 0; i < size; i++)
    scanf("%d", &arr[i]);

  printf("Enter the element to search ie. key element: ");
  scanf("%d", &key);

  for (index = 0; index < size; index++) {
    if (arr[index] == key) { 
      printf("Key element found at index %d\n", index);
      countKey++;
    }
  }
  if (countKey == 0) 
    printf("Key element not found");
  else
    printf("Key element is present %d times in the array.\n", countKey);
  return 0;
}

