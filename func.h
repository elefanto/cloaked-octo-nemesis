#ifndef FUNC_HPP
#define FUNC_HPP

#include <cassert>
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
class Arr {

	template<typename B> friend std::ostream& operator <<(std::ostream& out,
			const Arr<B>& v);

private:
	const static size_t step = 10;
	size_t size, capacity;
	T *ptr;

	void change_size(size_t);
	void swap(Arr<T>& lhs, Arr<T>& rhs);

public:
	Arr();
	Arr(size_t arraySize);

	template<typename B> Arr(const Arr<B>& );
	Arr(const Arr<T>& rhs);

	inline ~Arr() {
		delete[] ptr;
	}

	inline size_t get_size() const {
		return size;
	}
	inline size_t get_capacity() const {
		return capacity;
	}
	T get_element(size_t position) const;
	void push(T value);
	void insert(size_t position, T value);

	void delete_element(size_t position);
	void pop();
	void clear();

	Arr<T>& operator=(const Arr<T>& rhs);
	const Arr<T>& operator=(const Arr<T>& rhs) const;

	inline const T operator[](size_t position) const {
		assert(position < size);
		assert(ptr);
		return get_element(position);
	}

    inline  T& operator [](size_t position) {
    	return ptr[position];
    }


};

template<typename T> Arr<T>::Arr() :
	size(0), capacity(step), ptr(new T[capacity]) {
	for (size_t i = 0; i < capacity; ++i)
		ptr[i] = 0;
}

template<typename T> Arr<T>::Arr(size_t arraySize) :
	size(0), capacity(arraySize), ptr(new T[arraySize]) {
	for (size_t i = 0; i < size; ++i)
		ptr[i] = 0;
}

template<typename T> Arr<T>& Arr<T>::operator=(const Arr<T>& rhs) {
	Arr<T> temp(rhs);
	swap(temp, *this);
	return *this;
}

template<typename T> Arr<T>::Arr(const Arr<T>& rhs) :
	size(rhs.size), capacity(rhs.capacity), ptr(new T[capacity]) {
	for (size_t i = 0; i < size; ++i) {
		ptr[i] = rhs.ptr[i];
	}
}

template<typename T> void Arr<T>::push(T value) {
	if (size >= capacity) {
		capacity += step;
		change_size(capacity);
	}
	ptr[size] = value;
	++size;
}
template<typename T> void Arr<T>::pop() {
	if (size > 0) {
		ptr[size - 1] = 0;
		--size;
	}
}
template<typename T> void Arr<T>::clear() {
	for (size_t i = 0; i < size; ++i) {
		ptr[i] = 0;
	}
	size = 0;
}

template<typename T> T Arr<T>::get_element(size_t position) const {
	assert(position < size);
	return ptr[position];

}

template<typename T> void Arr<T>::insert(size_t position, T value) {
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

template<typename T> ostream& operator<<(ostream& out, const Arr<T>& v) {
	for (size_t i = 0; i < v.size; i++) {
		out << v[i];
		if (i != v.size - 1)
			out << ", ";

	}
	return out;
}
template<typename T> void Arr<T>::delete_element(size_t position) {
	assert(position < size);
	--size;
	for (size_t i = position; i < size; ++i) {
		ptr[i] = ptr[i + 1];
	}
}

template<typename T> void Arr<T>::change_size(size_t capacity) {
	T *temp_arr = new T[capacity];
	for (size_t i = 0; i < size; ++i) {
		temp_arr[i] = ptr[i];
	}
	for (size_t i = size; i < capacity; ++i) {
		temp_arr[i] = 0;
	}
	delete[] ptr;
	ptr = temp_arr;
}

template<typename T> void Arr<T>::swap(Arr<T>& lhs, Arr<T>& rhs) {
	size_t temp_size = rhs.size;
	rhs.size = lhs.size;
	lhs.size = temp_size;

	size_t temp_capacity = rhs.capacity;
	rhs.capacity = lhs.capacity;
	lhs.capacity = temp_capacity;

	T* temp_ptr = rhs.ptr;
	rhs.ptr = lhs.ptr;
	lhs.ptr = temp_ptr;
}
#endif
