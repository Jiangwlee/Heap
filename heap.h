#define OUT_OF_RANGE -1

class Heap {
  public:
    static void Init(int *array, int size) {mArray = array; mSize = size;}
    static void Display(void);

    // Get the index of left/right child
    static int  Left(int root) {return (2 * root + 1 >= mSize) ? OUT_OF_RANGE : (2 * root + 1);}
    static int  Right(int root) {return (2 * root + 2 >= mSize) ? OUT_OF_RANGE : (2 * root + 2);}
    static bool IsLeaf(int index) {return (Left(index) == OUT_OF_RANGE) && (Right(index) == OUT_OF_RANGE);}

    // Get the depth of this heap
    static int  Depth(void) {return DepthOfIndex(mSize - 1);}

    // Min heap function
    static void AdjustToMinHeap(int root);
    static int  MinChild(int index);
    static void CreateMinHeap(void);
    static void SortMinHeap(void);

  private:
    // Get the depth (start from root) of the node at index 
    static int  DepthOfIndex(int index);

    // Swap two elements
    static void Swap(int a, int b);

    // Create a min heap start from index
    static void CreateMinHeap(int root);

    // Get this node's parent's index
    static int  Parent(int index) {return (index - 1)/2;}
    
    // Every node has parent, except the root at position 0
    static bool HasParent(int index) {return (index > 0) ? true : false;}

  private:
    // This class would never be instantiation 
    Heap(){}
    static int * mArray; // points to the heap to be manipulate
    static int   mSize;
};
