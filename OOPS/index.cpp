#include <iostream>
#include <string>

using namespace std;
int main()
{
    int a = 10;
    int *ptr = &a;
    int **pb = &ptr;
    **pb += 1;
    cout << *ptr << endl;
}
