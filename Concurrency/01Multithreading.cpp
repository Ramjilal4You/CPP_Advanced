/*  Multithreading  

**  1. Light waight process is called thread
**  Ways of creating thread in c++
    thread t(callable, parameter list);
    Callable can be ...
    1. function pointer
    2. lembda function
    3. Functors
    4. Non-Static Member fuction
    5. Static Member fuction
*/

#include <iostream>
#include <thread>

using namespace std;

//1. function pointer
// void fun(int x)
// {
//     cout<<"Thread ID : "<<this_thread::get_id()<<" - x : "<<x<<endl;
// }

// int main()
// {
//     cout<<"Thread ID : "<<this_thread::get_id()<<endl;
    
//     thread t(fun, 11);

//     t.join();

//     return 0;
// }



//2. lembda function
// auto f = [](int x)
// {
//     cout<<"Thread ID : "<<this_thread::get_id()<<" - x : "<<x<<endl;
// };

// int main()
// {
//     cout<<"Thread ID : "<<this_thread::get_id()<<endl;
    
//     thread t(f, 12);

//     t.join();

//     return 0;
// }

//3. Functors (Function Objects)

// class Fnctr{
// public:
//     void operator()(int x){
//         cout<<"Thread ID : "<<this_thread::get_id()<<" - Fnctr(x) : "<<x<<endl;
//     }
// };

// int main()
// {
//     cout<<"Thread ID : "<<this_thread::get_id()<<endl;
    
//     thread t(Fnctr(), 13);

//     t.join();

//     return 0;
// }


//4. Non-Static Members

// class Temp{
// public:
//     void fun(int x){
//         cout<<"Thread ID : "<<this_thread::get_id()<<" - fun(x) : "<<x<<endl;
//     }
// };

// int main()
// {
//     cout<<"Thread ID : "<<this_thread::get_id()<<endl;
    
//     Temp obj;

//     thread t(&Temp::fun, obj, 13);

//     t.join();

//     return 0;
// }


//5. Static Members

// class Temp{
// public:
//     static void fun(int x){
//         cout<<"Thread ID : "<<this_thread::get_id()<<" - static fun(x) : "<<x<<endl;
//     }
// };

// int main()
// {
//     cout<<"Thread ID : "<<this_thread::get_id()<<endl;
    

//     thread t(&Temp::fun, 13);

//     t.join();

//     return 0;
// }