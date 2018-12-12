#include "stringent.h"
#include <iostream>

using namespace std;
int main()
{
  auto  a=std::string("1,2 3&&4");
  std::vector<int> g= stringent::explode<>(a,", &",[](string s){return stoi(s);});
  for (auto i:g)
    cout <<i << endl;
}
