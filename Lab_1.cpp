#include "Fraction.h"
#include <iostream>

using namespace std;

int main() {
	Fraction our_first_fraction(11, 5), our_second_fraction(7, 8);
	our_first_fraction += our_second_fraction;
	cout << our_first_fraction.get_numerator() << endl << our_first_fraction.get_denominator() << endl;
	return 0;
}

