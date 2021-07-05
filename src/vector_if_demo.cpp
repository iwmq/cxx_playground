#include<algorithm>
#include<numeric>
#include<iostream>
#include<span>
#include<vector>


void print(const std::string text, const std::vector<int> &data)
{
    std::cout << text << ": ";
    for(auto&& i : data) {
        std::cout << i << " ";
    }
    std::cout<<std::endl;
}

int main(int argc, char** argv)
{

    std::vector<int> data(20);
    // Fill data with 0 as intitial value
    std::iota(data.begin(), data.end(), 0);
    print("Original numbers", data);

    auto even = [](const int& i) {
        return i % 2 == 0;
    };
    std::vector<int> even_data;
    std::copy_if(data.begin(), data.end(), std::back_inserter(even_data), even);
    print("Even numbers", even_data);

    auto odd = [](const int& i) {
        return i % 2 == 1;
    };
    std::vector<int> odd_data;
    std::copy_if(data.begin(), data.end(), std::back_inserter(odd_data), odd);
    print("Odd numbers", odd_data);

    auto is_3x = [](const int& i) {
        return i % 3 == 0;
    };

    std::vector<int> non_3x_data;
    std::remove_copy_if(data.begin(), data.end(),
        std::back_inserter(non_3x_data), is_3x);
    print("Copy without 3x", non_3x_data);

    auto end = std::remove_if(data.begin(), data.end(), is_3x);
    // Erase residual values
    data.erase(end, data.end());
    print("After removing 3x", data);

    return 0;
}
