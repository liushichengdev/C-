// thread.cpp : Defines the entry point for the application.
//

// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include "thread.h"

void foo()
{
	// do stuff...
	for (int i = 0; i < 10; i++)
		std::cout << "function-----foo:" << std::this_thread::get_id() << std::endl;
}

void bar(int x)
{
	// do stuff...
	for (int i = 0; i < 10; i++)
		std::cout << "function-----bar:" << std::this_thread::get_id() << std::endl;
}

int main()
{
	std::thread first(foo);     // spawn new thread that calls foo()
	std::thread second(bar, 0);  // spawn new thread that calls bar(0)

	std::cout << "Hardware Concurrency: " << std::thread::hardware_concurrency() << std::endl;
	std::cout << "main, foo and bar now execute concurrently...\n";

	// synchronize threads:
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes

	/*first.detach();
	second.detach();*/

	std::cout << "foo and bar completed.\n";

	return 0;
}
