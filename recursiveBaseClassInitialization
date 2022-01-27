#include <iostream>
#include <string>

class Animal{
    public:
    std::string name;
};

class NamedAnimal:public Animal{
    public:
    std::string type;
};

int main()
{
    NamedAnimal cat({{"cat"},"Pradeep"});
    NamedAnimal dog({{"dog"}, "Lavanya"});
    cat = dog;
    std::cout << cat.type << std::endl;
    std::cout << cat.name << std::endl;

    return 0;
}
