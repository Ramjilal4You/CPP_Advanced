/*
recursive_mutex --> for loop & recursive calls
    -   lock, unlock, try_lock,

*/
#include <thread>
#include <mutex>

#include <iostream>

using namespace std;

// // recursive_mutex for recursive call
// int val=0;
// recursive_mutex mtx;

// void fun(int n){
//     if(n>5)
//         return;
//     mtx.lock(); //lock
//     cout<<"Thread id : "<<this_thread::get_id()<<" - "<<n<<endl;
//     val++;
//     fun(++n);   //recursive call
//     mtx.unlock();   //unlock after recursive call
// }
// int main(){
//     thread t1(fun, 1);
//     thread t2(fun, 1);

//     t1.join();
//     t2.join();

//     cout<<val<<endl;

// return 0;
// }

////-----------------
// // recursive_mutex for loop
// int val=0;
// recursive_mutex mtx;

// void fun(){
//     for(int i=1;i<=10;i++){
//         mtx.lock();
//         val++;
//     }

//     for(int i=1;i<=10;i++){
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
// recursive_mutex for recursive call
int val=0;
recursive_mutex mtx;

void fun(int n){
    if(n>5)
        return;
    
    if(mtx.try_lock()){ //lock
        cout<<"Thread id : "<<this_thread::get_id()<<" - "<<n<<endl;
        val++;
    }
    fun(++n);   //recursive call
    mtx.unlock();   //unlock after recursive call
}
int main(){
    cout<<"Main Thread id : "<<this_thread::get_id()<<"\n\n";
    thread t1(fun, 1);
    thread t2(fun, 1);

    t1.join();
    t2.join();

    cout<<val<<endl;

return 0;
}