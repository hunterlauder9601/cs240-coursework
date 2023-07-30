#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>

#include "Sorter.h"
#include <map>

//#define DEFAULT_NUMVALUES 100
#define MAX_NUMVALUES 10000
#define MIN_NUMVALUES 1

Sorter<int> getSorterInit(unsigned int numValues);

int main (int argc, char **argv) {

///////////// play with map
    map<int,long> myMap;
    map<int, long>::iterator i;
    unsigned int growth = 5;

///////////////////////////////////////////////////////////////
    unsigned int numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.shuffle();
        s.insertionSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "insertionSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.shuffle();
        s.selectionSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "selectionSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.shuffle();
        s.bubbleSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "bubbleSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.shuffle();
        s.quickSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "quickSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.shuffle();
        s.mergeSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "mergeSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;







///////////////////////////////////////////////////////////////
// 3D
    cout << "///////////////////////////////////////////////\n3D Testing Stuff\nReverse Testing:\n";
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.reverseBubbleSort();
        s.insertionSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "insertionSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.reverseBubbleSort();
        s.selectionSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "selectionSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.reverseBubbleSort();
        s.bubbleSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "bubbleSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.reverseBubbleSort();
        s.quickSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "quickSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.reverseBubbleSort();
        s.mergeSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "mergeSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;












    cout << "\n\nAlready Sorted Testing:\n";
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.bubbleSort();
        ticker.reset();
        s.insertionSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "insertionSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.bubbleSort();
        ticker.reset();
        s.selectionSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "selectionSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.bubbleSort();
        ticker.reset();
        s.bubbleSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "bubbleSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.bubbleSort();
        ticker.reset();
        s.quickSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "quickSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;
/////////////////////////////////////////////////////
    numValues =10;
    myMap.clear();
    for (int i = 0 ; i < 5; i++) {
        ticker.reset();
        Sorter<int> s = getSorterInit(numValues);
        s.bubbleSort();
        ticker.reset();
        s.mergeSort();
        //cout << "Ticks: " << ticker.ticks() << endl;
        myMap[numValues] = ticker.ticks();
        numValues*=growth;
    }
    cout << "mergeSortMap " << endl;
    for (i = myMap.begin(); i != myMap.end(); i++)
        cout << i->first << " --> " << i->second << endl;





//   s.shuffle();
//   cout << "Shuffled: ";
//   s.show(25, 10);
//
//   s.quickSort();
//   cout << "Quick Sorted: ";
//   s.show(numValues, 100);
//   cout << "Ticks: " << ticker.ticks() << endl;
//
//   s.shuffle();
//   cout << "Shuffled: ";
//   s.show(25, 10);
//
//   s.mergeSort();
//   cout << "Merge Sorted: ";
//   s.show(numValues, 100);

//
//   s.shuffle();
//   cout << "Shuffled: ";
//   s.show(25, 10);
//
//    s.bubbleSort();
//   cout << "Sorted: ";
//   s.show(25, 10);
//
//   s.shuffle();
//   cout << "Shuffled: ";
//   s.show(25, 10);
//
//    s.selectionSort();
//   cout << "Sorted: ";
//   s.show(25, 10);
//
//   s.shuffle();
//   cout << "Shuffled: ";
//    s.show(DEFAULT_NUMVALUES, 100);

//    s.insertionSort();
//
//Testing searches

    Sorter<int> s = getSorterInit(100);
    s.shuffle();
    s.show(numValues, 100);
    s.heapSort();
    s.show(numValues, 100);
    cout << "Value FROM LINEAR SERCH" << s.linearSearch(7835) << endl;
   cout << "Value FROM LINEAR SERCH" << s.linearSearch(9) << endl;
   cout << "Value FROM LINEAR SERCH" << s.linearSearch(3158) << endl;

   cout << "Value FROM BINARY SERCH" << s.binarySearch(7835) << endl;
   cout << "Value FROM BINARY SERCH" << s.binarySearch(9) << endl;
   cout << "Value FROM BINARY SERCH" << s.binarySearch(3158) << endl;

}

Sorter<int> getSorterInit(unsigned int numValues) {
    cout << endl << "Generating " << numValues << " values for sorting." << endl;
    Sorter<int> s;
    s.makeSpace(numValues);

    srand(time(NULL)); // use this line for pseudo-random numbers
//    srand(23);      // use this line for deterministic "random" numbers

    for (unsigned int i=0; i < numValues; i++) {
       unsigned int value = rand() % MAX_NUMVALUES;
       s.insert(value);
    }
    return s;
}
