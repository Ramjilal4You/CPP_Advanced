/* Semaphore - binary_semaphore & counting_semaphore
// used for signaling

- binary_semaphore - used for signaling
- counting_semaphore - it allows only limited thread inside critical block

1. Aquire & Release 
    - acquire() : decrease count, 
    - release() : insrease count,
    - try_acquire() : decrease count if acquired
    - try_acquire_for : for time duration
2. 

1. std::counting_semaphore
    - A counting semaphore is a synchronization primitive that allows multiple threads to access a shared resource up to a certain limit.
    - It is a generalization of a mutex or a binary semaphore.
    - You can initialize a counting semaphore with an initial count, which represents the number of threads that can access the resource 
        simultaneously without blocking.
    - Threads can acquire and release counts, and the semaphore’s count is incremented or decremented accordingly.
    - If a thread tries to acquire more counts than are available, it will block until counts become available.

2. std::binary_semaphore
    - A binary semaphore is a simpler version of a semaphore that can have only two values: 0 and 1.
    - It is often used for basic mutual exclusion or signaling between two threads.
    - It can be thought of as a mutex with a more lightweight interface.

*/

// C++ Program to illustrate the use of counting_semaphore 
#include <iostream> 
#include <semaphore> 
#include <thread> 
#include <syncstream>

using namespace std; 

// // counting semaphore
// // Initialize semaphore with a count of 2 
// counting_semaphore<10> semaphore(2);
// osyncstream cout_s(cout);

// void worker(int id) 
// { 
// 	// aquiring 
// 	semaphore.acquire(); 

// 	// doing some work 
// 	cout_s << "\nThread " << id << " acquired the semaphore.";

// 	this_thread::sleep_for(chrono::seconds(1));

// 	// releasing 
// 	semaphore.release(); 
// 	cout_s << "\nThread " << id << " released the semaphore.\n"; 
// } 

// // driver code 
// int main() 
// { 
// 	thread t1(worker, 1); 
// 	thread t2(worker, 2); 
// 	thread t3(worker, 3); 
// 	t1.join(); 
// 	t2.join(); 
// 	t3.join(); 
// 	return 0; 
// }



// binary semaphore
// Initialize semaphore with a count of 2 
binary_semaphore semaphore1(1);
osyncstream cout_s(cout);

void worker(int id) 
{ 
	// aquiring 
	semaphore1.acquire(); 

	// doing some work 
	cout_s << "\nThread " << id << " acquired the semaphore.";

	//this_thread::sleep_for(chrono::seconds(1));

	// releasing 
	semaphore1.release(); 
	cout_s << "\nThread " << id << " released the semaphore.\n"; 
} 

// driver code 
int main() 
{ 
	thread t1(worker, 1); 
	thread t2(worker, 2); 
	thread t3(worker, 3); 
	t1.join(); 
	t2.join(); 
	t3.join(); 
	return 0; 
}