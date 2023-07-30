#include "Ticker.h"
#include <iostream>

extern void nlogn(int);

Ticker ticker;

int main() {
   int n = 1000000;

   // Use a global variable ticker within the same file
   for (int i=1; i < n; i *=2)
      ticker.tick();
   std::cout << "n: " << n << " Log n ticks: " << ticker.ticks() << std::endl;

   // Use a global variable ticker in some other file
   ticker.reset();
   nlogn(n);
}
