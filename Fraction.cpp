#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
	reduce_fraction(this->numerator, this->denominator);
}

int Fraction::get_numerator()
{
	return numerator;
}

int Fraction::get_denominator()
{
	return denominator;
}

int Fraction::get_integer_part()
{
	return numerator / denominator;
}

Fraction Fraction::operator+(Fraction& other)
{
	int lcm = get_lcm(this->denominator, other.denominator);
	if (lcm / this->denominator != 1) {
		this->numerator *= (lcm / this->denominator);
		this->denominator = lcm;
	}
	if (lcm / other.denominator != 1) {
		other.numerator *= (lcm / other.denominator);
		other.denominator = lcm;
	}

	Fraction result(this->numerator + other.numerator, lcm);
	reduce_fraction(result.numerator, result.denominator);

	return result;
}

void Fraction::reduce_fraction(int& numerator, int& denominator)
{
	int gcd = get_gcd(numerator, denominator);
	if (gcd != 1) {
		numerator /= gcd;
		denominator /= gcd;
	}
	else
		return;
}

int Fraction::get_gcd(int first_number, int second_number)
{
	while (first_number != 0 && second_number != 0) {
		if (first_number > second_number) {
			first_number = first_number % second_number;
		}
		else {
			second_number = second_number % first_number;
		}
	}

	return first_number + second_number;
}

int Fraction::get_lcm(int first_number, int second_number)
{
	return (first_number * second_number) / get_gcd(first_number, second_number);
}
