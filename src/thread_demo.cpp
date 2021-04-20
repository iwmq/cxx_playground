#include<iostream>
#include<thread>

using namespace std;

void thread_func(int count)
{
    for(int i = 0; i < count; i++)
    {
        cout << "From spawned thread: i = " << i << endl;
        this_thread::sleep_for(2000ms);
    }
}

int main(int argc, char** argv)
{
    cout << "Main thread started..." << endl;
    
    int count = 10;
    thread t(thread_func, count);

    for(int i = 0; i < count; i++)
    {
        cout << "From main thread: i = " << i << endl;
        this_thread::sleep_for(1000ms);
    }

    t.join();

    cout << "Main thread finished..." << endl;
}