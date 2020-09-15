#include "Fraction.h"
#include <iostream>

using namespace std;

int main() {
	Fraction our_first_fraction(-77, 5), a2(-2, 7);
	our_first_fraction *= -5;
	cout << our_first_fraction.get_numerator() << endl << our_first_fraction.get_denominator() << endl << endl << our_first_fraction.to_double();
	return 0;
}

