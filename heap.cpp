#include <iostream>
#include <iomanip>
#include "heap.h"

using namespace std;

int Heap::mSize = 0;
int * Heap::mArray = NULL;

int Heap::DepthOfIndex(int index) {
  if (!HasParent(index)) {
    return 1;
  } else {
    // If this node has parent
    return 1 + DepthOfIndex(Parent(index));
  }
}

// Display the heap as follows
//          1
//     10      12
//   11  13  14  15
void Heap::Display(void) {
  const unsigned int num_width = 2;
  const unsigned int space_between_num = 2;
  const unsigned int depth = Depth();
  const unsigned int size  = 1 << (depth + 1);
  unsigned int * coordinates = new unsigned int[size];

  // Calculate the x-axis coordinates from the bottom to top
  for (int i = depth; i >= 0; --i) {
    // The index of nodes on layer i is [2^i - 1, 2^(i+1) - 2] 
    unsigned int low_idx = (1 << i) - 1;
    unsigned int high_idx = (1 << (i+1)) - 1;

    // Initialize the bottom layer
    if (i == depth) {
      for (int idx = low_idx; idx < high_idx; ++idx) {
        coordinates[idx] = 1 + (idx - low_idx) * 2;  // The bottom layer's x-axis are : 1 3 5 7 9 ...
      }
    } else {
      for (int idx = low_idx; idx < high_idx; ++idx) {
        unsigned int left_idx  = 2 * idx + 1;  // left child's index
        unsigned int right_idx = 2 * idx + 2;  // right child's index
        coordinates[idx] = (coordinates[left_idx] + coordinates[right_idx]) / 2;
      }
    }
  }

  cout << "---------------------------------------------" << endl;

  // Display the heap
  for (int i = 0; i < depth + 1; ++i) {
    unsigned int low_idx = (1 << i) - 1;
    unsigned int high_idx = (1 << (i+1)) - 1; 
    unsigned int pre_position = 0; // The position of previous node

    for (int j = low_idx; j < high_idx && j < mSize; ++j) {
      int position = coordinates[j]; // get the coordinates of current node 
      for (int k = pre_position; k < position - 1; ++k)
        cout << "  ";  // output two spaces for each point
      cout << setw(2) << setfill(' ') << mArray[j]; 
      pre_position = position;
    }

    cout << endl;
  }

  delete [] coordinates;
  return;
}

void Heap::AdjustToMinHeap(int root) {
  if (IsLeaf(root))
   return;

  // Get the index of min child
  int minChild = MinChild(root); 

  if (minChild == OUT_OF_RANGE)
    return;

  // Swap root and minChild
  if (mArray[minChild] < mArray[root])
    Swap(root, minChild);

  // Keep adjusting the minChild heap to min heap
  AdjustToMinHeap(minChild);
}

int Heap::MinChild(int root) {
  int left  = Left(root);
  int right = Right(root);

  if (OUT_OF_RANGE == right) {
    return left;
  } else {
    return mArray[left] < mArray[right] ? left : right; 
  }
}

void Heap::Swap(int a, int b) {
  mArray[a] = mArray[a] + mArray[b];
  mArray[b] = mArray[a] - mArray[b];
  mArray[a] = mArray[a] - mArray[b];
}

void Heap::CreateMinHeap(void) {
  // Convert this heap to min heap
  CreateMinHeap(0);
}

void Heap::CreateMinHeap(int root) {
  // Convert this heap to min heap
  if (IsLeaf(root))
    return;

  int left  = Left(root);
  int right = Right(root);

  if (right == OUT_OF_RANGE) {
    CreateMinHeap(left);
    // Compare left sub heap and root
    if (mArray[left] < mArray[root]) {
      Swap(left, root);
      AdjustToMinHeap(left);
    }
  } else {
    CreateMinHeap(left); 
    CreateMinHeap(right); 
    int minChild = MinChild(root);
    if (mArray[minChild] < mArray[root]) {
      Swap(minChild, root);
      AdjustToMinHeap(minChild);
    }
  }
}

// This function convert the min heap to a sorted array
// The biggest number is at head of the array. The smallest number is at the end
// of the array. Before executing this function, the heap should be a min heap.
void Heap::SortMinHeap(void) {
  int size = mSize;
  
  while (mSize > 1) {
    Swap(mSize - 1, 0);
    --mSize;
    AdjustToMinHeap(0); 
  } 

  mSize = size;

  cout << "The sorted array : ";

  for (int i = size - 1; i >= 0; --i)
    cout << mArray[i] << " ";

  cout << endl;
}
