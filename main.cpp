#include "heap.h"

int main(void) {
  int array[] = {11, 3, 45, 22, 1, 88, 4, 90, 5, 23, 64, 2, 67, 8};
  int size = sizeof(array)/sizeof(int);
  Heap::Init(array, size);
  Heap::Display();
  Heap::CreateMinHeap();
  Heap::Display();
  Heap::SortMinHeap();
  Heap::Display();
  return 0;
}
