#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "virtual_classes.h"

using namespace std;

Base_data::Base_data() {
	info[0] = info[1] = info[2] = 0;
}

Base_data::Base_data(int x, int y, int z) {
	for (int i = 0; i < 3; ++i)
		info[i] = 0;
}

Base_data::Base_data(const Base_data &rhs) {
	for (int i = 0; i < 3; ++i)
		info[i] = rhs.info[i];
}

Vector::Vector() {
	info[0] = info[1] = info[2] = 0;
}

Vector::Vector(int x, int y, int z) {
	info[0] = x;
	info[1] = y;
	info[2] = z;
}
Vector& Vector::add(const Base_data &rhs) {
	for (int i = 0; i < 3; ++i)
		info[i] += rhs.info[i];
	return *this;
}
void Vector::add_int(int value) {
	for (int i = 0; i < 3; ++i)
		info[i] += value;
}
void Vector::print() {
	cout << "Vector:\t" << "[" << info[0] << ", " << info[1] << ", " << info[2] << "]" << endl;
}

Date::Date() {
	info[0] = info[1] = info[2] = 0;
}

Date::Date(int x, int y, int z) {
	info[0] = x;
	info[1] = y;
	info[2] = z;
}
Date& Date::add(const Base_data &rhs) {
	int rhs_days = date_to_days(rhs);
	int lhs_days = date_to_days(*this);
	days_to_date(lhs_days + rhs_days, *this);
	return *this;
}
void Date::add_int(int value) {
	int all_days = date_to_days(*this);
	days_to_date(all_days + value, *this);
}
void Date::print() {
	cout << "Date:\t" << info[0] << "\\" << setw(2) << setfill('0') << info[1] << "\\" << setw(2) << setfill('0') << info[2] << endl;
}

int date_to_days(const Base_data &rhs) {
	return 365 * rhs.info[0] + 30*rhs.info[1]+rhs.info[2];
}

void days_to_date(int value, Base_data &rhs) {
	rhs.info[0] = value / 365;
	rhs.info[1] = value % 365 / 31;
	rhs.info[2] = value % 365 % 31;
}


Time::Time() {
	info[0] = info[1] = info[2] = 0;
}

Time::Time(int x, int y, int z) {
	info[0] = x;
	info[1] = y;
	info[2] = z;
}
Time& Time::add(const Base_data &rhs) {
	int rhs_days = time_to_seconds(rhs);
	int lhs_days = time_to_seconds(*this);
	seconds_to_time(lhs_days + rhs_days, *this);
	return *this;
}
void Time::add_int(int value) {
	int all_seconds = time_to_seconds(*this);
	seconds_to_time(all_seconds + value, *this);
}
void Time::print() {
	cout << "Time:\t" << info[0] << ":" << setw(2) << setfill('0') << info[1] << ":" << setw(2) << setfill('0') << info[2] << endl;
}

int time_to_seconds(const Base_data &rhs) {
	return 3600 * rhs.info[0] + 60*rhs.info[1]+rhs.info[2];
}

void seconds_to_time(int value, Base_data &rhs) {
	rhs.info[0] = value / 3600;
	rhs.info[1] = value % 3600 / 60;
	rhs.info[2] = value % 3600 % 60;
}
