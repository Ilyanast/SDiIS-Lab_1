#include "Fraction.h"
#include <math.h>

Fraction::Fraction(int numerator, int denominator)
{
	if (!check_for_correct_input_data(numerator, denominator)) {
		this->numerator = 0;
		this->denominator = 1;
	}
	else {
		this->numerator = numerator;
		this->denominator = denominator;
	}

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

double Fraction::to_double()
{
	return double(this->numerator) / this->denominator;
}

Fraction Fraction::operator+(Fraction& other)
{
	return sum_of_fractions(other);
}

Fraction Fraction::operator+(int other_int)
{
	Fraction other = int_to_fraction(other_int);
	return sum_of_fractions(other);

}

void Fraction::operator+=(Fraction& other)
{
	add_to_current_fraction(other);
}

void Fraction::operator+=(int other_int)
{
	Fraction other = int_to_fraction(other_int);
	add_to_current_fraction(other);
}

Fraction Fraction::sum_of_fractions(Fraction& other)
{
	to_common_denominator(other);

	Fraction result(this->numerator + other.numerator, this->denominator);
	reduce_fraction(result.numerator, result.denominator);

	return result;
}

Fraction Fraction::int_to_fraction(int number_to_translate)
{
	return Fraction(number_to_translate, 1);
}

void Fraction::add_to_current_fraction(Fraction& other)
{
	to_common_denominator(other);
	this->numerator += other.numerator;
	reduce_fraction(this->numerator, this->denominator);
}

void Fraction::reduce_fraction(int& numerator, int& denominator)
{
	int gcd = get_gcd(abs(numerator), denominator);
	if (gcd != 1) {
		numerator /= gcd;
		denominator /= gcd;
	}
	else
		return;
}

void Fraction::to_common_denominator(Fraction& other)
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

bool Fraction::check_for_correct_input_data(int& numerator, int& denominator)
{
	if (denominator == 0 || numerator == 0) {
		return false;
	}

	if (numerator > 0 && denominator < 0) {
		numerator = -numerator;
		abs(denominator);

		return true;
	}

	if (numerator < 0 && denominator < 0) {
		abs(numerator);
		abs(denominator);

		return true;
	}

	return true;
}
