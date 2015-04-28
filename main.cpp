#include <iostream>
#include "virtual_classes.h"

using namespace std;


int main() {
	Base_data *ptr[3];

	ptr[0] = new Vector(1,2,3);
	ptr[1] = new Date(0,0,0);
	ptr[2] = new Time(1,2,3);

	for(int i=0; i<3; ++i){
		ptr[i]->print();
	}
	cout << endl;
	for(int i=0; i<3; ++i){
		ptr[i]->add_int(57);
	}
	for(int i=0; i<3; ++i){
		ptr[i]->print();
	}
	cout << endl;
	for(int i=0; i<3; ++i){
		ptr[i]->add(*ptr[i]);
	}
	for(int i=0; i<3; ++i){
		ptr[i]->print();
	}
	return 0;
}
