#ifndef _TICKER_H_
#define _TICKER_H_
class Ticker {
   private:
      long counter;
   public:
      Ticker() { counter = 0; }
      void tick() { counter++; }
      void reset() { counter=0; }
      long ticks() { return counter; }
};
#endif //_TICKER_H_
