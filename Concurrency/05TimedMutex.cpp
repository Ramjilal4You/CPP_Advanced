/*
timed_mutex -   lock, unlock, try_lock, 
            -   try_lock_for & try_lock_until

*/
#include <thread>
#include <mutex>

#include <iostream>

using namespace std;

// // timed_mutex try_lock_for
// int val=0;
// timed_mutex mtx;

// void fun(){
//     for(int i=1;i<=10;i++){
//         if(mtx.try_lock_for(chrono::seconds(1))){
//             val++;
//             this_thread::sleep_for(chrono::seconds(2));
//             mtx.unlock();
//         }
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
