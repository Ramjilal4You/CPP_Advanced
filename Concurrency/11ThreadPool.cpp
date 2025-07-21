/*  Thread Pool -> use Object Pool Design pattern
client --> ThreadPool <>-- Thread
*/

#include <iostream>
#include <queue>
#include <mutex>
#include <vector>
#include <functional>   //function
#include <thread>
#include <condition_variable>
#include <utility>  //forward
using namespace std;

typedef void (*fptr)();

class ThreadPool{
private:
    vector<thread> _workers;

    queue<function<void()>> _tasks;
    bool stop;
    mutex queue_mtx;
    condition_variable cv;
public:
    ThreadPool(int n):stop(false){
        for(size_t i=1;i<=n;i++){
            _workers.emplace_back([this]{
                while(1){
                    unique_lock<mutex> lock(queue_mtx);
                    cv.wait(lock, [this]{return !_tasks.empty() || stop; });
                    if(stop && _tasks.empty())
                        break;
                    
                    auto task = move(_tasks.front());   //extract from queue
                    _tasks.pop();   //remove from queue

                    lock.unlock();  //unloack the queue_mtx, so other thread can use it

                    task(); //Run the task

                }
            });
        }

    }

    template<class T>
    void addTask(T&& task){
        unique_lock<mutex> lock(queue_mtx);
        _tasks.emplace(forward<T>(task));
        lock.unlock();  //unlock the task queue
        cv.notify_one();    //notify other thread 
    }

    ~ThreadPool(){
        unique_lock<mutex> lock(queue_mtx);
        stop=true;
        lock.unlock();
        cv.notify_all();

        for(thread &t : _workers){
            t.join();
        }
    }
};

int main(){

    ThreadPool pool(3);
    cout<<"Pool created\n";
    //add task to queue
    for(int i=1;i<=8;i++){
        auto fun=[i](){printf("Task %d executed by thread : %d\n",i,this_thread::get_id());};
        pool.addTask(fun);
        this_thread::sleep_for(chrono::seconds(1));
    }
    
return 0;
}