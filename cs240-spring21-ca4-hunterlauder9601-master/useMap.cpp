#include <iostream>
#include <map>

using namespace std;

int main ()
{
   map<int,int> myMap;
   map<int, int>::iterator i;
   myMap[10] = 20;
   myMap[20] = 40;
   myMap[100] = 200;

   for (i = myMap.begin(); i != myMap.end(); i++)
      cout << i->first << " --> " << i->second << endl;
}
