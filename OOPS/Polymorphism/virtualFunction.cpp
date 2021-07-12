/*
1. A C++ virtual function is a member function in the base class that you redefine in a derived class. It is declared using the virtual keyword.
2. It is used to tell the compiler to perform dynamic linkage or late binding on the function.
3. A 'virtual' is a keyword preceding the normal declaration of a function
4. When the function is made virtual, C++ determines which function is to be invoked at the runtime based on the type of the object pointed by the base class pointer.
*/
/*
#include <iostream>
class A
{
public:
    int x = 5;
    void display() { std::cout << x << std::endl; }
};

class B : public A
{
public:
    int y = 10;
    void display() { std::cout << y << std::endl; }
};

int main()
{
    A *a;
    B b;
    a = &b;
    a->display();
    return 0;
}

In the above example, * a is the base class pointer. The pointer can only access the base class members but not the members of the derived class. 
Although C++ permits the base pointer to point to any object derived from the base class, it cannot directly access the members of the derived class. 
Therefore, there is a need for virtual function which allows the base pointer to access the members of the derived class.
*/

/*
#include <iostream>

class A
{
public:
    virtual void display() { std::cout << "Base class invoked" << std::endl; }
};

class B : public A
{
public:
    void display() { std::cout << "Child class invoked" << std::endl; }
};

int main()
{
    A *a;
    B b;
    a = &b;
    a->display();
    return 0;
}
*/

#include <iostream>
using namespace std;
class Base
{
public:
    virtual void show() = 0;
};
class Derived : public Base
{
public:
    void show()
    {
        std::cout << "Derived class is derived from the base class." << std::endl;
    }
};
int main()
{
    Base *bptr;
    //Base b;
    Derived d;
    bptr = &d;
    bptr->show();
    return 0;
}