/*
1. Binding together data and function that manipulates the data
2. If we created class and have data member and member function then it is called encapsulation
*/

#include <iostream>
class Base
{
private:
    int m_x;

public:
    void setX(int n) { this->m_x = n; }
    int getX() { return this->m_x; }
};

int main()
{
    Base b;
    b.setX(56);
    std::cout << "value of x is: " << b.getX() << std::endl;
    return 0;
}