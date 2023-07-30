
#include <iostream>
using namespace std;
#include <cstdlib>

template <typename T>
class Sorter {
   private:
      int *array; 
      //T *array; 
      unsigned int numElements;
      unsigned int capacity;

      void swap(unsigned int i, unsigned int j);
      int quickSortA(int, int);
      void quickSortB(int, int);
      void mergeSortA(int, int, int);
      void mergeSortB(int, int);

  public:
      Sorter();
      Sorter(unsigned int initialCapacity);
      ~Sorter();

      void clear(); 
      bool insert(T value); 

      // Make sure the array contains at least newCapacity elements.
      // If not, grow it to that size and copy in old values
      unsigned int makeSpace(unsigned int newCapacity); 

      // Show the first n elements, k per line using << 
      void show(unsigned int n, int k); 

      // "Shuffle" the array elements
      void shuffle(); 

      void insertionSort();
      void quickSort();
      void mergeSort();
      void bubbleSort();
      void selectionSort();

      void reverseBubbleSort();

      void heapSort();
      void heapHelper(int, int);

      bool binarySearch(T val);
      int binarySearch(int l, int r, T val);
      bool linearSearch(T val);
};

#include "Sorter.cpp"
