#include<iostream>
#include<string>

using namespace std;

template<typename T0, typename... Ts>
void print1(T0 val, Ts... args) {
    cout<<val<<endl;
    if constexpr (sizeof...(Ts) > 0) {
        print1(args...);
    }
}

template<typename ... T>
auto sum(T ... t) {
    // fold expression
    return (t + ...);
}

int main(int argc, char** argv)
{   
    string sep(80, '-');

    print1(1);
    cout<<sep<<endl;
    print1("Hello", 2, 'd', 1.02);
    cout<<sep<<endl;

    cout<<sum(1, 2, 3, 4, 5)<<endl;

    return 0;
}
