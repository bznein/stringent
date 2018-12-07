#include "stringent.h"
#include <iostream>

using namespace std;
int main()
{
  auto  a=std::string("1,2 3&&4");

  for(auto i: stringent::explode<>(a,", &",[](string s){return (s);}))
    cout <<i << endl;
}
