#include<fmt/core.h>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    fmt::print("Hello, {}\n", "handsome boy");

    string message = fmt::format(
        "The answer is {}, and you got score {}\n",
        42, 'A'
    );
    cout<<message<<endl;

    return 0;
}
