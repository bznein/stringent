#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
namespace stringent
{
  decltype(auto) explode(const  std::string& s, char c)
  {
    auto res=std::vector<std::string>();
    res.reserve(s.size());
    int last_index=0,pos;
    do{
      pos=s.find(c,last_index);
      res.emplace_back(s.substr(last_index,pos-last_index));
      last_index=pos+1;
    }
    while(pos!=std::string::npos);
    return res;
  }

  decltype(auto) occurrences(const std::string& s, char c)
    {
      return std::count_if(s.begin(),s.end(), [c](char e){return c==e;});
    }

  decltype(auto) occurrences(const std::string& s)
    {
      std::map<char,unsigned int> occurr;
      for (auto & ch: s)
        {
          if (occurr.find(ch)==occurr.end())
            occurr[ch]=occurrences(s,ch);
        }
      return occurr;
    }
}
