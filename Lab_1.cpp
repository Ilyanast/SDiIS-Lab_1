#include "Fraction.h"
#include <iostream>

using namespace std;

int main() {
	Fraction our_first_fraction(3, 2), our_second_fraction(5, 6);
	cout << (our_first_fraction + our_second_fraction).get_numerator() << endl << (our_first_fraction + our_second_fraction).get_denominator() << endl;
	return 0;
}

