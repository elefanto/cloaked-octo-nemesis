#include <iostream>
#include "func.h"

using namespace std;

int main() {

	Arr<double> test(0);
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
	//test.get_array();
	test.insert(3, 555.555);
	//test.get_array();
	//	test.delete_element(3);
	//	test.pop();

	cout << test << endl;

	Arr<double> test1 = test;
	//test1.get_array();

	const Arr<double> test2 = test1;
	//test2.get_array();

	//cout << test.get_capacity() << "\t" << test.get_size() << endl;
	//cout << test[1] << endl;
	//const size_t bla = 3;
	//cout << test[bla] << endl;
	//==================================================================
	//======================int=========================================
	//==================================================================
	Arr<int> test_int(0);
	test_int.push(1);
	test_int.push(2);
	test_int.push(3);
	test_int.push(4);
	test_int.push(5);
	test_int.push(6);
	test_int.push(7);
	test_int.push(8);
	test_int.push(9);
	test_int.push(10);
	test_int.push(11);
	//test_int.get_array();
	test_int.insert(3, 555.555);
	//test_int.get_array();
	//	test_int.delete_element(3);
	//	test_int.pop();
	//test_int.get_array();

	//cout << test_int.get_capacity() << "\t" << test_int.get_size() << endl;

	Arr<int> test1_int = test_int;
	//test1_int.get_array();

	const Arr<int> test2_int = test1_int;
	test_int.push(999);
	test_int.push(91919);
	test_int.push(96969);
	//test2_int.get_array();

	//cout << test_int.get_capacity() << "\t" << test_int.get_size() << endl;
	//cout << test_int[1] << endl;
	//const size_t bla_int = 3;
	//cout << test_int[bla] << endl;

	//==================================================================
	//======================Arr=========================================
	//==================================================================

	Arr<Arr<int> > test_arr(0);
	test_arr.push(test1_int);
	test_arr.push(test2_int);
	Arr<Arr<int> > test_arr1(0);
	test_arr1 = test_arr;
	test_arr.insert(0, test_int);
	cout << "First array array:\t\t" << test_arr << endl;
	cout << "Second array array:\t\t" << test_arr1 << endl;
	cout << "First array array [0]:\t\t" << test_arr[0] << endl;
	cout << "First array array [0][13]:\t" << test_arr[0][13] << endl;
	test_arr[0][13] = 666;

	cout << "First array array [0][13]:\t" << test_arr[0][13] << endl;
	cout << "Capacity: " << test_arr.get_capacity() << "\tSize: "
			<< test_arr.get_size() << endl;


	//	Arr<Arr<int> >  test1_arr = test_arr;
	//	test1_arr.get_array();
	//
	//	const Arr<Arr<int> >  test2_arr = test1_arr;
	//	test2_int.get_array();
	//
	//	cout << test_arr.get_capacity() << "\t" << test_arr.get_size() << endl;
	//	cout << test_arr[1] << endl;
	//	const size_t bla_arr = 3;
	//	cout << test_arr[bla] << endl;

	return 0;
}

