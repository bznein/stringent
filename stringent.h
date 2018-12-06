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

  namespace chars
  {
    char swapCase(char c)
    {
      if (std::islower(c))
        return std::toupper(c);
      return std::tolower(c);
    }
  }

  namespace aux
  {
    template<typename Collection>
      auto getIndex(Collection const& collection, size_t offset = 0)
      {
        return [&collection, offset](auto const& iterator)
          {
            return offset + std::distance(begin(collection), iterator);
          };
      }
  }

   decltype(auto) swapCase(const std::string& s)
	{
		std::stringstream ss;
		for (auto c:s)
			ss << chars::swapCase(c);
		return ss.str();
	}

  decltype(auto) lowerCase(const std::string& s)
  {
	std::stringstream ss;
	for (auto c:s)
		ss << static_cast<char>(std::tolower(c));
	return ss.str();
  }
  decltype(auto) upperCase(const std::string& s)
  {
	std::stringstream ss;
	for (auto c:s)
		ss << static_cast<char>(std::toupper(c));
	return ss.str();
  }


  template<typename F=decltype(constants::default_function), typename R = typename std::result_of<F&(std::string)>::type>
    std::vector<R> explode(const  std::string& s, const std::string& c,F f=constants::default_function)
    {

      auto res=std::vector<R>();
      res.reserve(s.size());
      int last_index=0;
      const auto index=aux::getIndex(s,0);
      for (auto letter=s.begin(); letter!=s.end(); ++letter)
        {
          if (c.find(*(letter))!=std::string::npos)
            {
              if(index(letter)!=last_index)
                  res.emplace_back(s.substr(last_index,index(letter)-last_index));
              last_index=index(letter)+1;
            }
        }
      if (last_index!=s.size()-2)
        res.emplace_back(s.substr(last_index));
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
