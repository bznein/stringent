#include "stringent.h"
#include <iostream>

using namespace std;
int main()
{
  auto  a=stringent::occurrences("aasdaser");
  for ( auto const&  [key, val]: a)
    {
      cout << key << ", " << val << endl;
    }
}
