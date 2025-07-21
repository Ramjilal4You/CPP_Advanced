/*
loack_guard - supports RAII
-- light waight wrapper template class for owning mutex on scoped basis
-- you can not copy, assign or move it
-- kind of smart lock
-- auto lock & auto unlock
-- works with - mutex, timed_mutex & recursive_mutex
-- only support adopt_lock locking strategy

std::scoped_lock offers an alternative for lock_guard that provides the 
ability to lock multiple mutexes using a deadlock avoidance algorithm.
*/
#include <thread>
#include <mutex>

#include <iostream>

using namespace std;


// lock_guard for mutex
int val=0;
mutex mtx;

void fun(){
    for(int i=1;i<=100000;i++){
        mtx.lock();
        lock_guard<mutex> lg(mtx, adopt_lock);
        val++;
        //mtx.unlock(); //no need of lock & unlock
    }
}
int main(){
    thread t1(&fun);
    thread t2(&fun);

    t1.join();
    t2.join();

    cout<<val<<endl;

return 0;
}

// //----------------
// //lock_guard for timed_mutex
// int val=0;
// timed_mutex mtx;

// void fun(){
//     for(int i=1;i<=100000;i++){
//         lock_guard<timed_mutex> lg(mtx);
//         val++;
//         //mtx.unlock(); //no need of lock & unlock
//     }
// }
// int main(){
//     thread t1(&fun);
//     thread t2(&fun);

//     t1.join();
//     t2.join();

//     cout<<val<<endl;

// return 0;
// }


// //----------------
// // lock_guard for recursive_mutex
// int val=0;
// recursive_mutex mtx;

// void fun(int n){
//     if(n>5)
//         return;
//     lock_guard<recursive_mutex> lg(mtx); //lock
//     cout<<"Thread id : "<<this_thread::get_id()<<" - "<<n<<endl;
//     val++;
//     fun(++n);   //recursive call
//     //mtx.unlock();   //no need of lock & unlock as using lock guard
// }
// int main(){
//     thread t1(fun, 1);
//     thread t2(fun, 1);

//     t1.join();
//     t2.join();

//     cout<<val<<endl;

// return 0;
// }
