#include<iostream>
#include<map>

using namespace std;

int main(int argc, char** argv)
{
    map<string, string> favorites;
    favorites["color"] = "RED";
    favorites["food"] = "Humberg";

    // vector<int>::iterator iter = data.begin();
    auto iter = favorites.begin();
    for (; iter != favorites.end(); iter ++)
    {
        cout << iter->first << " --> " << iter->second << endl;
    }
    return 0;
}