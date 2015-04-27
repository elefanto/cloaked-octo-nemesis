#include <iostream>
#include <cstdlib>

#include "func.h"

using namespace std;

Arr::Arr() :
	size(0), capacity(step), ptr(new double[capacity]) {
	for (size_t i = 0; i < capacity; ++i)
		ptr[i] = 0;
}

Arr::Arr(size_t arraySize) :
	size(0), capacity(arraySize), ptr(new double[arraySize]) {
	for (size_t i = 0; i < size; ++i)
		ptr[i] = 0;
}

Arr& Arr::operator=(const Arr& rhs) {
	Arr temp(rhs);
	swap(temp, *this);
	return *this;
}

Arr::Arr(const Arr &rhs) :
	size(rhs.size), capacity(rhs.capacity), ptr(new double[capacity]) {
	for (size_t i = 0; i < size; ++i) {
		ptr[i] = rhs.ptr[i];
	}
}

void Arr::push(double value) {
	if (size >= capacity) {
		capacity += step;
		change_size(capacity);
	}
	ptr[size] = value;
	++size;
}
void Arr::pop() {
	if (size > 0) {
		ptr[size - 1] = 0;
		--size;
	}
}
void Arr::clear() {
	for (size_t i = 0; i < size; ++i) {
		ptr[i] = 0;
	}
	size = 0;
}

double Arr::get_element(size_t position) const {
	assert(position < size);
	return ptr[position];

}

void Arr::insert(size_t position, double value) {
	if (position >= size) {
		push(value);
	} else {
		if (size >= capacity) {
			capacity += step;
			change_size(capacity);
		}
		++size;
		for (size_t i = size; i > position; --i) {
			ptr[i] = ptr[i - 1];
		}
		ptr[position] = value;
	}
}

void Arr::get_array() const {
	cout << "Array:\t";
	for (size_t i = 0; i < size; ++i) {
		cout << "[" << ptr[i] << "]";
	}
	cout << std::endl;
}

void Arr::delete_element(size_t position) {
	assert(position < size);
	--size;
	for (size_t i = position; i < size; ++i) {
		ptr[i] = ptr[i + 1];
	}
}

void Arr::change_size(size_t capacity) {
	double *temp_arr = new double[capacity];
	for (size_t i = 0; i < size; ++i) {
		temp_arr[i] = ptr[i];
	}
	for (size_t i = size; i < capacity; ++i) {
		temp_arr[i] = 0;
	}
	delete[] ptr;
	ptr = temp_arr;
}

void Arr::swap(Arr& lhs, Arr& rhs) {
	size_t temp_size = rhs.size;
	rhs.size = lhs.size;
	lhs.size = temp_size;


	size_t temp_capacity = rhs.capacity;
	rhs.capacity = lhs.capacity;
	lhs.capacity = temp_capacity;

	double* temp_ptr = rhs.ptr;
	rhs.ptr = lhs.ptr;
	lhs.ptr = temp_ptr;
}
