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

	reduce_numbers(this->numerator, this->denominator);
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

Fraction Fraction::operator+(Fraction& other_fraction)
{
	return sum_of_fractions(other_fraction);
}

Fraction Fraction::operator+(const int other_int)
{
	Fraction other_fraction = int_to_fraction(other_int);
	return sum_of_fractions(other_fraction);
}

Fraction & Fraction::operator+=(Fraction& other_fraction)
{
	return *this = *this + other_fraction;
}

Fraction & Fraction::operator+=(const int other_int)
{
	return *this = *this + other_int;
}

Fraction Fraction::operator-(Fraction& other_fraction)
{
	return sum_of_fractions(-other_fraction);
}

Fraction Fraction::operator-(const int other_int)
{
	Fraction other_fraction = int_to_fraction(other_int);
	return sum_of_fractions(-other_fraction);
}

Fraction & Fraction::operator-=(Fraction& other_fraction)
{
	return *this = *this - other_fraction;
}

Fraction & Fraction::operator-=(const int other_int)
{
	return *this = *this - other_int;
}

Fraction Fraction::operator*(Fraction& other_fraction)
{
	return multiplication_of_fractions(other_fraction);
}

Fraction Fraction::operator*(const int other_int)
{
	Fraction other_fraction = int_to_fraction(other_int);
	return multiplication_of_fractions(other_fraction);
}

Fraction & Fraction::operator*=(Fraction& other_fraction)
{
	return *this = *this * other_fraction;
}

Fraction & Fraction::operator*=(const int other_int)
{
	return *this = *this * other_int;
}

Fraction Fraction::operator/(Fraction& other_fraction)
{
	return division_of_fractions(other_fraction);
}

Fraction Fraction::operator/(const int other_int)
{
	Fraction other_fraction = int_to_fraction(other_int);
	return division_of_fractions(other_fraction);
}

Fraction & Fraction::operator/=(Fraction& other_fraction)
{
	return *this = *this / other_fraction;
}

Fraction & Fraction::operator/=(const int other_int)
{
	return *this = *this / other_int;
}

Fraction Fraction::operator++(int)
{
	Fraction other_fraction(1, 1), temp_fraction(this->numerator, this->denominator);
	*this += 1;
	return temp_fraction;
}

Fraction Fraction::operator--(int)
{
	Fraction other_fraction(1, 1), temp_fraction(this->numerator, this->denominator);
	*this -= 1;
	return temp_fraction;
}

Fraction & Fraction::operator++()
{
	return *this += 1;
}

Fraction & Fraction::operator--()
{
	return *this -= 1;
}

Fraction Fraction::operator-()
{
	return Fraction(-this->numerator, this->denominator);
}

bool Fraction::operator==(Fraction& other_fraction)
{
	return (this->numerator == other_fraction.numerator && this->denominator == other_fraction.denominator);
}

bool Fraction::operator==(int other_int)
{
	return false;
}

bool Fraction::operator>(Fraction& other_fraction)
{
	return this->to_double() > other_fraction.to_double();
}

bool Fraction::operator<(Fraction& other_fraction)
{
	return this->to_double() < other_fraction.to_double();
}

bool Fraction::operator>=(Fraction& other_fraction)
{
	return this->to_double() >= other_fraction.to_double();
}

bool Fraction::operator<=(Fraction& other_fraction)
{
	return this->to_double() <= other_fraction.to_double();
}

bool Fraction::operator>(int other_int)
{
	return this->to_double() > double(other_int);
}

bool Fraction::operator<(int other_int)
{
	return this->to_double() < double(other_int);
}

bool Fraction::operator>=(int other_int)
{
	return this->to_double() >= double(other_int);
}

bool Fraction::operator<=(int other_int)
{
	return this->to_double() <= double(other_int);
}

std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
{
	return out << fraction.numerator << "/" << fraction.denominator;;
}

Fraction Fraction::division_of_fractions(Fraction& other_fraction)
{
	Fraction result(this->numerator * other_fraction.denominator, this->denominator * other_fraction.numerator);
	reduce_numbers(result.numerator, result.denominator);

	return result;
}

Fraction Fraction::multiplication_of_fractions(Fraction& other_fraction)
{
	Fraction result(this->numerator * other_fraction.numerator, this->denominator * other_fraction.denominator);
	reduce_numbers(result.numerator, result.denominator);

	return result;
}

Fraction Fraction::sum_of_fractions(Fraction other_fraction)
{
	to_common_denominator(other_fraction);

	Fraction result(this->numerator + other_fraction.numerator, this->denominator);
	reduce_numbers(result.numerator, result.denominator);

	return result;
}

Fraction Fraction::int_to_fraction(const int number_to_translate)
{
	return Fraction(number_to_translate, 1);
}


void Fraction::reduce_numbers(int& numerator, int& denominator)
{
	int gcd = get_gcd(numerator, denominator);
	if (gcd != 1) {
		numerator /= gcd;
		denominator /= gcd;
	}
}

void Fraction::to_common_denominator(Fraction& other_fraction)
{
	int lcm = get_lcm(this->denominator, other_fraction.denominator);
	if (lcm / this->denominator != 1) {
		this->numerator *= (lcm / this->denominator);
		this->denominator = lcm;
	}
	if (lcm / other_fraction.denominator != 1) {
		other_fraction.numerator *= (lcm / other_fraction.denominator);
		other_fraction.denominator = lcm;
	}
}

int Fraction::get_gcd(int first_number, int second_number)
{
	first_number = abs(first_number);
	second_number = abs(second_number);

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
	first_number = abs(first_number);
	second_number = abs(second_number);

	return (first_number * second_number) / get_gcd(first_number, second_number);
}

bool Fraction::check_for_correct_input_data(int& numerator, int& denominator)
{
	if (denominator == 0 || numerator == 0) {
		return false;
	}

	if (numerator > 0 && denominator < 0) {
		numerator = -numerator;
		denominator = abs(denominator);

		return true;
	}

	if (numerator < 0 && denominator < 0) {
		numerator = abs(numerator);
		denominator = abs(denominator);

		return true;
	}

	return true;
}
