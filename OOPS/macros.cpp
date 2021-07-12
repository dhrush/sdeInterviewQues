#include <iostream>
using namespace std;

#define deb(x) cout << #x << ": " << x << endl;

int main()
{
    int x(100), y(200);
    deb(x);
    deb(y);
    return 0;
}