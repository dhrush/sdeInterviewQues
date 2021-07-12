#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int amount = 0;
std::mutex m;

void addMoney()
{
    m.lock();
    ++amount;
    m.unlock();
}

int main()
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    cout << "id of thread t1 is: " << t1.get_id() << endl;
    cout << "id of thread t1 is: " << t2.get_id() << endl;
    t1.join();
    t2.join();

    cout << "the amount is: " << amount << endl;
    return 0;
}