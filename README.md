# CPP_Advanced
I'll add here all the examples related to Advanced C++ topics.

https://www.linkedin.com/pulse/rule-zero-six-rainer-grimm/ - https://www.pearson.com/en-us/subject-catalog/p/c-core-guidelines-explained-best-practices-for-modern-c/P200000007274/9780136875673

Youtube - 
01 Memory Leaks & How to avoid
	- Memory Leaks - with diagnostic tool
	- How can we avoid - using delete
02 Rule of 3 - https://www.geeksforgeeks.org/rule-of-three-in-cpp/
03 Rule of 5 - https://www.geeksforgeeks.org/rule-of-five-in-cpp/

04 Smart Pointers - why need, what & types
	- unique_ptr
	- shared_ptr
	- weak_ptr - with proper example, where to use

05 Casting Operators
	- static_cast
	- dynamic_cast
	- reinterpret_cast
	- const_cast
	
06 Concurrency
	01. Multithreading
		- Thread creation methods - 5(ways) 
		- return value from thread - (future, promise & async with launch policy)
		-> join, joinable, detach
		
	02. mutex	--> lock, unlock, try_lock
		- timed mutex - try_lock_for(), try_lock_until()
		- recursive_mutex
	
	03. lock_gaurd<mutex> lock(mtx)	--> scopped auto lock & unlock use RAII, can not allow copy, assignment & move
	
	04. unique_lock<mutex> ul(mtx) 			--> scopped auto lock & unlock with policy : adopt
	-  scoped_lock() 
	
	05. shared_lock<shared_mutex> sl(smtx)	--> 
	
	06. Conditional_variables	--> wait(unique_lock, predicate), wait_for(), wait_until(), notify_one(), notify_all();
	
	07. Semaphore(binary_semaphore & counting_semaphore)	--> acuire(), release()
	
	08. sleep_for() Vs wait();
	
	09. COnsumer Producer problems
	10. Difference between Semaphore & Mutex
	11. Object Pool
	12. Thread Pool
	
