/*
std::thread::joinable
bool joinable() const noexcept;
Check if joinable
Returns whether the thread object is joinable.

A thread object is joinable if it represents a thread of execution.

A thread object is not joinable in any of these cases:
if it was default-constructed.
if it has been moved from (either constructing another thread object, or assigning to it).
if either of its members join or detach has been called.
*/

#include <iostream>       // std::cout
#include <thread>         // std::thread

void mythread()
{
	// do stuff...
}

int main()
{
	std::thread foo;
	std::thread bar(mythread);

	std::cout << "Joinable after construction:\n" << std::boolalpha;
	std::cout << "foo: " << foo.joinable() << '\n'; // it is default-constructed
	std::cout << "bar: " << bar.joinable() << '\n'; // initialization constructor

	if (foo.joinable()) foo.join();
	if (bar.joinable()) bar.join();

	std::cout << "Joinable after joining:\n" << std::boolalpha;
	std::cout << "foo: " << foo.joinable() << '\n';
	std::cout << "bar: " << bar.joinable() << '\n';

	return 0;
}