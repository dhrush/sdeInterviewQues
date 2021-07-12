/*
If derived class defines same function as defined in its base class, it is known as function overriding in C++.
It is used to achieve runtime polymorphism. It enables you to provide specific implementation of the function which is already provided by its base class
*/

#include <iostream>

class Animal
{
public:
    void eat()
    {
        std::cout << "eats ..." << std::endl;
    }
};

class Dog : Animal
{
public:
    void eat()
    {
        std::cout << "eats parle-g" << std::endl;
    }
};

int main()
{
    Dog d;
    d.eat();
    return 0;
}