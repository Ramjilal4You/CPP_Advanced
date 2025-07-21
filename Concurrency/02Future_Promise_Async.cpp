/*  Future & Promise */
/*  return value from thread
    1. use of future & promise
    2. use async

*/

#include <thread>
#include <future>   //future, promise, async

#include <iostream>
using namespace std;

//** function pointer, retun value as parameter
void fun(int& x)
{
    x=10;
    cout<<"Thread ID : "<<this_thread::get_id()<<" - x : "<<x<<endl;
}

int main()
{
    cout<<"Thread ID : "<<this_thread::get_id()<<endl;
    int x = 5;
    thread t(fun, ref(x));

    t.join();

    cout<<x<<endl;

    return 0;
}


//1. use of future & promise
// //for ref use case
// void fun(promise<int>& p){
//     p.set_value(50);
// }

// //for move use case
// void fun(promise<int>&& p){
//     p.set_value(50);
// }

// int main()
// {
//     promise<int> p;
//     future<int> f = p.get_future(); //in case of move it should be before thread creation
    
//     //thread t(fun, ref(p));    //it works
//     thread t(fun, move(p));     //it works
    
//     //future<int> f = p.get_future();   //in case of ref it can be before/after thread creation

//     cout<<"Thread Id : "<<this_thread::get_id()<<" return value : "<<f.get()<<endl;
//     t.join();

// return 0;
// }



// //2. use async -1 
//std::async(launchPolicy, callable, parameters) : return value can be stored in future<dataType>


// int fun(int x){
//      cout<<"Thread Id : "<<this_thread::get_id()<<" fun()"<<endl;
//     return x;
// }

// int main()
// {
//     future<int> f = async(fun, 10);
//     //future<int> f = async(&fun, 10);  //it also works
//     this_thread::sleep_for(chrono::seconds(2));
//     cout<<"Thread Id : "<<this_thread::get_id()<<" return value : "<<f.get()<<endl;

// return 0;
// }



//2. use async -with launch policy 
/*
//std::async(launchPolicy, callable, parameters) : return value can be stored in future<dataType>
launchPolicy : 
    1. launch::async    - create & start thread asap
    2. launch::deferred - does not create thread, use parent thread only

*/
int fun(int x){
     cout<<"int fun() - Thread Id : "<<this_thread::get_id()<<endl;
    return x;
}

int main()
{
    //future<int> f = async(launch::async, fun, 10);  //launch::async
    future<int> f = async(launch::deferred, fun, 10);  //launch::deferred
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"in main() - Thread Id : "<<this_thread::get_id()<<endl;

    int ret = f.get();  //main thread will wait here to get the value 
    cout<<"Return value from fun() : "<<ret<<endl;

return 0;
}
