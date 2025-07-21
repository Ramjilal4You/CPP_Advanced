/*
unique_lock 
-- light waight wrapper template class for owning mutex on scoped basis
-- works with - mutex, timed_mutex & recursive_mutex
-- It allows
    1. can have different locking strategies
    2. can transfer of ownership (move alowed but not copy/ assignment)
    3. can be use with condition_variable
    4. allow time constrained attempts at locking (try_lock_for, try_lock_until)

-- Locking strategies
    1. defer_lock   -   do not aquire ownership of the mutex
    2. try_to_lock  -   try to aquire ownership of the mutex without blocking
    3. adopt_lock   -   assume that calling thread already has the ownership of the mutex

-- kind of smart lock
-- auto lock & auto unlock

*/
#include <thread>
#include <mutex>

#include <iostream>

using namespace std;



// //----------------
// // unique_lock for mutex with defer_lock strategy
// int val=0;
// mutex mtx;

// void fun(){
    
//     unique_lock<mutex> ul(mtx, defer_lock); //does not lock
//     ul.lock();  //lock here 
//     for(int i=1;i<=10;i++){
//         cout<<"thread id : "<<this_thread::get_id()<<" - "<<val<<endl;
//         val++;
//         //mtx.unlock(); or ul.unlock(); //no need of unlock
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

// // unique_lock for mutex with adopt_lock strategy
// int val=0;
// mutex mtx;

// void fun(){
//     mtx.lock();
//     unique_lock<mutex> ul(mtx, adopt_lock);
//     for(int i=1;i<=10;i++){
//         cout<<"thread id : "<<this_thread::get_id()<<" - "<<val<<endl;
//         val++;
//         //mtx.unlock(); //no need of unlock
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

// unique_lock for mutex with try_to_lock strategy
int val=0;
mutex mtx;

void fun(){
    mtx.lock();
    unique_lock<mutex> ul(mtx, try_to_lock);
    for(int i=1;i<=10;i++){
        cout<<"thread id : "<<this_thread::get_id()<<" - "<<val<<endl;
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
// // unique_lock for mutex without locking strategies
// int val=0;
// mutex mtx;

// void fun(){
    
//     unique_lock<mutex> ul(mtx); //auto lock & unlock
//     val++;
//     //mtx.unlock(); //no need of lock & unlock
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
// //unique_lock for timed_mutex
// int val=0;
// timed_mutex mtx;

// void fun(){
//     for(int i=1;i<=100000;i++){
//         unique_lock<timed_mutex> ul(mtx);
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
// // unique_lock for recursive_mutex
// int val=0;
// recursive_mutex mtx;

// void fun(int n){
//     if(n>5)
//         return;
//     unique_lock<recursive_mutex> lg(mtx); //lock
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
