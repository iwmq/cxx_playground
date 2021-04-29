#include <boost/bind/bind.hpp>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace boost::placeholders;

int f(int x, int y)
{
    return x + y;
}

void print(std::ostream *os, int i)
{
    *os << "-- " << i << " --" << std::endl;
}

int main()
{   
    std::vector<int> v{1, 4, 5, 3}; // ++std=c++11
    std::for_each(v.begin(), v.end(), boost::bind(print, &std::cout, _1));

    std::cout << std::string(120, '*') << std::endl;

    int result = boost::bind(f, 1, _1)(1);
    std::cout << "** " << result << " **" << std::endl;
 
    return 0;
}