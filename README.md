This is a practice. I implement heap algorithms including heap adjusting,
sorting and creation.

1. Heap adjusting
   Heap adjusting adjusts the root's position and puts it to a proper position
in the heap. The root's left sub tree and right sub tree are heaps. But the root
itself does not make the tree a heap. This algorithm puts the root to a proper
position to make the whole tree a heap.

==> The tree before adjusting
               10
             1    2
           3   4
==> The tree after adjusting
               1 
             3    2
           10  4

2. Heap sorting
   Heap sorting means output the elements in a heap by order. Take min heap for
example, it outputs the heap by following steps:
   --> output the root of the tree
   --> swap the root and the last element of the heap and decrease the heap size
by 1
   --> adjust the tree to min heap
   --> go back to first step

3. Heap creation
   Heap creation means create a heap from an array.

-----------------------
Compile:
make

Run:
./heap
