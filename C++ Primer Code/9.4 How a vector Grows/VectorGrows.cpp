// 9.4 How a vector Grows.cpp : Defines the entry point for the application.
//

#include "VectorGrows.h"
#include <vector>

using namespace std;

int main()
{
	cout << "Hello A Vector Grows." << endl;

	//#1
	vector<int> ivec;

	cout << "#1 ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	//#2
	for (vector<int>::size_type ix = 0; ix != 24; ++ix) {
		ivec.push_back((int)ix);
	}

	cout << "#2 ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	//#3
	ivec.reserve(50);

	cout << "#3 ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	//#4
	while (ivec.size() != ivec.capacity()) {
		ivec.push_back(0);
	}
	cout << "#4 ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	//#5
	ivec.push_back(42);
	cout << "#5 ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	//#6
	ivec.shrink_to_fit();
	cout << "#6 ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

	return 0;
}
