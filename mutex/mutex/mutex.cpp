/**
 * std::mutex
class mutex;
Mutex class
A mutex is a lockable object that is designed to signal when critical sections of code need exclusive access, preventing other threads with the same protection from executing concurrently and access the same memory locations.

mutex objects provide exclusive ownership and do not support recursivity (i.e., a thread shall not lock a mutex it already owns) -- see recursive_mutex for an alternative class that does.

It is guaranteed to be a standard-layout class.

 */
// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section

void print_block(int n, char c) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
	mtx.lock();
	for (int i = 0; i < n; ++i) { std::cout << c; }
	std::cout << '\n';
	mtx.unlock();
}

int main()
{
	std::thread th1(print_block, 50, '*');
	std::thread th2(print_block, 50, '$');

	th1.join();
	th2.join();

	return 0;
}