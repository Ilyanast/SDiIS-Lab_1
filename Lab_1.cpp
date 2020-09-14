#include <iostream>

using namespace std;

class Fraction
{
public:
	Fraction(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
		reduce_fraction();
	};

	int get_numerator() {
		return numerator;
	}

	int get_denominator() {
		return denominator;
	}

	int get_integer_part() {
		return numerator / denominator;
	}
	//~Fraction();

private:
	int numerator;
	int denominator;

	void reduce_fraction() {
		int gcd = get_gcd(numerator, denominator);
		if (gcd != 1) {
			numerator /= gcd;
			denominator /= gcd;
		}
		else
			return;
	}

	int get_gcd(int numerator, int denominator) {

		int gcd = 1, largest_part;

		if (numerator > denominator)
			largest_part = numerator;
		else
			largest_part = denominator;

		while (numerator > 1 && denominator > 1) {
			for (int i = 2; i <= largest_part; i++) {
				if (numerator % i == 0 && denominator % i == 0) {
					gcd *= i;
					numerator /= i;
					denominator /= i;
					break;
				}
				if (numerator % i == 0) {
					numerator /= i;
					break;
				}
				if (denominator % i == 0) {
					denominator /= i;
					break;
				}
			}
		}
		return gcd;
	}

};


int main() {
	int a, b;
	cin >> a >> b;
	Fraction our_fraction(a, b);
	cout<< endl << our_fraction.get_numerator() << endl << our_fraction.get_denominator() <<
		endl << endl << our_fraction.get_integer_part() << endl;
}