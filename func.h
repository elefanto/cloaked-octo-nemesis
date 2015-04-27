#ifndef FUNC_HPP
#define FUNC_HPP

#include <cassert>

class Arr {

private:
	const static size_t step = 10;
	size_t size, capacity;
	double *ptr;

	void change_size(size_t);
	void swap(Arr& lhs, Arr& rhs);

public:
	Arr();
	Arr(size_t arraySize);
	Arr(const Arr &rhs);
	inline ~Arr() {
		delete[] ptr;
	}

	inline size_t get_size() const {
		return size;
	}
	inline size_t get_capacity() const {
		return capacity;
	}
	double get_element(size_t position) const;
	void get_array() const;

	void push(double value);
	void insert(size_t position, double value);

	void delete_element(size_t position);
	void pop();
	void clear();

	Arr& operator=(const Arr& rhs);

	const Arr& operator=(const Arr& rhs);

	inline const double operator[](size_t position) const {
		assert(position < size);
		assert(ptr);
		return get_element(position);
	}

	inline double operator[](size_t position) {
		assert(position < size);
		assert(ptr);
		return get_element(position);
	}

};

#endif
