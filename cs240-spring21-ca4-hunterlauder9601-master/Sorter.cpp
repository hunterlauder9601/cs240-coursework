#include <iostream>

using namespace std;

#include <assert.h>
#include "Ticker.h"

Ticker ticker;

template<class T>
void Sorter<T>::swap(unsigned int i, unsigned int j) {
    T tmp;
    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    return;
}

template<class T>
Sorter<T>::Sorter() {
    numElements = 0;
    capacity = 0;
    array = nullptr;
}

template<class T>
Sorter<T>::Sorter(unsigned int initialCapacity) {
    assert(initialCapacity > 0);
    capacity = initialCapacity;
    numElements = 0;
    array = new T[capacity];
}

template<class T>
unsigned int Sorter<T>::makeSpace(unsigned int newCapacity) {
    T *old;
    unsigned int i;
    if (newCapacity > capacity) {
        old = array;
        array = new T[newCapacity];
        for (i = 0; i < numElements; i++)
            array[i] = old[i];
        capacity = newCapacity;
        delete[] old;
    }
    return capacity;
}

template<class T>
void Sorter<T>::clear() {
    numElements = 0;
    return;
}

template<class T>
bool Sorter<T>::insert(T element) {
    if (numElements >= capacity)
        return false;
    array[numElements++] = element;
    return true;
}

template<class T>
Sorter<T>::~Sorter() {
    if (array) {
        delete[] array;
        numElements = 0;
    }
}

// Shuffle array elements
template<class T>
void Sorter<T>::shuffle() {
    unsigned int j;
    for (unsigned int i = 1; i < numElements; i++) {
        j = rand() % i;
        swap(i, j);
    }
}

// Show the first n elements, k per line, using << 
template<class T>
void Sorter<T>::show(unsigned int n, int k) {
    int toShow = ((n < numElements) ? n : capacity);
    for (int i = 0; i < toShow; i++) {
        if (!(i % k)) cout << endl;
        cout << array[i] << " ";
    }
    cout << endl;
}

// =============================================================
// SORTS BEGIN BELOW
// =============================================================

// -===================================================
// SORT 1   ? n2
// -===================================================
template<class T>
void Sorter<T>::insertionSort() {
    ticker.reset();
    unsigned int i, j;
    T val;
    for (i = 0; i < numElements; i++) {
        val = array[i];
        j = i;
        while ((j > 0) && (array[j - 1] > val)) {
            ticker.tick();
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = val;
    }
    return;
}

// -===================================================
// SORT 2  either merge or quick
// -===================================================
template<class T>
int Sorter<T>::quickSortA(int low, int high) {
    T p = array[high];
    int i = low;
    for (int j = low; j <= high; j++) {
        ticker.tick();
        if (array[j] < p) swap(i++, j);
    }
    swap(i, high);
    return i;
}

template<class T>
void Sorter<T>::quickSortB(int low, int high) {
    int spot;
    if (low < high) {
        spot = quickSortA(low, high);
        quickSortB(low, spot - 1);
        quickSortB(spot + 1, high);
    }
}

template<class T>
void Sorter<T>::quickSort() {
    ticker.reset();
    quickSortB(0, numElements - 1);
}

// -===================================================
// SORT 3
// -===================================================
template<class T>
void Sorter<T>::mergeSortA(int low, int high, int mid) {
    int sz = high - low + 1;
    assert(sz);
    T *tmpArray = new T[sz];
    assert(tmpArray);
    int i = low, j = mid + 1, k = 0;
    while ((i <= mid) && (j <= high)) {
        ticker.tick();
        if (array[i] < array[j])
            tmpArray[k++] = array[i++];
        else
            tmpArray[k++] = array[j++];
    }
    while (i <= mid) {
        ticker.tick();
        tmpArray[k++] = array[i++];
    }
    while (j <= high) {
        ticker.tick();
        tmpArray[k++] = array[j++];
    }
    for (k = 0; k < sz; k++)
        array[low + k] = tmpArray[k];
    delete[] tmpArray;
}

template<class T>
void Sorter<T>::mergeSortB(int low, int high) {
    unsigned int spot;
    if (low < high) {
        spot = (low + high) / 2;
        mergeSortB(low, spot);
        mergeSortB(spot + 1, high);
        mergeSortA(low, high, spot);
    }
}

template<class T>
void Sorter<T>::mergeSort() {
    ticker.reset();
    mergeSortB(0, numElements - 1);
}

// -===================================================
// SORT 4
// -===================================================
template<class T>
void Sorter<T>::bubbleSort() {
    ticker.reset();
    int i, j;
    for (i = (numElements - 1); i >= 0; i--)
        for (j = 1; j <= i; j++) {
            ticker.tick();
            if (array[j - 1] > array[j])
                swap(j - 1, j);
        }
    return;
}

template<class T>
void Sorter<T>::reverseBubbleSort() {
    int i, j;
    for (i = (numElements - 1); i >= 0; i--)
        for (j = 1; j <= i; j++) {
            if (array[j - 1] < array[j])
                swap(j - 1, j);
        }
    return;
}

// -===================================================
// SORT 5
// -===================================================
template<class T>
void Sorter<T>::selectionSort() {
    ticker.reset();
    unsigned int min;
    for (unsigned int i = 0; i < numElements - 1; i++) {
        min = i;
        for (unsigned int j = i + 1; j < numElements; j++){
            ticker.tick();
            if (array[j] < array[min]) min = j;
        }
        swap(i, min);
    }
    return;
}

// -===================================================
// heapSort()
// -===================================================
template<class T>
void Sorter<T>::heapHelper(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest]) // if left is bigger than largest
        largest = left;

    if (right < n && array[right] > array[largest]) // if right is bigger than largest
        largest = right;

    // Swap and continue with recursion if root is not largest
    if (largest != i) {
        std::swap(array[i], array[largest]);
        heapHelper(n, largest);
    }
}
template<class T>
void Sorter<T>::heapSort()
{
    // instantiates max heap
    for (int i = numElements / 2 - 1; i >= 0; i--){
        heapHelper(numElements, i);
    }

    for (int i = numElements - 1; i >= 0; i--) {
        std::swap(array[0], array[i]);
        heapHelper(i, 0);
    }
}

// -===================================================
// binarySearch()
// -===================================================
template<class T>
bool Sorter<T>::binarySearch(T val) {
    ticker.reset();
    cout << "binarySearch()" << endl;
    if (binarySearch(0, numElements - 1, val) == -1) {
        cout << "Ticks: " << ticker.ticks() << endl;
        return false;
    } else {
        cout << "Ticks: " << ticker.ticks() << endl;
        return true;
    }
}

template<class T>
int Sorter<T>::binarySearch(int l, int r, T val) {
    //ticker.tick();
    if (r >= l) {
        ticker.tick();
        int mid = l + (r - l) / 2;

        if (array[mid] == val) {
            return mid;
        }

        if (array[mid] > val){
            return binarySearch(l, mid - 1, val);
        }

        return binarySearch(mid + 1, r, val);
    }
    return -1;
}

// -===================================================
// linearSearch()
// -===================================================
template<class T>
bool Sorter<T>::linearSearch(T val) {
    ticker.reset();
    cout << "linearSearch()" << endl;
    for (int i = 0; i < numElements; i++) {
        ticker.tick();
        if (array[i] == val) {
            cout << "Ticks: " << ticker.ticks() << endl;
            return true;
        }
    }
    cout << "Ticks: " << ticker.ticks() << endl;
    return false;
}

