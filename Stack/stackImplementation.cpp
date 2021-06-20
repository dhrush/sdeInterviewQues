#include <iostream>
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Stack
{
    int top;
    public:
        int a[MAX];
        
        Stack(){top = -1;}
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
        bool isFull();
};

bool Stack::push(int x)
{
    if(top >= (MAX-1) )
        return false;
    else
    {
        a[++top]=x;
        return true;
    }
}

int Stack::pop()
{
    if(top<0)
        return INT_MIN;
    else
    {
        return(a[top--]);
    }
}

int Stack::peek()
{
    if(top >= (MAX-1) )
        return INT_MIN;
    else
    {
        return (a[top]);
    }
}

bool Stack::isFull()
{
    if(top >= (MAX-1))  return true;
    else return false;
}

bool Stack::isEmpty()
{
    if(top < 0) return true;
    else    return false;
}

int main() 
{
    class Stack s1;
    bool IsEmpty = s1.isEmpty();
    cout<<IsEmpty<<"\n";
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    while(!s1.isEmpty())
    {
        cout<<s1.peek();
        cout<<"\n";
        s1.pop();
    }
	return 0;
}
