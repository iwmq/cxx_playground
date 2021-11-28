#include<array>
#include<iostream>
#include<ranges>

using namespace std;

int main(int argc, char** argv)
{
    array<int, 10> a {10, 2, 87, 3, 5, 9, 4, 7, 101, 6};
    cout<<"Before sorting: ";
    for(auto& i:a) {
        cout<<i<<" ";
    }
    cout<<endl;

    // Not sopported yet
    // ranges::sort(a);

    sort(a.begin(), a.end());
    cout<<"After sorting (std:sort): ";
    for(auto& i:a) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
