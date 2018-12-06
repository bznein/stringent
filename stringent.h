#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <type_traits>
#include <functional>

namespace stringent
{
  namespace constants
  {
    auto default_function=[](std::string s){return s;};
  }

  template<typename F=decltype(constants::default_function), typename R = typename std::result_of<F&(std::string)>::type>
    std::vector<R> explode(const  std::string& s, const std::string& c,F f=constants::default_function)
    {

      auto res=std::vector<R>();
      res.reserve(s.size());
      int last_index=0;
      size_t pos;
      do{
        int closest_index=s.size();
        for (auto ch: c)
          {
            if (auto p=s.find(ch,last_index); p!=std::string::npos && p<closest_index)
              closest_index=p;
          }
        if (closest_index==s.size())
          pos=std::string::npos;
        else
          pos=closest_index;
        if (pos!=last_index)
             res.emplace_back(f(s.substr(last_index,pos-last_index)));
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

  namespace chars
  {
    char swapCase(char c)
    {
      if (std::islower(c))
        return std::toupper(c);
      return std::tolower(c);
    }
  }


  decltype(auto) removeOccurrencesCaseInsensitive(const std::string &s, char c)
  {
    auto c2=chars::swapCase(c);
    std::stringstream ss;

    for (auto elem:s)
      {
        if (elem != c && elem != c2)
          ss << elem;
      }
    return ss.str();
  }

  decltype(auto) removeOccurrences(const std::string &s, char c)
  {
    std::stringstream ss;

    for (auto elem:s)
      {
        if (elem != c)
          ss << elem;
      }
    return ss.str();
  }

  decltype(auto) reverse(const std::string &s)
    {
      return std::string(s.rbegin(),s.rend());
    }
  
}
