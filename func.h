#ifndef VIRTUAL_CLASSES_H
#define VIRTUAL_CLASSES_H

#include <cassert>

class Base_data {
public:
	int info[3];

	Base_data();
	Base_data(int x, int y, int z);
	Base_data(const Base_data &rhs);
	virtual inline ~Base_data() {
	}

	virtual Base_data& add(const Base_data &rhs) = 0;
	virtual void add_int(int value) = 0;
	virtual void print() = 0;
};

class Vector: public Base_data {
public:

	Vector();
	Vector(int x, int y, int z);

	virtual Vector& add(const Base_data &rhs);
	virtual void add_int(int value);
	virtual void print();
	virtual inline ~Vector() {
	}
	inline int bla() {
		return 10;
	}
};

class Date: public Base_data {
public:

	Date();
	Date(int x, int y, int z);
	virtual Date& add(const Base_data &rhs);
	virtual void add_int(int value);
	virtual void print();
	virtual inline ~Date() {
	}

};

class Time: public Base_data {
public:

	Time();
	Time(int x, int y, int z);
	virtual Time& add(const Base_data &rhs);
	virtual void add_int(int value);
	virtual void print();
	virtual inline ~Time() {
	}

};
int date_to_days(const Base_data &rhs);
void days_to_date(int value, Base_data &rhs);
int time_to_seconds(const Base_data &rhs);
void seconds_to_time(int value, Base_data &rhs);
#endif

