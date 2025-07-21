/* Condition Cariables
IMPORTANT: cv are used for 2 perpuses
    1. Notify other threads
    2. waiting for some conditions
-- notify_one(), notify_all(), wait, wait_for, wait_until
-- wait(unique_lock<mutex>&, predicate )
    - predicate : function which returns true/false;
        true -> execute
        false -> wait

//  1. cv allow running threads to wait on some condition & once those condition is met the waiting thread 
        notify other thread using notify_one or ontify_all
//  2. you need mutex with unique_lock to use condition variables
//  3. if thread want to wait for some condition then it has to do these things:
        a. Acquire the mutex lock using unique_lock<mutex> lck(mtx)
        b. Execute wait, wait_for, wait_until, the wait operation automatcally 
            release the mutex & suspend the execution of the thread
        c. when condition variable is notified, the thread is awakened, and mutex is automatically reacquired the lock.
            the thread then should check the condition & resume waiting if the wakeup was spurious.

Spurious Wakeup:(wakeup before notify) some thread is waiting but no one is sending notify
Lost Wakeup: the sender sends the notification but there is no receiver in the wait for the notification yet.

//Note:
1. Condition variables are use to synchronize two or more threads
2. best example -> producer consumer problem

*/

#include <thread>
#include <mutex>
#include <condition_variable>

#include <iostream>

using namespace std;


int balance=0;
mutex mtx;
condition_variable cv;

void addMoney(int money){  
    this_thread::sleep_for(chrono::seconds(1));
    lock_guard<mutex> lg(mtx);
    balance+=money;
    cout<<"Money Added\n";
    cv.notify_one();    //to wake up 1 thread
}

void withdrawMoney(int money){
    unique_lock<mutex> ul(mtx);
    cv.wait(ul, [=](){return balance>=money?true:false;});
    if(balance>=money){
        balance-=money;
        cout<<"Money Withdrown\n";
    }
    else
        cout<<"Low balance\n";
}
int main(){
    thread t1(addMoney, 500);
    thread t2(withdrawMoney, 500);

    t1.join();
    t2.join();

    cout<<balance<<endl;

return 0;
}

