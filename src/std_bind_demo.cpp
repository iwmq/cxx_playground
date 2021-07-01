#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std::placeholders;

int f(int x, int y)
{
    return x + y;
}

void print(std::ostream *os, int i)
{
    *os << "-- " << i << " --" << std::endl;
}

class TestBind
{
    public:
        TestBind(std::string name): name_(name)
        {
            std::cout << "Calling TestBind()" << std::endl;
        }

        ~TestBind()
        {
            std::cout << "Calling ~TestBind()" << std::endl;
        }

        void greet(std::string message)
        {
            std::cout << "Hello, " << name_
            << ", a message for you: " << message << std::endl;
        }

    private:
        std::string name_;
};


int main()
{
    std::vector<int> v{1, 4, 5, 3}; // ++std=c++11
    std::for_each(v.begin(), v.end(), std::bind(print, &std::cout, _1));

    std::cout << std::string(120, '*') << std::endl;

    int result = std::bind(f, 1, _1)(1);
    std::cout << "** " << result << " **" << std::endl;

    std::cout << std::string(120, '*') << std::endl;

    // NOTICE: a member function of a class takes a imexplicit object pointer
    // as its first parameter, whichi is why `&test_bind` is used.
    TestBind test_bind("Jay");
    auto greet = std::bind(&TestBind::greet, &test_bind, _1);
    greet("You are using std::bind!");

    return 0;
}