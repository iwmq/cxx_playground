#include<iostream>
#include<memory>
#include<string>

// using namespace std;

struct Person {
    Person(unsigned int age, std::string name)
    : age(age), name(name)  {}

    unsigned int age;
    std::string name;
};

std::ostream& operator<<(std::ostream& os, Person &p)
{
    os<<"Person: name = " << p.name << ", age = " << p.age;
    return os;
}


int main(int argc, char** argv)
{
    Person p(20, "Alice");
    std::cout<<p<<std::endl;

    std::shared_ptr<Person> pp = std::make_shared<Person>(20, "Judy");
    std::cout<<*pp<<std::endl;

    return 0;
}
