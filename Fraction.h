#include <iostream>
#include <ostream>

class Fraction
{
public:
	Fraction(int numerator, int denominator);
	int get_numerator();
	int get_denominator();
	int get_integer_part();
	double to_double();
	Fraction operator + (Fraction& other_fraction);
	Fraction operator + (const int other_int);
	Fraction& operator += (Fraction& other_fraction);
	Fraction& operator += (const int other_int);
	Fraction operator - (Fraction& other_fraction);
	Fraction operator - (const int other_int);
	Fraction& operator -= (Fraction& other_fraction);
	Fraction& operator -= (const int other_int);
	Fraction operator * (Fraction& other_fraction);
	Fraction operator * (const int other_int);
	Fraction& operator *= (Fraction& other_fraction);
	Fraction& operator *= (const int other_int);
	Fraction operator / (Fraction& other_fraction);
	Fraction operator / (const int other_int);
	Fraction& operator /= (Fraction& other_fraction);
	Fraction& operator /= (const int other_int);
	Fraction operator ++ (int);
	Fraction operator -- (int);
	Fraction& operator ++ ();
	Fraction& operator -- ();
	Fraction operator - ();
	bool operator == (Fraction& other_fraction);
	bool operator == (int other_int);
	bool operator > (Fraction& other_fraction);
	bool operator < (Fraction& other_fraction);
	bool operator >= (Fraction& other_fraction);
	bool operator <= (Fraction& other_fraction);
	bool operator > (int other_int);
	bool operator < (int other_int);
	bool operator >= (int other_int);
	bool operator <= (int other_int);
	friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);

private:
	Fraction division_of_fractions(Fraction& other_fraction);
	Fraction multiplication_of_fractions(Fraction& other_fraction);
	Fraction sum_of_fractions(Fraction other_fraction);
	Fraction int_to_fraction(int number_to_translate);
	void reduce_numbers(int& numerator, int& denominator);
	void to_common_denominator(Fraction& other_fraction);
	int get_gcd(int first_number, int second_number);
	int get_lcm(int first_number, int second_number);
	bool check_for_correct_input_data(int& numerator, int& denominator);

	int numerator;
	int denominator;
};