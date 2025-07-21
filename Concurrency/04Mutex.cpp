/*
mutex - lock, unlock & try_lock
std::try_lock(m1,m2) --> atleast 2 mutex it will take

recursive_mutex
*/
#include <thread>
#include <mutex>

#include <iostream>

using namespace std;

// // mutex lock & unlock
// int val=0;
// mutex mtx;

// void fun(){
//     for(int i=1;i<=100000;i++){
//         mtx.lock();
//         val++;
//         mtx.unlock();
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

////-----------------------
// // mutext try_lock
// int val=0;
// mutex mtx;

// void fun(){
//     for(int i=1;i<=100000;i++){
//         if(mtx.try_lock()){
//             val++;
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



////-----------------------
// std--> lock, lock_for, lock_until, try_lock, 
int val=0;
mutex m1, m2;

void fun(){
    for(int i=1;i<=100000;i++){
        if(try_lock(m1, m2)){
            val++;
            m1.unlock();
            m2.unlock();
        }
    }
}
int main(){
    thread t1(&fun);
    thread t2(&fun);
    thread t3(&fun);

    t1.join();
    t2.join();
    t3.join();

    cout<<val<<endl;

return 0;
}