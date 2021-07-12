#include <iostream>
#include <string>

using namespace std;

class B; //pre declaration
class A
{
private:
    int minA;

public:
    A(int a)
    {
        minA = 0;
        this->minA = a;
    }
    friend int minAB(A, B);
};

class B
{
private:
    int minB;

public:
    B(int b)
    {
        minB = 0;
        this->minB = b;
    }
    friend int minAB(A, B);
};

int minAB(A a, B b)
{
    return min(a.minA, b.minB);
}

int main()
{
    A a(5);
    B b(10);
    cout << "minimum of " << minAB(a, b) << endl;

    return 0;
}