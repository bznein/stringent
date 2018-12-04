#include <string>
#include <sstream>
#include <vector>
#include <iostream>

namespace stringent
{
  decltype(auto) explode(const  std::string& s, char c)
  {
    auto res=std::vector<std::string>();
    res.reserve(s.size());
    int last_index=0,pos;
    do{
      pos=s.find(c,last_index);
      res.emplace_back(s.substr(last_index,pos));
      last_index=pos+1;
    }
    while(pos!=std::string::npos);
    return res;
  }
}
