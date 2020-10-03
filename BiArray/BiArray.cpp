#include "BiArray.h"
#include <iostream>
using namespace std;

// default constructor
BiArray::BiArray() {
	//sets the capacity 
	capacity = INITIALCAP;
	//sets the size of the array to 0
	arraySize = 0;
	//initalzies an array and gives it memory space
	startOfArray = new int[capacity]();
	//sets a pointer for the front and back elements of the array
	frontPointer = startOfArray + (capacity/2);
	backPointer = startOfArray + (capacity/2);
}

// value constructor
BiArray::BiArray(int arr[], int size) {
	//seys the size of the array
	arraySize = size;
	//sets the capacity of the array dependant on the size
	if (size * LO_THRESHOLD > INITIALCAP) {
		capacity = size * LO_THRESHOLD;
	}
	else {
		capacity = INITIALCAP;
	}
	//initalizes array to the size of the capacity
	startOfArray = new int[capacity];
	//sets a pointer for the front and back elements of the array
	frontPointer = startOfArray + (capacity / 2) - (arraySize / 2) - 1;
	backPointer = startOfArray + (capacity / 2) + (arraySize / 2) + 1;
	//fills the array from the front pointer onwards
	for (int i = 0; i < arraySize; i++) {
		*(frontPointer + i + 1) = arr[i];
	}
}

// destructor
BiArray::~BiArray() {
	//clears the memory allocation for the array
	delete[] startOfArray;
	//sets all the pointers to null
	frontPointer = nullptr;
	backPointer = nullptr;
	startOfArray = nullptr;
}

// copy constructor
BiArray::BiArray(const BiArray& other){
	//copies all elements of the 'other' array
	arraySize = other.arraySize;
	startOfArray = new int[arraySize];
	frontPointer = other.frontPointer;
	backPointer = other.backPointer;
	capacity = other.capacity;
	//fills array element by element
	for (int i = 0; i < arraySize; ++i)
	{
		*(startOfArray + i) = other[i];
	} 
}

// move constructor
BiArray::BiArray(BiArray&& other)
	://copies all elements of 'other' array
	startOfArray{other.startOfArray},
	capacity{ other.capacity },
	arraySize{ other.arraySize },
	frontPointer{other.frontPointer},
	backPointer{ other.backPointer }
{
	//sets all elements of 'other' array to 0 or null
	other.arraySize = 0;
	other.capacity = 0;
	other.frontPointer = nullptr;
	other.backPointer = nullptr;
	other.startOfArray = nullptr;
}

// copy assignment
BiArray& BiArray::operator=(const BiArray& other) {
	if (&other != this) {
		//clears memory space of this array
		delete[] startOfArray;
		//copies all the elements of 'other' array
		startOfArray = other.startOfArray;
		frontPointer = other.frontPointer;
		backPointer = other.backPointer;
		arraySize = other.arraySize;
		capacity = other.capacity;
	}
	return *this;
}

// move assignment
BiArray& BiArray::operator=(BiArray&& other) {
	if (&other != this) {
		//swaps the start of array with start of 'other' array
		int* temp = startOfArray;
		startOfArray = other.startOfArray;
		other.startOfArray = temp;
		//sets the temp to nullptr
		temp = nullptr;

		//swaps the frontPoiter of array with start of 'other' array
		int* tempFront = frontPointer;
		frontPointer = other.frontPointer;
		other.frontPointer = tempFront;
		tempFront = nullptr;

		//swaps the backPointer of array with start of 'other' array
		int* tempBack = backPointer;
		backPointer = other.backPointer;
		other.backPointer = tempBack;
		tempBack = nullptr;

		//swaps the capacity of array with start of 'other' array
		int tempCap = capacity;
		capacity = other.capacity;
		other.capacity = tempCap;
		tempCap = 0;

		//swaps the size of array with start of 'other' array
		int tempSize = arraySize;
		arraySize = other.arraySize;
		other.arraySize = tempSize;
		tempSize = 0;
	}
	return *this;
}

bool BiArray::get(int i, int& v) const {
	//checks if i is in bound
	if (i < 0) {
		return false;
	}
	else if (i > arraySize - 1){
		return false;
	}
	//if i is in bound returns v as the element pointed to
	else {
		 v = *(frontPointer + 1 + i);
		return true;
	}
}

bool BiArray::set(int i, int v) {
	//checks if i is in bound
	if (i < 0) {
		return false;
	}
	else if (i > arraySize - 1) {
		return false;
	}
	//if i is in bound sets the ith element to v
	else {
		*(frontPointer + 1 + i) = v;
		return true;
	}
}

int BiArray::operator[](int i) const {
	//returns the ith element of the array
	int* tempPointer = frontPointer;
	return *(tempPointer + i + 1);
}


int& BiArray::operator[](int i) {
	//returns the ith element of the array
	int* tempPointer = frontPointer;
	return *(tempPointer + i + 1);
}

void BiArray::push_back(int v) {
	//checks if the element will fit and calls resize 
	if (backPointer == startOfArray + capacity) {
		resizePushBack(v);
	}
	// if array is empty adds element to the back and moves pointers
	else if (arraySize == 0) {
		frontPointer = startOfArray + (capacity / 2);
		backPointer = startOfArray + (capacity / 2);
		*(backPointer) = v;
		backPointer++;
		frontPointer--;
	}
	//if array is not empty adds element and moves back pointer
	else {
		*(backPointer) = v;
		backPointer++;
	}	
	arraySize++;
}

