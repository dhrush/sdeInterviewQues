#include <iostream>
/*
If we create two or more members having the same name but different in number or type of parameter, it is known as C++ overloading. In C++, we can overload:

1. methods,
2. constructors, and
3. indexed properties
*/
class cal
{
public:
    int add(int a, int b) { return a + b; }

    int add(int a, int b, int c) { return a + b + c; }

    void fun(int i) { std::cout << i << std::endl; }

    //void fun(float i) { std::cout << i << std::endl; }    This results in an error as all floating point members are trearted as double not as float

    void fun(double i) { std::cout << i << std::endl; }
};

int main()
{
    cal ob;
    /*std::cout << ob.add(2, 3) << std::endl;
    std::cout << ob.add(2, 3, 4) << std::endl;*/

    //  ob.fun(5.6);        This results in an error as all floating point members are trearted as double not as float
    ob.fun(5.6);            //this works as expected
    return 0;
}