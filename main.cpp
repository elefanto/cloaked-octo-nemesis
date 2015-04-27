#include <iostream>
#include "func.h"

using namespace std;

int main() {

	Arr test(0);
	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	test.push(5);
	test.push(6);
	test.push(7);
	test.push(8);
	test.push(9);
	test.push(10);
	test.push(11);
	test.get_array();
	test.insert(3, 555.555);
	test.get_array();
	//	test.delete_element(3);
	//	test.pop();
	test.get_array();

	cout << test.get_capacity() << "\t" << test.get_size() << endl;

	Arr test1 = test;
	test1.get_array();

	const Arr test2 = test1;
	test2.get_array();

	cout << test.get_capacity() << "\t" << test.get_size() << endl;
	cout << test[1] << endl;
	const size_t bla = 3;
	cout << test[bla] << endl;

	return 0;
}

