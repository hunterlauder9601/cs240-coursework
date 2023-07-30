#include "Ticker.h"
#include <iostream>

extern Ticker ticker;

void nlogn(int n) {
   for (int i=1; i <= n; i++)
      for (int j=1; j <= n; j *=2)
         ticker.tick();
   std::cout << "n: " << n << " nlogn() ticks: " << ticker.ticks() << std::endl;
   return;
}
