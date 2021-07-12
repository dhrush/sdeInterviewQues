/*
Abstract classes are the way to achieve abstraction in C++. 
Abstraction in C++ is the process to hide the internal details and showing functionality only. 
Abstraction can be achieved by two ways:

1. Abstract class
2. Interface
*/

#include <iostream>

class Shape
{
public:
    virtual void draw() = 0;
};

class Rectangle : public Shape
{
public:
    void draw() { std::cout << "Drawing rectangle" << std::endl; }
};

class Circle : public Shape
{
public:
    void draw() { std::cout << "Drawing circle" << std::endl; }
};

int main()
{
    Rectangle rec;
    Circle cir;
    rec.draw();
    cir.draw();
    return 0;
}