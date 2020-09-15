#include "Fraction.h"
#include <iostream>

using namespace std;

int main() {
	Fraction a(-2, 3), a2(135, 35);
	cout << (a + a2).get_numerator() << endl << (a + a2).get_denominator() << endl;
	return 0;
}

