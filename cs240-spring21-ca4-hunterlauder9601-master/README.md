Part 1: Know Your Sorts

1A: Build and run CA4.cpp with:
g++ CA4.cpp -o CA4

1B: The templated Sorter class contains 5 different sorts. Three of them are a single function, two of them use three functions.
These are the five main sorts we have talked about in class.  Figure out which one is which, and rename all of the functions
for the five sorts with meaningful function names.  Change the signatures (in Sorter.h) and the calls to the functions
(in Sorter.cpp and CA4.cpp) to reflect the new names, so that the code compiles and runs again.

Part 2: Simple Searches

2A: Fill in the code for
bool Sorter::linearSearch(T val);
and add some "test code" to show that it works, in CA4.cpp. The function should return true if val is found, false if not.

2B: Fill in the code for
bool Sorter::binarySearch(T val);
and add some "test code" to show that it works, in CA4.cpp. The function should return true if val is found, false if not.

Your binary search code may assume that the array is sorted (but if you want it to work, make sure to only call it only on a sorted array).

Part 3: Operation Counting

3A: Take a look at Ticker.h, useTicker.cpp, and nlogn.cpp.  Ticker is a class that can be used to make a rough 
count of basic operations within your program.  If you place it in the right spot, you can use it to get 
a feel for the runtime complexity of functions and code.  Notice where we place the ticker for the nlogn()
function, and for the loop in useTicker.cpp.  We're only adding it to the "critical" region of code.
For nested loops, that's within the inner-most loop.  For recursive functions, you can add the ticker at 
the top of the recursive function to accurately consider the calls, but if each call takes more than constant
time, you may need to add the ticker elsewhere to get an accurate picture of operation counts.

3B: 
Use the ticker to assess the operations required of the 2 searches, by having the functions "tick" in their
critical regions.  After you get things working, you should make arrays of several sizes, and
much larger than 10 values. Do some pencil and paper calculations to confirm that the ticker counts make sense.

3C: 
Use the ticker to assess the operations required of the 5 sorts, as you did for part 3B.  The 5 sorts in this 
exercise are "comparison based" sorts. The runtime complexities we discussed bound the number of "basic operations",
as usual, but also the number of comparisons. So if you have the ticker tick once per comparison that the
algorithm must make, you will get a accurate picture of the runtime complexity.

Write code that will report numbers in tables of two columns, for N and Ticks. Each table eventually
will have 5 (or more) rows, one for each of 5 different values of N that you select to characterize the function behavior.
You could store the <N, Ticks> pairs in a C++ map; we've included file useMap.cpp to show the very basic
bare bones use of a C++ map.

The "test code" in CA4.cpp is all stuffed back to back in main(). Feel free to organize the tests better, 
perhaps by separating them into separate functions in CA4.cpp, or even in a separate source code file.

3D: Investigate the behavior of the search and sort functions on sorted arrays and arrays sorted in reverse order. 
Can you find quantitative evidence that sorted arrays are the best and/or worst case for some of the sorts?

Part 4: Writeup

Prepare a writeup of your findings, addressing each of the items above (1A through 3D), labeled by Part and
sub-part (e.g. 3B).  You will submit this report along with all of the code changes you make and the new code
that you write. You may graph results to show function growth, or just include the tables (neatly formatted please). 
Please include some calculated values for comparison.  For example, if you report that evidence shows that 
a sort is O(n log n), you may want to include the actual value of f(n) = n log n for the different values
of n that you choose.

Part 5: Heap Sort

Implement Heap Sort on the Sorter class. You have everything you need for this in the lecture
slides! Should be a straightforward implementation... remember though that C++ arrays start with 0, and
the algorithms I showed you start with 1.  Follow the design for the other sorts, with the public heap
sort function taking no parameters, and other functions that don't belong in the interface defined as
private.
