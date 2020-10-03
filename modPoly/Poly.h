#include <iostream>
#include <vector>
using std::ostream;
using std::vector;
using std::cout;
using std::endl;

// templated class for a polynomial, with coefficients of type T
// The type T is assumed to have a zero element 0
// Furthermore T is assumed to have implemented:
//   the + operator;
//   the == operator;
//   the << operator.
template<typename T>
class Polynomial {
public:

	// Default constructor. Constructs the polynomial "0"
	Polynomial() {
		//sets default vector to {0}
		poly = {0};
	}

	// Value constructor. Constructs a polynomial based on the vector
	// of coefficients, in descending order of exponents.
	// For example, if coef contains {0,6,8,9,4}, then it constructs
	// the polynomial 6x^3 + 8x^2 + 9x + 4
	Polynomial(vector<T> other) {
		int size = other.size();
		//sets up vector of correct size
		for (int i = 0; i < size; i++){
			poly.push_back(other[0]);
		}
		//copies values through
		for (int i = 0; i < size; i++){
			poly[i] = other[i];
		}
	}

	// default destructor, shallow copy constructor and copy assignment
	// should be ok

	// Return the degree of the polynomial.
	int degree() const {
		int toReturn = 0;
		//loops through the poly vector looking for empty spaces
		for(int i = poly.size() - 1; i >= 0; i--){
			if(poly[i] == 0){
			}
			else{
				//finds largest non 0 vector slot
				toReturn = poly.size() - i - 1;
			}
		}
		return toReturn;
	}

	// Return the coefficient of the x^i term. If i is negative or
	// larger than the degree, 0 is returned.
	T getCoef(int i) const {
		if(i >= poly.size() || i < 0){
			//if out of range returns 0
			return 0;
		}
		//otherwise gets the coefficent for that value
		return poly[poly.size() - i - 1];
	}

	//custom function
	void setCoef(int i, T toSet) {
		//if out of range does nothing
		if(i >= poly.size() || i < 0){
		}
		else{
			//sets the coef to one given
			poly[poly.size() - i - 1] = toSet;
		}
	}

	// Addition of two polynomials. This time it is a member function
	Polynomial operator+(const Polynomial& other) const {
		vector<T> otherPoly = other.getPoly();
		vector<T> temp;
		//finds largest vector and makes a new one of the same size
		if (poly.size() >= otherPoly.size()){
			for (int i = 0; i < poly.size(); i++){
				temp.push_back(this -> getCoef(i) + other.getCoef(i));
			}
		}
		else {
			for (int i = 0; i < otherPoly.size(); i++){
				temp.push_back(this -> getCoef(i) + other.getCoef(i));
			}
		}
		//fills new vector with correct values using set coef function
		Polynomial<T> toReturn(temp);
		for (int i = 0; i < temp.size(); i++){
			 	toReturn.setCoef(i,(this -> getCoef(i) + other.getCoef(i)));
			}
		return toReturn;
	}

	// Print the polynomial, in descending order of coefficients and
	// with the usual "x^..." terms.
	// It is not necessary to print it "pretty".
	// For example, if the polynomial is 2x^4 + x^3 - 5x - 1, it is
	// sufficient to print it as 2x^4 + 1x^3 + 0x^2 + -5x^1 + -1x^0
	// Minor formatting differences will be accepted.
	// If you print it pretty you get up to 5 bonus marks (out of 100
	// for this task). See the testPrintPretty() test case.
	// (This bonus part may not be as easy as it seems...)
	friend ostream& operator<<(ostream& os, const Polynomial<T>& p) {
		//loops through and prints all of the polys
		for (int i = p.degree(); i >= 0; i--){
			os << p.getCoef(i) << "x^" << i;
			if(i != 0){
				os << " + ";
			}
		}
		return os;
	}

	vector<T> getPoly() const{
		//returns the poly
		return poly;
	}
private:
	vector<T> poly;
};