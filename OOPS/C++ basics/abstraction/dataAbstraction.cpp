/*
Data Abstraction is a process of providing only the essential details to the outside world 
and hiding the internal details, i.e., representing only the essential details in the program.

Let's take a real life example of AC, which can be turned ON or OFF, change the temperature, change the mode, and other external components such as fan, swing. 
But, we don't know the internal details of the AC, i.e., how it works internally. Thus, we can say that AC seperates the implementation details from the external interface

C++ provides a great level of abstraction. 
For example, pow() function is used to calculate the power of a number without knowing the algorithm the function follows.
*/

/*
1. Abstraction using classes: 
    An abstraction can be achieved using classes. A class is used to group all the data members and member functions into a single unit by using the access specifiers. 
    A class has the responsibility to determine which data member is to be visible outside and which is not.

2. Abstraction in header files: An another type of abstraction is header file. 
    For example, pow() function available is used to calculate the power of a number without actually knowing which algorithm function uses to calculate the power. 
    Thus, we can say that header files hides all the implementation details from the user.

*/

// abstraction using classes
/*
#include <iostream>
using namespace std;
class Sum
{
private:
    int x, y, z; // private variables
public:
    void add()
    {
        cout << "Enter two numbers: ";
        cin >> x >> y;
        z = x + y;
        cout << "Sum of two number is: " << z << endl;
    }
};
int main()
{
    Sum sm;
    sm.add();
    return 0;
}
*/

//abstraction using header files
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n = 4;
    int power = 3;
    int result = pow(n, power); // pow(n,power) is the  power function
    std::cout << "Cube of n is : " << result << std::endl;
    return 0;
}