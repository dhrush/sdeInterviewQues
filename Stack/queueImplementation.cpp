#include <iostream>
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Queue
{
    int front, rear;
    public:
        int a[MAX];
        Queue(){front=0; rear=0;}
        bool Enqueue(int x);
        int Dequeue();
        void displayQueue();
        int getFront();
};

bool Queue::Enqueue(int x)
{
    if(rear >= MAX-1)   return false;
    else 
    {
        /*if(front==rear)
            a[rear++]=x;
        else
            a[++rear] = x;        */
        a[rear]=x;
        rear++;
        return true;
    }
}

int Queue::Dequeue()
{
    if(front == rear)   return INT_MIN;
    else    return(a[front++]);
}

void Queue::displayQueue()
{
    for(int i=front; i<rear; i++)
        cout<<a[i]<<" ";
}

int Queue::getFront()
{
    if(front == rear)   return INT_MIN;
    else    return(a[front]);
}

int main()
{
    class Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    cout<<"\n The initial queue is: ";
    q.displayQueue();
    cout<<"\n";
    cout<<q.Dequeue();
    cout<<"\n The final queue is: ";
    q.displayQueue();
    return 0;
}











