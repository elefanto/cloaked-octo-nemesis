// Demonstrates typedef keyword
#include <iostream>

using namespace std;

int fib(int);
int b = 0;

int main() {
	int a = 10;

	cout << fib(a) << endl;
	cout << b << endl;
	return 0;
}

int fib(int x){
	b++;
	if (x < 3){
		return 1;
	}else{
		return fib(x-1)+fib(x-2);
	}
}
