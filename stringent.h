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

  char swapCase(char c)
  {
    if (std::islower(c))
      return std::toupper(c);
    return std::tolower(c);
  }


  declype(auto) removeOccurrencesCaseInsensitive(const string &s, char c)
  {
    auto c2=swapCase(c);
    stringstream ss;

    for (auto elem:s)
      {
        if (elem != c && elem != c2)
          ss << elem;
      }
    return ss.str();
  }

  decltype(auto) removeOccurrences(const string &s, char c)
  {
    stringstream ss;

    for (auto elem:s)
      {
        if (elem != c)
          ss << elem;
      }
    return ss.str();
  }

  
}
