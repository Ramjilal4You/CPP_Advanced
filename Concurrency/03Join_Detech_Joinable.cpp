/*  Multithreading  : Join, Joinable, detech

    Problem:
    1. double join --> runtime error
    2. double detech --> runtime error
*/

#include <iostream>
#include <thread>

using namespace std;

void fun()
{
    cout<<"Thread ID : "<<this_thread::get_id()<<endl;
}

int main()
{
    cout<<"Thread ID : "<<this_thread::get_id()<<endl;
    
    thread t(fun);

    //t.join();
    //t.join(); //it 'std::system_error' execption, to avoid this always use joinable before join

    this_thread::sleep_for(chrono::seconds(1));

    t.detach(); //(demon thread) detach the thread, not operating system will terminate this thread automaticallu when parent thread will be terminated

    //t.detach(); //it 'std::system_error' execption, to avoid this always use joinable before detach

    if(t.joinable()){
        t.detach(); // no issue
    }

return 0;
}