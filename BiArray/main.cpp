#include <iostream>
#include "BiArray.h"
using namespace std;

int main() {

	int arr1[10]{1,2,3,4,5,6,7,8,9};
	BiArray b1{ arr1,10 }; // value con

	BiArray a; // zero con
	cout << "Hello" << endl;
	cout << b1.print() << endl;
	b1.pop_front();
	cout << b1.print() << endl;
	b1.pop_front();
	cout << b1.print() << endl;
	b1.pop_front();
	cout << b1.print() << endl;
	b1.pop_front();
	cout << b1.print() << endl;
	b1.pop_front();
	cout << b1.print() << endl;
	b1.pop_front();
	cout << b1.print() << endl;

	/*a.push_back(1);
	a.printAll();
	a.push_back(2);
	a.printAll();
	a.push_back(3);
	a.printAll();
	a.push_back(4);
	a.printAll();
	a.push_front(5);
	a.printAll();
	a.push_front(6);
	a.printAll();
	a.push_front(7);
	a.printAll();
	a.push_front(8);
	a.printAll();
	a.push_front(9);
	a.printAll();
	a.push_front(10);
	a.printAll();
	a.push_front(11);
	a.printAll();
	a.push_front(12);
	a.printAll();*/
	/*
	
	//pop front with push back wrong
	//pop back with push front wrong
	a.pop_front();
	a.push_front(9);
	a.printAll();

	a.pop_front();
	a.push_front(10);
	a.printAll();

	a.pop_back();
	a.push_front(11);
	a.push_front(12);
	a.push_front(13);
	a.printAll();
	a.push_front(7);
	a.printAll();
	a.printAll();
	a.push_front(2);
	a.printAll();
	a.pop_back();
	a.printAll();
	a.push_front(3);
	cout << "Here";
	a.pop_back();
	a.printAll();
	a.push_front(4);
	a.printAll();
	a.push_front(5);
	a.printAll();
	a.pop_front();
	a.printAll();
	a.push_front(6);
	a.printAll();
	a.push_front(7);
	a.printAll();
	a.push_front(8);
	a.printAll();
	a.push_front(9);
	a.printAll();
	a.push_front(10);
	cout << a[3] << endl;
	cout << a.print() << endl;
	int v=-1;
	a.get(3,v);
	cout << v << endl;

	int arr[10]{10,9,8,7,6,5,1,2,3,4};
	BiArray b{arr,10}; // value con
	cout << "a==b? " << (a==b) << endl;

	BiArray bb = b; // copy con
	cout << bb.print() << endl;

	b[3] = 77;
	b.set(4,66);
	cout << b.print() << endl;
	cout << "a==b? " << (a==b) << endl;

	BiArray c;
	c = std::move(b); // move asg
	cout << c.print() << endl;

	a.pop_back();
	cout << a.print() << endl;
	a.pop_front();
	cout << a.print() << endl;
	cout << a.getSize() << endl;
	cout << a.getCapacity() << endl;
	*/
}