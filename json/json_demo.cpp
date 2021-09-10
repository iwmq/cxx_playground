#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int arc, char* argv[])
{
    json j;
    j["name"] = "Jay Wang";
    j["languages"] = {"Python", "JavaScript", "C++"};

    std::cout << j.dump() << std::endl;

    return 0;
}