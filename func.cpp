#include <iostream>
#include <cstdlib>
#include "func.h"

using namespace std;

Arr::Arr() {
	size = step;
	ptr = new double[size];
	for (size_t i = 0; i < size; ++i)
		ptr[i] = 0;
}

Arr::Arr(int arraySize) {
	size = (arraySize > 0 ? arraySize : step);
	ptr = new double[size];

	for (size_t ix = 0; ix < size; ix++)
		ptr[ix] = 0;
}

void Arr::get_element() {
	size_t position;
	cout << "Enter position(less than " << size << "):" << endl;
	cin >> position;
	if (position < size) {
		cout << ptr[position] << endl;
	} else {
		cout << "Position is to big. GAME OVER;" << endl;
	}
}

void Arr::set_element() {
	size_t position;
	double value;

	cout << "Enter position" << endl;
	cin >> position;
	cout << "Enter value" << endl;
	cin >> value;
	if (position >= size) {
		size_t size_old = size;
		size = position / step * step + step; // збільшення розміру
		change_size(size_old);

	}
	ptr[position] = value;
}
void Arr::set_array() {
	cout << "Enter array's values (0 is an end):" << endl;
	size_t count = 0;
	double input_var = 1.0;
	do {
		cin >> input_var;
		if (input_var != 0) {
			count++;
			if (count < size && size - count > step) { // зменшення розміру
				size = count / step * step + step;
				change_size(count);
			}
			if (count > size) { // збільшення розміру
				size += step;
				change_size(count);
			}
			ptr[count - 1] = input_var;
		}
	} while (input_var != 0);
}

void Arr::get_array() {
	cout << "Array:\t";
	for (size_t i = 0; i < size; i++) {
		cout << "[" << ptr[i] << "]";
	}
	cout << std::endl;
}

void Arr::change_size(size_t count) {
	double * temp_arr = new double[size];
	for (size_t i = 0; i < size; ++i) {
		temp_arr[i] = 0;
	}
	for (size_t i = 0; i < count; ++i) {
		temp_arr[i] = ptr[i];
	}
	delete[] ptr;
	ptr = new double[size];
	for (size_t i = 0; i < size; ++i) {
		ptr[i] = temp_arr[i];
	}
	delete[] temp_arr;
}
