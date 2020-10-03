#ifndef __INTMOD_H_
#define __INTMOD_H_

#include <iostream>
#include <string>
using std::ostream;
using std::cout;
using std::endl;

// you can assume n is an integer >= 2
template<int n>
class IntMod {

public:

	// Default constructor. Should initialize value to 0
	IntMod() {
		//initalizes to 0
		modValue = 0;
	}

	// Value constructor. Accepts any (positive or negative) integer
	// not necessarily within [0..n-1]
	IntMod(int v) {
		//sets up mod values
		toMod = v;
		//gets the current 'mod' using the fact that
		//a negative mod is equivent to positive ones of
		//the same order
		int temp = makePositive(v);
		modValue = temp % n;
	}

	// default destructor, shallow copy constructor and copy assignment
	// should be ok

	// Returns the value of this IntMod as an integer, in
	// the range 0..n-1
	int toInt() const {
		//returns mod value
		return modValue;
	}

	// Overloaded + operator for adding two IntMods.
	// The two operands must be of same type i.e. same value of n in IntMod<n>
	// otherwise would not compile.
	// For technical reasons they are defined inside the class body
	// even though they are friends; see e.g. https://en.cppreference.com/w/cpp/language/friend#Template_friend_operators
	friend IntMod operator+(const IntMod& lhs, const IntMod& rhs) {
		//uses mod formula to add mod's
		return (lhs.toInt() + rhs.toInt()) % n;
	}

	// Overloaded * operator for multiplying two IntMods.
	friend IntMod operator*(const IntMod& lhs, const IntMod& rhs) {
		//uses mod formula to multiply mods
		return (lhs.toInt() * rhs.toInt()) % n;
	}

	// Overloaded == operator for comparing two IntMods.
	friend bool operator==(const IntMod& lhs, const IntMod& rhs) {
		//checks if theyre mods are the same and if so returns true
		if(lhs.toInt() == rhs.toInt()){
			return true;
		}
		else{
			return false;
		}
	}

	// Return the multiplicative inverse of the current number mod n
	// (note that this is a member function).
	// An inverse of a number x, modulo n, is a number y such that
	// x*y mod n == 1.
	// It is sufficient to simply test the above condition
	// for each number in 1,2,...,n-1. You don't need to implement any
	// "better" algorithms.
	// If the inverse does not exist, throw a std::domain_error exception.
	IntMod inverse() {
		IntMod<n> intMod;
		//uses mod formulas to search through all possible inverses
		for(int i = 0; i < n; i++){
			intMod = i;
			if((this->toInt() * intMod.toInt()) % n == 1){
				return intMod;
			}
		}
		//if one is not found throws error
		throw std::domain_error("No inverse exsists");
	}

	// Overloaded << operator, printing the IntMod like an integer
	friend ostream& operator<<(ostream& os, const IntMod& p) {
		//prints the mod value of a intMod
		std::string x = std::to_string(p.toInt());
		os << x;
		return os;
	}

private:
	int modValue;
	int toMod;

	//makes a number positive by adding 'n' to keep the mods equivilant
	int makePositive(int x){
		while(x < 0){
			x = x + n;
		}
		return x;
	}
};

#endif /* __INTMOD_H_ */
