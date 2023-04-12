#include <iostream>
#include "quicksort.cpp"

int main() {
  int arr[10] = {31, 2, 4, 40, 134, 13, 81, 822, 0, 99};
  quicksort(arr, 0, 9);
  return 0;
}

