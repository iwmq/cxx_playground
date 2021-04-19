#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    // vector<long long int> data;
    // data.push_back(1);
    // data.push_back(2);
    // data.push_back(3);

    // Bracket initializer
    vector<long long int> data {1, 2, 3, 4};

    // vector<int>::iterator iter = data.begin();
    // auto iter = data.begin();
    // for (; iter != data.end(); iter ++)
    // {
    //     cout << *iter << endl;
    // }

    // Range-based iterator
    for(auto&& i : data) {
        cout << "i = " << i << endl;
    }

    // Use for_each
    for_each(data.begin(), data.end(), [](auto& i) {
        cout << "i * i = " << i * i << endl;
    });

    // Use find
    auto found_num = find(data.begin(), data.end(), 5);
    if ( found_num != end(data) ) {
        cout << "Found " << *found_num << endl;
    } else {
        cout << "Not found" << endl;
    }

    // Use find_if
    found_num = find_if(data.begin(), data.end(), [](auto& i) {
        return i % 2 == 0;
    });
    if ( found_num != end(data) ) {
        cout << "Found " << *found_num << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "Size of long long int " << sizeof(long long int) << endl;
    cout << "Size of int " << sizeof(int) << endl;

    return 0;
}
