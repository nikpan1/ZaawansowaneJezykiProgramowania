#include <iostream>
#include <type_traits>
#include <utility>

using namespace std;

void printArray(int *arr, int size) {
  for(int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int partition(int *arr, int _first, int _last) {
  int v = _first;
  int l = _first + 1;
  int r = _last;
  
  while(l < r) { 
    while(arr[l] < arr[v]) l ++;
    while(arr[r] > arr[v]) r --;
    if (l < r) swap(arr[l], arr[r]);
  }
  
  swap(arr[v], arr[r]); // to jest zbędne jeżeli zwraca r  lol
  return r;
}

int quicksort(int *arr, int l, int r) {
  printArray(arr, r);
  int j = partition(arr, l, r);
  if (j - 1> l) quicksort(arr, l, j - 1);
  if (r > j + 1) quicksort(arr, j + 1, r);
  return -1;
}