bool BiArray::pop_back() {
	//checks size is valid
	if (arraySize <= 0) {
		return false;
	}
	//removes last element of array
	else {
		*(backPointer - 1) = 0;
		backPointer--;
		arraySize--;
		resizePop();
		return true;
	}
}

void BiArray::push_front(int v) {
	//checks if the element will fit and calls resize 
	if (frontPointer < startOfArray) {
		resizePushFront(v);
	}
	// if array is empty adds element to the back and moves pointers
	else if(arraySize == 0) {
		frontPointer = startOfArray + (capacity / 2);
		backPointer = startOfArray + (capacity / 2);
		*(frontPointer) = v;
		backPointer++;
		frontPointer--;
	}
	//if array is not empty adds element and moves front pointer
	else {
		*(frontPointer) = v;
		frontPointer--;
	}
	arraySize++;
}


bool BiArray::pop_front() {
	//checks if size is valid
	if (arraySize <= 0) {
		return false;
	}
	//removes last element of array
	else {
		*(frontPointer + 1) = 0;
		frontPointer++;
		arraySize--;
		resizePop();
		return true;
	}
}

int BiArray::getSize() const {
	//returns size
	return arraySize;
}

int BiArray::getCapacity() const {
	//returns capacity
	return capacity;
}

string BiArray::print() const {
	//initalizes string to "["
	string toPrint = "[";
	int value;
	string test;
	//fills the print in for the valid segments of the array
	for (int i = 0; i < capacity; i++) {
		if (((startOfArray + i) > frontPointer) && ((startOfArray + i) < backPointer - 1)) {
			value = *(startOfArray + i);
			test = to_string(value);
			toPrint += test;
			if ((startOfArray + i) < backPointer - 2) {
				toPrint += " ";
			}
		}
	}
	toPrint += "]";
	//returns the completed array
	return toPrint;
}

string BiArray::printAll() const {
	string toPrint = "[";
	int value;
	string test;
	for (int i = 0; i < capacity; i++) {
		if (((startOfArray + i) > frontPointer) && ((startOfArray + i) < backPointer)) {
			value = *(startOfArray + i);
			test = to_string(value);
			toPrint += test;
		}
		else {
			toPrint += "X";
		}
		if ((startOfArray + i) < startOfArray + capacity - 1) {
			toPrint += " ";
		}
	}
	toPrint += "]";
	return toPrint;
}

bool operator==(const BiArray& lhs, const BiArray& rhs) {
	//checks if size and capacity are correct
	if (lhs.getSize() != rhs.getSize()) {
		return false;
	}
	//checks if elements are matching
	else {
		for (int i = 0; i < lhs.getSize(); i++) {
			if (lhs[i] != rhs[i]){
				return false;
			}
		}
		return true;
	}
}

bool operator!=(const BiArray& lhs, const BiArray& rhs) {
	//checks arrays arent the same
	if (lhs == rhs) {
		return false;
	}
	else {
		return true;
	}
}

void BiArray::resizePushBack(int v) {
	//finds new size of array and sets up new array then swaps elements
	capacity = arraySize * LO_THRESHOLD;
	int* tempPointer = new int[capacity];
	int* tempFront = tempPointer + (capacity / 2) - (arraySize / 2) - 1;
	int* tempBack = tempPointer + (capacity / 2) + (arraySize / 2) + 1;
	for (int i = 0; i < arraySize; i++) {
		*(tempFront + i + 1) = *(frontPointer + i + 1);
	}
	if (capacity % 2 == 0) {
		backPointer = tempBack;
		*(tempFront + arraySize + 1) = v;
	}
	else {
		backPointer = tempBack + 1;
		*(tempFront + arraySize + 1) = v;
	}
	//clears all unneeded data and sets points to proper positions
	delete[] startOfArray;
	startOfArray = tempPointer;
	frontPointer = tempFront;
	tempBack = nullptr;
	tempFront = nullptr;
	tempPointer = nullptr;
}

void BiArray::resizePushFront(int v) {
	//finds new size of array and sets up new array then swaps elements
	capacity = arraySize * LO_THRESHOLD;
	int* tempPointer = new int[capacity];
	int* tempFront = tempPointer + (capacity / 2) - (arraySize / 2) - 1;
	int* tempBack = tempPointer + (capacity / 2) + (arraySize / 2) + 1;
	for (int i = 0; i < arraySize; i++) {
		*(tempFront + i + 1) = *(frontPointer + i + 1);
	}
	if (capacity % 2 == 0) {
		frontPointer = tempFront - 1;
		*(tempFront) = v;
	}
	else {
		frontPointer = tempFront - 1;
		*(tempFront) = v;
	}
	//clears all unneeded data and sets points to proper positions
	delete[] startOfArray;
	startOfArray = tempPointer;
	backPointer = tempBack;
	tempBack = nullptr;
	tempFront = nullptr;
	tempPointer = nullptr;
}
void BiArray::resizePop() {
	//checks capacity and if it needs to be resized
	if (capacity > HI_THRESHOLD * arraySize) {
		capacity = arraySize * HI_THRESHOLD;
		int* tempPointer = new int[capacity];
		int* tempFront = tempPointer + (capacity / 2) - (arraySize / 2) - 1;
		int* tempBack = tempPointer + (capacity / 2) + (arraySize / 2) + 1;
		for (int i = 0; i < arraySize; i++) {
			*(tempFront + i + 1) = *(frontPointer + i + 1);
		}
		//clears all unneeded data and sets points to proper positions
		delete[] startOfArray;
		frontPointer = tempFront;
		startOfArray = tempPointer;
		backPointer = tempBack;
		tempBack = nullptr;
		tempFront = nullptr;
		tempPointer = nullptr;
	}
}
